#include <iostream>
#define log(x) std::cout << x << std::endl;
using namespace std;

struct Node {
  int data;
  Node* prev;
  Node* next;
};

class LinkedList {
 private:
  Node* HeadNode = new Node();

 public:
  LinkedList& shift(int item) {
    Node* myNewNode = new Node();
    myNewNode->data = item;
    if (isLinkedListEmpty())
      this->HeadNode->next = myNewNode;
    else {
      Node* current = this->HeadNode->next;
      this->HeadNode->next = myNewNode;
      myNewNode->next = current;
      current->prev = myNewNode;
    }

    return *this;
  }

  // Extra start

  bool isLinkedListEmpty() { return this->HeadNode->next == nullptr; }

  void printLinkedList(void) {
    Node* current = this->HeadNode->next;
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }

  void printInReverse() {
    Node* current = this->getFirstNode();

    if (current == nullptr) return;

    while (current->next != nullptr) current = current->next;

    while (current != nullptr) {
      cout << current->data << " ";
      current = current->prev;
    }

    cout << endl;
  }

  void printWithRecursion(Node* current) {
    if (current == nullptr) return;
    cout << current->data << " ";
    this->printInReverseWithRecursion(current->next);
  }

  void printInReverseWithRecursion(Node* current) {
    if (current == nullptr) return;
    this->printInReverseWithRecursion(current->next);
    cout << current->data << " ";
  }

  Node* getFirstNode() { return this->HeadNode->next; }

  // Extra end

  LinkedList() { this->HeadNode->next = nullptr; };
  ~LinkedList(){};
};

int main(int argc, char const* argv[]) {
  LinkedList mylist;

  mylist.shift(7).shift(6).shift(5).shift(4).shift(3);

  mylist.printLinkedList();

  mylist.printInReverse();

  mylist.printWithRecursion(mylist.getFirstNode());
  log("");

  mylist.printInReverseWithRecursion(mylist.getFirstNode());
  log("");

  log("Exited Successfully.");

  return 0;
}
