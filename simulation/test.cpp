#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int a = 12, b = 12, c = 13, d = 6, e = 13;
  cout << (a ^ b ^ c ^ d ^ e) << ' ' << b;
  return 0;
}
