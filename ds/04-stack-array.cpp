#include <iostream>
#include <stack>
#define log(x) std::cout << x << std::endl;
using namespace std;

class MyStack {
 private:
  int top;
  int* MyArr;
  int maxSize;

 public:
  MyStack& push(int item) {
    if (this->isOverflowed()) this->handleOverflow();

    this->top++;

    this->MyArr[this->top] = item;

    return *this;
  }

  int pop() { return this->MyArr[this->top--]; }

  // Extra start

  bool empty() { return this->top == -1; }

  int size() { return (this->top + 1); }

  bool isOverflowed() { return this->size() >= this->maxSize; }

  void printSatck() {
    for (int i = top; i >= 0; i--) cout << i << " -> " << MyArr[i] << endl;
  }

  void handleOverflow() {
    this->maxSize *= 2;
    int* newArr = new int[this->maxSize];

    for (int i = 0; i < this->size(); i++) newArr[i] = this->MyArr[i];

    delete[] this->MyArr;
    this->MyArr = newArr;
  }

  // Extra end

  MyStack(int arrSize = 100) {
    this->maxSize = arrSize;

    this->top = -1;

    MyArr = new int[this->maxSize];
  };

  ~MyStack() { delete[] this->MyArr; };
};

int main(int argc, char const* argv[]) {
  MyStack myMyStack(2);

  myMyStack.push(3).push(4).push(5);

  myMyStack.printSatck();

  while (!myMyStack.empty()) log(myMyStack.pop());

  return 0;
}
