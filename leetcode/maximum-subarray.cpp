#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int maximum = nums[0];

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];

      if (sum > maximum) maximum = sum;

      if (sum < 0) sum = 0;
    }
    return maximum;
  }
};

int main(int argc, char const* argv[]) {
  Solution leet;
  vector<int> nums = {5, 4, -1, 7, 8};
  int result = leet.maxSubArray(nums);
  cout << result << endl;
  return 0;
}