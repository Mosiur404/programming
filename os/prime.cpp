#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int start = 0, end = 1000;

  for (int i = start; i <= end; i++) {
    bool flag = true;
    if (i == 0 || i == 1) continue;
    for (int j = 2; j < i / 2; j++) {
      if (i % j == 0) {
        flag = false;
        break;
      }
    }
    if (flag) cout << i << '\t';
  }

  return 0;
}