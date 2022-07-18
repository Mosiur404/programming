#include <iostream>
using namespace std;

struct Node {
  int val;
  int priority;
  Node *next;
  Node() : val(0), priority(0), next(nullptr) {}
  Node(int x) : val(x), priority(0), next(nullptr) {}
  Node(int x, int y) : val(x), priority(y), next(nullptr) {}
  Node(int x, int y, Node *next) : val(x), priority(y), next(next) {}
};

class Queue {
private:
  Node *head;
  Node *tail;

public:
  Queue *enqueue(int item, int priority = 0) {
    Node *newNode = new Node(item, priority);
    if (this->head == nullptr && this->tail == nullptr)
      this->head = this->tail = newNode;
    else {
      this->tail->next = newNode;
      this->tail = newNode; // tail points to last node
    }
    return this;
  }
  Queue *dequeue() {
    Node *item = this->head;
    this->head = this->head->next;
    delete item;
    return this;
  }
  Node *peek() { return this->head; }
  bool empty() { return this->head == nullptr; }
  Queue() : head(nullptr), tail(nullptr) {}
  ~Queue() {}
};

int main(int argc, char const *argv[]) {
  Queue *q = new Queue();
  q->enqueue(1)->enqueue(2)->enqueue(3)->enqueue(4);

  while (!q->empty()) {
    cout << q->peek()->val << ' ';
    q->dequeue();
  }

  return 0;
}
