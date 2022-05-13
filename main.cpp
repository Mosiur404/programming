#include <iostream>
using namespace std;

int gcd(int m, int n) {
  if (m == 0) return n;
  if (n == 0) return m;

  if (m > n) return gcd(m % n, n);

  return gcd(m, n % m);
}

int main() {
  int m = 24, n = 18;
  cout << "GCD: " << gcd(m, n) << endl;
  cout << "LCM: " << (m * n / gcd(m, n)) << endl;
}