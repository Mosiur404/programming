#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// enter 1, enter 2 out 1, out 2
class MyQueue {
public:
  stack<int> s1, s2;
  MyQueue() {}
  void push(int x) {
    while (!this->s1.empty()) {
      this->s2.push(this->s1.top());
      this->s1.pop();
    }
    this->s2.push(x);
    while (!this->s2.empty()) {
      this->s1.push(this->s2.top());
      this->s2.pop();
    }
  }
  int pop() {
    int temp = this->peek();
    this->s1.pop();
    return temp;
  }
  int peek() { return this->s1.top(); }
  bool empty() { return this->s1.empty(); }
};
int main(int argc, char const *argv[]) {
  MyQueue *myQueue = new MyQueue();
  myQueue->push(1); // queue is: [1]
  myQueue->push(2); // queue is: [1, 2] (leftmost is front of the queue)
  myQueue->push(3);
  myQueue->push(4);
  cout << myQueue->pop() << endl;
  myQueue->push(5);
  cout << myQueue->pop() << endl;
  cout << myQueue->pop() << endl;
  cout << myQueue->pop() << endl;
  cout << myQueue->pop() << endl;
  myQueue->empty();
}
