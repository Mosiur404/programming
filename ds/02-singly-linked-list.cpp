#include <iostream>
#define log(x) std::cout << x << std::endl;
using namespace std;

struct Node {
  int data;
  Node* next;
};

class LinkedList {
 private:
  int item, location;
  Node* HeadNode = new Node();

 public:
  LinkedList& push(void) {
    if (this->empty()) return this->shift();

    Node* myNode = new Node();
    myNode->data = this->item;
    myNode->next = nullptr;
    this->getLastNode()->next = myNode;

    return *this;
  }

  int pop(void) {
    if (this->empty()) return handleEmptyList();

    Node* oneBeforeLast = getOneIndexBeforeLastNode();
    Node* lastNode = oneBeforeLast->next;
    oneBeforeLast->next = nullptr;

    int result = lastNode->data;
    delete lastNode;
    return result;
  }

  LinkedList& shift(void) {
    Node* myNode = new Node();
    myNode->data = this->item;

    if (this->empty())
      this->HeadNode->next = myNode;
    else {
      Node* temp = this->HeadNode->next;
      this->HeadNode->next = myNode;
      myNode->next = temp;
    }

    return *this;
  }

  int unshift(void) {
    if (this->empty()) return handleEmptyList();

    Node* firstNode = this->HeadNode->next;
    if (firstNode->next == nullptr)
      this->HeadNode->next = nullptr;
    else
      this->HeadNode->next = firstNode->next;
    return firstNode->data;
  }

  LinkedList& insert() {
    if (this->location == 1) return this->shift();

    Node* myNode = new Node();
    myNode->data = item;

    Node* prevNode = this->getNthNode(this->location - 1);
    // that position does not exist
    if (prevNode == nullptr) {
      log("Location not found.");
      return *this;
    }
    Node* currentNode = prevNode->next;
    prevNode->next = myNode;
    myNode->next = currentNode;

    return *this;
  }

  int replace() {
    if (this->empty()) return handleEmptyList();

    Node* currentNode = this->getNthNode(this->location);
    // that position does not exist
    if (currentNode == nullptr) {
      log("Location not found.");
      return 0;
    }
    int originalValue = currentNode->data;
    currentNode->data = this->item;

    return originalValue;
  }

  int deleteNode() {
    if (this->empty()) return handleEmptyList();

    Node* prevNode = this->getNthNode(this->location - 1);
    Node* currentNode = prevNode->next;

    if (currentNode->next == nullptr)
      // if there nothing after current node
      prevNode->next = nullptr;
    else
      // if there is a node after current node then link it
      prevNode->next = currentNode->next;

    int result = currentNode->data;
    delete currentNode;
    return result;
  }

  LinkedList& reverse(void) {
    if (this->empty()) {
      handleEmptyList();
      return *this;
    }
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* current = this->HeadNode->next;

    while (current != nullptr) {
      next = current->next;

      // here prev node is the current node saved in previous iteration
      // now current node points to prev node <- (reverse)
      current->next = prev;
      // sending it for next iteration
      prev = current;

      current = next;
    }
    this->HeadNode->next = prev;

    return *this;
  }

  void reverseWithRecursion(Node* current) {
    if (current->next == nullptr) {
      // if it is the last one then head node points to it.
      this->HeadNode->next = current;
      return;
    }

    this->reverseWithRecursion(current->next);

    Node* next = current->next;
    // reversing the link <--
    next->next = current;
    // so that the last one points to null
    current->next = nullptr;
  }

  // extra start

  bool empty() { return this->HeadNode->next == nullptr; }

  Node* getHeadNode() { return this->HeadNode; }

  Node* getFirstNode() { return this->HeadNode->next; }

  Node* getNthNode(int n) {
    if (n <= 0) return nullptr;

    Node* current = this->HeadNode->next;
    int i = 1;
    while (current != nullptr) {
      if (n == i) return current;
      current = current->next;
      i++;
    }
    return nullptr;
  }

  Node* getLastNode() {
    Node* currentNode = this->HeadNode->next;
    while (currentNode->next != nullptr) currentNode = currentNode->next;

    return currentNode;
  }

  Node* getOneIndexBeforeLastNode() {
    Node* currentNode = this->HeadNode;
    Node* prev = nullptr;
    while (currentNode->next != nullptr) {
      prev = currentNode;
      currentNode = currentNode->next;
    }
    return prev;
  }

  void printLinkedList(void) {
    if (this->empty()) {
      log("Linked List is empty.");
      return;
    }
    Node* current = this->HeadNode->next;
    string output = "Linked List: ";
    while (current != nullptr) {
      output += to_string(current->data) + " ";
      current = current->next;
    }
    log(output);
  }

  void printWithRecursion(struct Node* ptr) {
    if (ptr == nullptr) return;

    cout << (ptr->data) << " ";

    this->printWithRecursion(ptr->next);
  }

  void printInReverseWithRecursion(struct Node* ptr) {
    if (ptr == nullptr) return;

    this->printInReverseWithRecursion(ptr->next);

    cout << (ptr->data) << " ";
  }

  int handleEmptyList() {
    log("Linked List is empty.");
    return 0;
  }

  bool reset() {
    while (!this->empty()) this->pop();
    return true;
  }

  LinkedList& setItem() {
    cout << "Insert Item: ";
    cin >> this->item;
    return *this;
  }
  LinkedList& setLocation() {
    cout << "Insert Location: ";
    cin >> this->location;
    return *this;
  }

  // extra end

  LinkedList() { this->HeadNode->next = nullptr; };
  ~LinkedList(){};
};

// https://www.youtube.com/watch?v=B31LgI4Y4DQ&list=WL&index=18
// https://miro.medium.com/max/1200/0*0XVK02Guco9xJMJL.png
int main(int argc, char const* argv[]) {
  LinkedList mylist;

  int command;

  while (true) {
    cout << "\n\nChoose option: ";
    cout << "\n 0) Exit";
    cout << "\n 1) Push";
    cout << "\n 2) Pop";
    cout << "\n 3) Shift";
    cout << "\n 4) Unshift";
    cout << "\n 5) Insert";
    cout << "\n 6) Replace";
    cout << "\n 7) Delete";
    cout << "\n 8) Reverse";
    cout << "\n 9) Reverse with recursion";
    cout << "\n10) Print";
    cout << "\n11) Print with recursion";
    cout << "\n11) Print with recursion";
    cout << "\n12) Print in reverse with recursion";
    cout << "\n13) Reset";
    cout << endl;

    cout << "Command: ";
    cin >> command;

    if (command == 0) {
      log("\nExited Successfully.");
      break;
    };

    switch (command) {
      case 1:
        mylist.setItem().push();
        break;

      case 2:
        mylist.pop();
        break;

      case 3:
        mylist.setItem().shift();
        break;
      case 4:
        mylist.unshift();
        break;

      case 5:
        mylist.setItem().setLocation().insert();
        break;

      case 6:
        mylist.setItem().setLocation().replace();
        break;

      case 7:
        mylist.setLocation().deleteNode();
        break;

      case 8:
        mylist.reverse();
        break;

      case 9:
        mylist.reverseWithRecursion(mylist.getFirstNode());
        break;

      case 10:
        mylist.printLinkedList();
        break;

      case 11:
        mylist.printWithRecursion(mylist.getFirstNode());
        break;

      case 12:
        mylist.printInReverseWithRecursion(mylist.getFirstNode());
        break;

      case 13:
        mylist.reset();
        break;

      default:
        break;
    }
  }

  return 0;
}
