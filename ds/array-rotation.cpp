#include <iostream>
#include <vector>
using namespace std;

class ArrayRotation {
 private:
  vector<int> arr;

 public:
  ArrayRotation(vector<int> arr) { this->arr = arr; }

  void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
  }

  void swapLeftByOne(int arr[], int numberOfItems) {
    int temp = arr[0];

    for (int i = 0; i < numberOfItems - 1; i++) {
      arr[i] = arr[i + 1];
    }
    arr[numberOfItems - 1] = temp;
  }
  void reverseArray(int arr[], int start, int numberOfItems) {
    for (int i = 0; i < numberOfItems / 2; i++) {
      int temp = arr[i + start];
      arr[i + start] = arr[numberOfItems - i - 1];
      arr[numberOfItems - i - 1] = temp;
    }
  }
  ArrayRotation &init() { return *this; }
};

int main(int argc, char const *argv[]) {
  ArrayRotation MyArr({1, 2, 3});
  return 0;
}