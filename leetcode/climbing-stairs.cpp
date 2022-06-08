#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    int dpSize = n + 1;
    unsigned int memo[dpSize];
    memo[0] = 1;
    memo[1] = 1;
    for (int i = 2; i < dpSize; i++) {
      memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
  }
};

int main(int argc, char const* argv[]) {
  Solution leet;
  int nums = 3;
  int result = leet.climbStairs(nums);
  cout << result << endl;
  return 0;
}