#include <iostream>
using namespace std;

class MyArray {
private:
  int *MyArr;
  int numberOfItems = 0;

public:
  int location, item;
  void Print(string text) { cout << '\n' << text << '\n'; }

  MyArray &push() {
    this->MyArr[this->numberOfItems] = this->item;
    numberOfItems++;

    this->Print("Push " + to_string(this->item) + " at location " +
                to_string(this->numberOfItems) + " Successfull");

    return *this;
  }

  MyArray &pop() {
    numberOfItems--;

    this->Print("Pop " + to_string(this->MyArr[numberOfItems]) +
                " at location " + to_string(this->numberOfItems + 1) +
                " Successfull");
    return *this;
  }

  MyArray &insert() {
    if (this->isLocationInValid(this->location)) return *this;
    // 0 1 2
    for (int i = this->numberOfItems; i >= this->location; i--)
      this->MyArr[i] = this->MyArr[i - 1];

    this->MyArr[this->location - 1] = this->item;
    this->Print("My item " + to_string(this->location) + to_string(this->item));
    this->numberOfItems++;

    this->Print("Insert " + to_string(this->item) + " at location " +
                to_string(this->location) + " Successfull");

    return *this;
  }

  MyArray &replace(void) {
    if (this->isLocationInValid(this->location)) return *this;

    this->MyArr[location - 1] = item;

    this->Print("Replace " + to_string(this->item) + " at location " +
                to_string(this->location) + " Successfull");

    return *this;
  }

  MyArray &deleteItem(void) {
    if (this->isLocationInValid(this->location)) return *this;

    for (int i = this->location; i < this->numberOfItems; i++)
      this->MyArr[i - 1] = this->MyArr[i];

    this->numberOfItems--;

    this->Print("Delete " + to_string(this->item) + " at location " +
                to_string(this->location) + " Successfull");

    return *this;
  }

  // start extra
  MyArray &setItem() {
    cout << "Insert Item: ";
    cin >> this->item;
    return *this;
  }
  MyArray &setLocation() {
    cout << "Insert Location: ";
    cin >> this->location;
    return *this;
  }

  bool isLocationInValid(int location) {
    this->Print("Location " + to_string(location) + " is not valid.");
    return (location <= 0 || location >= numberOfItems);
  }

  void printArray(void) {
    cout << "MyArr is: ";
    if (numberOfItems == 0) cout << "Empty";
    for (int i = 0; i < this->numberOfItems; i++)
      cout << this->MyArr[i] << " ";
  }
  // end extra
  // copy constructor (detail here: https://youtu.be/BvR1Pgzzr38)
  MyArray(const MyArray &otherClass) {
    this->numberOfItems = otherClass.numberOfItems;
    this->MyArr = new int[this->numberOfItems];
    memcpy(this->MyArr, otherClass.MyArr,
           sizeof(int) * otherClass.numberOfItems);
  }
  // move constructor (detail here: https://youtu.be/ehMg6zvXuMY)
  MyArray(MyArray &&otherClass) noexcept {
    this->numberOfItems = otherClass.numberOfItems;
    this->MyArr = otherClass.MyArr;

    otherClass.numberOfItems = 0;
    otherClass.MyArr = nullptr;
  }
  MyArray(int n = 100) { MyArr = new int[n]; }
  ~MyArray() {}
};

int main(int argc, char const *argv[]) {
  MyArray arr;
  int command;

  while (true) {
    cout << "\n\nChoose option: ";
    cout << "\n0) Exit";
    cout << "\n1) Push";
    cout << "\n2) Pop";
    cout << "\n3) Insert";
    cout << "\n4) Replace";
    cout << "\n5) Delete";
    cout << "\n6) Print\n";

    cin >> command;

    if (command == 0) {
      cout << "\nExited Successfully.";
      break;
    };

    switch (command) {
    case 1:
      arr.setItem().push();
      break;

    case 2:
      arr.pop();
      break;

    case 3:
      arr.setItem().setLocation().insert();
      break;

    case 4:
      arr.setItem().setLocation().replace();
      break;

    case 5:
      arr.setLocation().deleteItem();
      break;

    case 6:
      arr.printArray();
      break;

    default:
      break;
    }
  }

  return 0;
}
