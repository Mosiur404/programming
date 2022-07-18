#include <iostream>
#define log(x) std::cout << x << std::endl;
using namespace std;

struct HeapNode {
  char val;
  int priority;
  HeapNode *left, *right, *parent;
  HeapNode()
      : val('A'), priority(0), left(nullptr), right(nullptr), parent(nullptr) {}
  HeapNode(char a)
      : val(a), priority(0), left(nullptr), right(nullptr), parent(nullptr) {}
  HeapNode(char a, int b)
      : val(a), priority(b), left(nullptr), right(nullptr), parent(nullptr) {}
  HeapNode(char a, int b, HeapNode *c)
      : val(a), priority(b), left(c), right(nullptr), parent(nullptr) {}
  HeapNode(char a, int b, HeapNode *c, HeapNode *d)
      : val(a), priority(b), left(c), right(d), parent(nullptr) {}
  HeapNode(char a, int b, HeapNode *c, HeapNode *d, HeapNode *e)
      : val(a), priority(b), left(c), right(d), parent(e) {}
};

class MyHeap {
private:
  HeapNode *head;
  HeapNode *tail;

public:
  MyHeap *enqueue(char val, int priority) {
    HeapNode *newNode = new HeapNode(val, priority);
    // first case
    if (head == nullptr && tail == nullptr) {
      head = tail = newNode;
      return this;
    }
    // other cases
    heapify(newNode);

    return this;
  }
  void heapify(HeapNode *newNode) {
    HeapNode *current = this->head;
    while (current == nullptr) {
      if (current->left == nullptr) {
        current->left = newNode;
        newNode->parent = current;
      }
      current = current->left;
    }
  }
  MyHeap *dequeue() {}
  char peek() {}
  bool empty() {}
  MyHeap() : head(nullptr), tail(nullptr) {}
  ~MyHeap() {}
};

int main(int argc, char const *argv[]) {
  MyHeap *heap = new MyHeap();
  heap->enqueue('A', 18)
      ->enqueue('B', 10)
      ->enqueue('C', 25)
      ->enqueue('D', 40)
      ->enqueue('E', 12)
      ->enqueue('F', 15)
      ->enqueue('G', 20)
      ->enqueue('H', 10);

  return 0;
}
