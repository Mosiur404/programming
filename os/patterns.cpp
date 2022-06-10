#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int inp = 4;
  for (int i = 1; i <= inp; i++) {
    for (int j = 0; j < i; j++) cout << i << ' ';
    cout << endl;
  }
  cout << endl << endl;

  for (int i = 0; i < inp; i++) {
    for (int j = inp - i; j > 0; j--) cout << j << ' ';
    cout << endl;
  }

  for (int i = 0; i < inp; i++) {
    for (int j = inp - i + 1; j > 0; j--) cout << ' ';

    for (int k = 0; k <= i; k++) cout << k + 1;
    cout << endl;
  }

  return 0;
}
