#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int result = 0, i, j;
    for (i = 0, j = nums.size() - 1; i < j; i++, j--)
      result ^= nums[i] ^ nums[j];

    if (i == j) result ^= nums[i];
    return result;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> nums = {1};
  int result = Solution().singleNumber(nums);

  cout << "RESULT: " << (result) << endl;
  return 0;
}
