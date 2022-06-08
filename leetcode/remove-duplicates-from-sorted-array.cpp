#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int counter = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1])
        counter++;
      else
        nums[i - counter] = nums[i];
    }
    if (counter > 0) nums.resize(nums.size() - counter);
    return nums.size();
  };
};

int main(int argc, char const* argv[]) {
  Solution leet;
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int target = 9;
  int result = leet.removeDuplicates(nums);

  for (int i = 0; i < (int)nums.size(); i++) cout << nums[i] << ' ';
  cout << endl;
  cout << result << endl;
  return 0;
}