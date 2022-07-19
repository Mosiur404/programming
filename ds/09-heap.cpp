#include <iostream>
#include <vector>
#include <cmath>
#define log(x) std::cout << x << std::endl;
using namespace std;

class MyHeap {
private:
  vector<int> q;
  void heapify_up() {
    int currentIndex = q.size() - 1;
    int parentIndex = currentIndex;
    bool flag = false;

    while (parentIndex != 0) {
      parentIndex = this->getParentIndex(parentIndex);
      if (q.at(currentIndex) > q.at(parentIndex)) {
        swap(q[currentIndex], q[parentIndex]);
        currentIndex = parentIndex;
      }
    }
  }

  void heapify_down() {
    int lastIndex = q.size() - 1;
    int currentIndex = 0;
    while (true) {
      int leftIndex = 2 * currentIndex + 1;
      int rightIndex = 2 * currentIndex + 2;
      int largestIndex = currentIndex;

      if (leftIndex <= lastIndex && q[leftIndex] > q[largestIndex])
        largestIndex = leftIndex;

      else if (rightIndex <= lastIndex && q[rightIndex] > q[largestIndex])
        largestIndex = rightIndex;

      else if (largestIndex == currentIndex)
        break;

      swap(q[largestIndex], q[currentIndex]);
      currentIndex = largestIndex;
    }
  }
  // extra
  int getParentIndex(int currentIndex) { return (currentIndex - 1) / 2; }

public:
  MyHeap *enqueue(int val) {
    q.push_back(val);

    if (q.size() > 1) this->heapify_up();

    return this;
  }

  MyHeap *dequeue() {
    int lastIndex = q.size() - 1;
    q.front() = q[lastIndex]; // move last to first
    q.pop_back();             // remove last
    this->heapify_down();
    return this;
  }

  int peek() { return this->q.front(); }
  bool empty() { return this->q.size() == 0; }

  void print() {
    for (int item : this->q)
      cout << item << ' ';
    cout << endl;
  }
  MyHeap() {}
  ~MyHeap() {}
};

int main(int argc, char const *argv[]) {
  MyHeap *heap = new MyHeap();
  heap->enqueue(18)
      ->enqueue(10)
      ->enqueue(25)
      ->enqueue(40)
      ->enqueue(12)
      ->enqueue(15)
      ->enqueue(20);
  // heap->enqueue(10)->enqueue(20)->enqueue(15)->enqueue(30)->enqueue(40);
  heap->print();

  while (!heap->empty()) {
    cout << heap->peek() << ' ';
    heap->dequeue();
  }
  cout << endl;

  return 0;
}
