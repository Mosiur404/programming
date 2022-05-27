#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

const unsigned int SCR_WIDTH = 640;
const unsigned int SCR_HEIGHT = 480;

class Bresenham {
 private:
  int x1;
  int y1;
  int x2;
  int y2;
  int dx;
  int dy;
  int d;

 public:
  void startDrawing() {
    int i = 0;
    while (i < 50) {
      this->drawPixel(this->x1, this->y1);

      if (this->d < 0) {
        this->d += 2 * dy;
        this->x1 = this->x1 + 1;
      } else {
        this->d += (2 * this->dy) - (2 * this->dx);
        this->x1 = this->x1 + 1;
        this->y1 = this->y1 + 1;
      }
      i++;
    }
  }

  int delEast() { return 2 * this->dy; }
  int delNorthEast() { return 2 * (this->dy - this->dx); }

  void drawPixel(int x, int y) {
    std::cout << this->xToCoordinates(x) << " " << this->yToCoordinates(y)
              << std::endl;

    return;
    glBegin(GL_POINTS);
    glPointSize(10);
    glVertex2i(this->xToCoordinates(x), this->yToCoordinates(y));
    glEnd();
  }

  float xToCoordinates(float pixel) { return (2.0 * pixel / SCR_WIDTH) - 1.0; }
  float yToCoordinates(float pixel) { return (2.0 * pixel / SCR_HEIGHT) - 1.0; }

  Bresenham(int x1, int y1, int x2, int y2) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->dx = this->x2 - this->x2;
    this->dy = this->y2 - this->y1;
    this->d = 2 * this->dy - this->dx;
  };
  ~Bresenham(){};
};

float xToC(float pixel) { return (2.0 * pixel / SCR_WIDTH) - 1.0; }
float yToC(float pixel) { return (2.0 * pixel / SCR_HEIGHT) - 1.0; }

struct ShaderSource {
  std::string VertexSource;
  std::string FragmentSource;
};
static ShaderSource ParseShader(const std::string& filepath) {
  std::ifstream stream(filepath);
  enum ShaderType { NONE = -1, VERTEX = 0, FRAGMENT = 1 };

  std::string line;
  std::stringstream ss[2];
  ShaderType type = ShaderType::NONE;

  while (getline(stream, line)) {
    if (line.find("#shader") != std::string::npos) {
      if (line.find("vertex") != std::string::npos)
        type = ShaderType::VERTEX;
      else if (line.find("fragment") != std::string::npos)
        type = ShaderType::FRAGMENT;

    } else
      ss[(int)type] << line << '\n';
  }
  return {ss[0].str(), ss[1].str()};
}

static unsigned int CompileShader(unsigned int type,
                                  const std::string& source) {
  unsigned int id = glCreateShader(type);
  const char* src = source.c_str();
  glShaderSource(id, 1, &src, nullptr);
  glCompileShader(id);

  int result;
  glGetShaderiv(id, GL_COMPILE_STATUS, &result);

  if (result != GL_FALSE) return id;

  int length;
  glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
  char message[length];
  glGetShaderInfoLog(id, length, &length, message);
  std::cout << "Failed to compile shader!";
  std::cout << (type == GL_VERTEX_SHADER ? "(VERTEX)" : "(FRAGMENT)")
            << std::endl;
  std::cout << message << std::endl;
  glDeleteShader(id);
  return 0;
}
static unsigned int CreateShader(const std::string& vertexShader,
                                 const std::string& fragmentShader) {
  unsigned int program = glCreateProgram();
  unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
  unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);

  // glDetachShader(program,vs);
  // glDetachShader(program,fs);

  glValidateProgram(program);

  glDeleteShader(vs);
  glDeleteShader(fs);
  return program;
}

int main(int argc, char const* argv[]) {
  // Bresenham myLine(1, 1, 400, 400);
  // myLine.startDrawing();
  // return 0;

  GLFWwindow* window;

  /* Initialize the library */
  if (!glfwInit()) return -1;

  /* Create a windowed mode window and its OpenGL context */
  window =
      glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Computer Graphics", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);
  /* Initialize GLEW */
  GLenum err = glewInit();
  if (GLEW_OK != err) std::cout << "Error" << std::endl;

  std::cout << glGetString(GL_VERSION) << std::endl;

  // buffer data
  // float positions[6] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};
  float positions[6] = {xToC(20), yToC(20),  xToC(600),
                        yToC(20), xToC(290), yToC(420)};
  // make buffer
  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

  // init shader
  ShaderSource source = ParseShader("src/Basic.shader");
  unsigned int shader =
      CreateShader(source.VertexSource, source.FragmentSource);
  glUseProgram(shader);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    /* Render here */

    // start
    // {
    //   glBegin(GL_LINES);
    //   glVertex2f(0.0f, -1.0f);
    //   glVertex2f(0.0f, 1.0f);
    //   glVertex2f(-1.0f, 0.0f);
    //   glVertex2f(1.0f, 0.0f);
    //   glEnd();
    // }

    glDrawArrays(GL_TRIANGLES, 0, 3);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }
  glDeleteProgram(shader);
  glfwTerminate();
  return 0;
}