#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    int left = 1, right = x;
    if (x < 2) return x;

    while (left < right) {
      int mid = (right - left) / 2 + left;
      int temp = x / mid;
      if (temp == mid)
        return mid;
      else if (temp < mid) {
        right = mid;
      } else
        left = mid + 1;
    }
    return left - 1;
  }
};

int main(int argc, char const* argv[]) {
  Solution leet;
  int nums = 2147483647;
  int result = leet.mySqrt(nums);
  cout << result << endl;
  return 0;
}