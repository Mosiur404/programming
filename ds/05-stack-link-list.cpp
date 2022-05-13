#include <iostream>
#define log(x) std::cout << x << std::endl;
using namespace std;

struct Node {
  int data;
  Node* next;
};

class Stack {
 private:
  Node* HeadPtr = new Node();

 public:
  Stack& push(int item) {
    Node* myNode = new Node();
    myNode->data = item;

    Node* startNode = this->top();

    this->HeadPtr->next = myNode;

    myNode->next = startNode;

    return *this;
  }

  int pop() {
    if (this->top() == nullptr) return 0;
    Node* startNode = this->top();
    this->HeadPtr->next = startNode->next;

    int result = startNode->data;
    delete startNode;

    return result;
  }

  // Extra start

  bool empty() { return this->HeadPtr->next == nullptr; }

  int size() {
    Node* current = this->HeadPtr->next;
    int i = 0;
    while (current->next != nullptr) {
      i++;
      current = current->next;
    }
    return i;
  }

  Node* top() { return this->HeadPtr->next; }

  void printSatck() {
    string output = "";
    Node* current = this->HeadPtr->next;
    while (current != nullptr) {
      output += to_string(current->data) + '\n';
      current = current->next;
    }
    log(output);
  }

  void printSatckWithRecursion(Node* current, int i = 0) {
    if (current == nullptr) return;

    cout << i << " -> " << current->data << endl;
    this->printSatckWithRecursion(current->next, i + 1);
  }

  // Extra end

  Stack(void) { this->HeadPtr->next = nullptr; };

  ~Stack() { delete this->HeadPtr; };
};

int main(int argc, char const* argv[]) {
  Stack myStack;
  myStack.push(3).push(4).push(5);

  myStack.printSatck();
  myStack.printSatckWithRecursion(myStack.top());
  // while (!myStack.empty())
  log(myStack.pop());
  return 0;
}
