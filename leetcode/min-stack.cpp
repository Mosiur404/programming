#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
  int val;
  int min;
  struct Node *next;
  Node() : val(0), min(0), next(nullptr) {}
  Node(int x) : val(x), min(0), next(nullptr) {}
  Node(int x, int y) : val(x), min(y), next(nullptr) {}
  Node(int x, int y, struct Node *z) : val(x), min(y), next(z) {}
};
class MinStack {
private:
  Node *headPtr;

public:
  MinStack() { this->headPtr = nullptr; }
  void push(int val) {
    struct Node *current = this->headPtr;
    int minimum = current == nullptr ? val : min(val, current->min);
    this->headPtr = new Node(val, minimum, current);
  }
  void pop() {
    struct Node *current = this->headPtr;
    this->headPtr = current->next;
    delete current;
  }
  int top() { return this->headPtr->val; }
  int getMin() { return this->headPtr->min; }
};

int main(int argc, char const *argv[]) {
  MinStack *minStack = new MinStack();
  minStack->push(-2);
  minStack->push(0);
  minStack->push(-1);
  cout << "param_3 " << minStack->getMin() << endl; // return -2
  cout << "param_3 " << minStack->top() << endl;    // return -1
  minStack->pop();
  cout << "param_3 " << minStack->getMin() << endl; // return -2

  return 0;
}
