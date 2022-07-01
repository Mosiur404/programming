#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

class MyStack {
public:
  queue<int> Q1, Q2;
  MyStack() {}
  // push 1 Q1 = {  }
  // push 2 Q2 = { 1 }
  void push(int x) {
    this->Q2.push(x);
    while (!this->Q1.empty()) {
      this->Q2.push(this->Q1.front());
      this->Q1.pop();
    }
    swap(this->Q1, this->Q2);
  }

  int pop() {
    int temp = this->top();
    this->Q1.pop();
    return temp;
  }

  int top() { return this->Q1.front(); }

  bool empty() { return this->Q1.empty(); }
};

int main(int argc, char const *argv[]) {

  MyStack *obj = new MyStack();
  obj->push(1);
  obj->push(2);
  int top = obj->top();
  int pop = obj->pop();
  bool empty = obj->empty();
  cout << "top: " << top << " pop: " << top << " empty: " << empty << endl;

  return 0;
}
