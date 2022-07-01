#include <iostream>
#include <vector>
#include <cmath>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  int memo[10];
  int pdi_function(int n) {
    int base = 10;
    int total = 0;
    while (n) {
      total += this->memo[n % base];
      n /= base;
    }
    cout << total << ' ';
    return total;
  }

  bool isHappy(int n) {
    // for (int i = 0; i < 10; i++)
    //   this->memo[i] = pow(i, 2);

    // int slow, fast;
    // slow = fast = n;
    // do {
    //   slow = pdi_function(slow);
    //   // cout << slow;
    //   fast = pdi_function(fast);
    //   // cout << ' ' << fast;
    //   fast = pdi_function(fast);
    //   // cout << ' ' << fast << endl;
    //   if (fast == 1) return 1;
    // } while (slow != fast);
    // return 0;

    for (int i = 0; i < 10; i++)
      this->memo[i] = pow(i, 2);
    int power = 1;
    int length = 1;
    int tortoise = n;
    int hare = this->pdi_function(n);

    while (tortoise != hare && hare > 1) {
      if (length == power) {
        tortoise = hare;
        power = power << 1;
        length = 0;
      }
      hare = this->pdi_function(hare);
      length++;
    }
    cout << "found";
    return hare == 1;
  }
};

int main(int argc, char const *argv[]) {
  Solution leet;
  int nums = 2;
  bool result = leet.isHappy(nums);
  cout << (result ? "TRUE" : "FALSE") << endl;
  return 0;
}