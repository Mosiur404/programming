#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
struct Color {
  float r, g, b;
};

void Init() {
  glClearColor(1.0, 1.0, 1.0, 0);
  glColor3f(0.0, 0.0, 0.0);
  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 640, 0, 480);
}
void draw_pixel(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

struct Color getPixelColor(int x, int y) {
  struct Color color;
  glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
  return color;
}

void setPixelColor(int x, int y, struct Color color) {
  glBegin(GL_POINTS);
  glColor3f(1.0, 1.0, 1.0);
  glVertex2i(x, y);
  glEnd();
  // glFlush();
}
void flood(int x, int y, struct Color old_col, struct Color new_col) {
  struct Color color;
  color = getPixelColor(x, y);

  printf("%f %f %f\n", color.r, color.g, color.b);

  // check current pixel is old_color or not
  if (color.r == new_col.r && color.g == new_col.g && color.b == new_col.b)
    return;
  if (color.r == old_col.r && color.g == old_col.g && color.b == old_col.b) {
    printf("gettting d \n");
    // put new pixel with new color
    glBegin(GL_POINTS);
    glColor3f(0, 0, 0);
    glVertex2i(x, y);
    glEnd();
    glFlush();

    // recursive call for bottom pixel fill
    flood(x + 1, y, old_col, new_col);

    // // recursive call for top pixel fill
    flood(x - 1, y, old_col, new_col);

    // // recursive call for right pixel fill
    flood(x, y + 1, old_col, new_col);

    // // recursive call for left pixel fill
    flood(x, y - 1, old_col, new_col);
    return;
  }

  return;
}

void draw_line(int x1, int x2, int y1, int y2) {
  int dx, dy, i, e;
  int incx, incy, inc1, inc2;
  int x, y;

  dx = x2 - x1;
  dy = y2 - y1;

  if (dx < 0) dx = -dx;
  if (dy < 0) dy = -dy;
  incx = 1;
  if (x2 < x1) incx = -1;
  incy = 1;
  if (y2 < y1) incy = -1;
  x = x1;
  y = y1;
  if (dx > dy) {
    draw_pixel(x, y);
    e = 2 * dy - dx;
    inc1 = 2 * (dy - dx);
    inc2 = 2 * dy;
    for (i = 0; i < dx; i++) {
      if (e >= 0) {
        y += incy;
        e += inc1;
      } else
        e += inc2;
      x += incx;
      draw_pixel(x, y);
    }

  } else {
    draw_pixel(x, y);
    e = 2 * dx - dy;
    inc1 = 2 * (dx - dy);
    inc2 = 2 * dx;
    for (i = 0; i < dy; i++) {
      if (e >= 0) {
        x += incx;
        e += inc1;
      } else
        e += inc2;
      y += incy;
      draw_pixel(x, y);
    }
  }
}

void createrectangle(void) {
  // to clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);
  // creating a rectangle
  draw_line(100, 400, 400, 400);
  draw_line(100, 100, 400, 100);
  draw_line(100, 400, 100, 100);
  draw_line(400, 400, 400, 100);

  // this is the colour of the filler  and old color of the object
  struct Color old_col = {1.0, 1.0, 1.0};
  struct Color new_col = {0.0, 0.0, 0.0};
  flood(250, 250, old_col, new_col);
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Flood fill");
  glutDisplayFunc(createrectangle);
  Init();
  glutMainLoop();
}