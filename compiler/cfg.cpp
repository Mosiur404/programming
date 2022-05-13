#include <iostream>
using namespace std;

class CFG1 {
 private:
  string state = "state_0", finalState = "state_1", dummyState = "state_2",
         language = "";
  bool output;
  void setStateToDummy() { this->state = this->dummyState; }
  void state_0(char character) {
    switch (character) {
      case '\0':
        this->state = "state_1";
        break;
      case 'a':
        this->state = "state_1";
        break;
      default:
        this->setStateToDummy();
        break;
    }
  }
  void state_1(char character) {
    switch (character) {
      case 'a':
        this->state = "state_1";
        break;
      default:
        this->setStateToDummy();
        break;
    }
  }

 public:
  CFG1(string language) { this->language = language; }
  CFG1 &init() {
    int currentlyReading = 0, totalChar = this->language.length();
    do {
      if (this->state == "state_0")
        this->state_0(this->language[currentlyReading]);
      else if (this->state == "state_1")
        this->state_1(this->language[currentlyReading]);
      else if (this->state == this->dummyState)
        break;

      currentlyReading++;
    } while (currentlyReading < totalChar);
    this->output = this->state == this->finalState;
    return *this;
  }
  void print() {
    cout << "For Grammar a* '" << this->language << "' is ";
    cout << (this->output ? "Accpeted" : "Rejected");
  }
};
class CFG2 {
 private:
  string state = "state_0", finalState = "state_2", dummyState = "state_3",
         language = "";
  bool output;
  void setStateToDummy() { this->state = this->dummyState; }
  void state_0(char character) {
    switch (character) {
      case '\0':
        state = "state_1";
        break;
      case 'a':
        state = "state_1";
        break;
      case 'b':
        state = "state_1";
        break;
      default:
        this->setStateToDummy();
        break;
    }
  }
  void state_1(char character) {
    switch (character) {
      case 'a':
        state = "state_1";
        break;
      case 'b':
        state = "state_2";
        break;
      default:
        this->setStateToDummy();
        break;
    }
  }
  void state_2(char character) {
    switch (character) {
      case 'b':
        state = "state_2";
        break;
      default:
        this->setStateToDummy();
        break;
    }
  }

 public:
  CFG2(string language) { this->language = language; }
  CFG2 &init() {
    int currentlyReading = 0, totalChar = this->language.length();
    do {
      if (this->state == "state_0")
        this->state_0(this->language[currentlyReading]);
      else if (state == "state_1")
        this->state_1(this->language[currentlyReading]);
      else if (state == "state_2")
        this->state_2(this->language[currentlyReading]);
      else if (this->state == this->dummyState)
        break;
      currentlyReading++;
    } while (currentlyReading < totalChar);
    this->output = this->state == this->finalState;
    return *this;
  }
  void print() {
    cout << "For Grammar a*b+ '" << this->language << "' is ";
    cout << (this->output ? "Accpeted" : "Rejected");
  }
};

class CFG3 {
 private:
  string state = "state_0", finalState = "state_3", dummyState = "state_4",
         language = "";
  bool output;
  void setStateToDummy() { this->state = this->dummyState; }
  void state_0(char character) {
    switch (character) {
      case 'a':
        state = "state_1";
        break;
      default:
        this->setStateToDummy();
        break;
    }
  }
  void state_1(char character) {
    switch (character) {
      case 'b':
        state = "state_2";
        break;
      default:
        this->setStateToDummy();
        break;
    }
  }
  void state_2(char character) {
    switch (character) {
      case 'b':
        state = "state_3";
        break;
      default:
        this->setStateToDummy();
        break;
    }
  }
  void state_3(char character) { this->setStateToDummy(); }

 public:
  CFG3(string language) { this->language = language; }
  CFG3 &init() {
    int currentlyReading = 0, totalChar = this->language.length();
    do {
      if (this->state == "state_0")
        this->state_0(this->language[currentlyReading]);
      else if (state == "state_1")
        this->state_1(this->language[currentlyReading]);
      else if (state == "state_2")
        this->state_2(this->language[currentlyReading]);
      else if (state == "state_3")
        this->state_3(this->language[currentlyReading]);
      else if (this->state == this->dummyState)
        break;

      currentlyReading++;
    } while (currentlyReading < totalChar);
    this->output = this->state == this->finalState;
    return *this;
  }
  void print() {
    cout << "For Grammar abb '" << this->language << "' is ";
    cout << (this->output ? "Accpeted" : "Rejected");
  }
};
int main() {
  cout << "\nInput: ";
  string input;
  getline(cin, input, '\n');
  cout << '\n';
  CFG1(input).init().print();
  cout << '\n';
  CFG2(input).init().print();
  cout << '\n';
  CFG3(input).init().print();
  cout << '\n';
}