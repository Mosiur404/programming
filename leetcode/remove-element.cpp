#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int counter = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == val)
        counter++;
      else
        nums[i - counter] = nums[i];
    }
    return nums.size() - counter;
  }
};

int main(int argc, char const* argv[]) {
  Solution leet;
  int target = 3;
  vector<int> nums = {2, 2, 1, 2, 4, 3};
  int result = leet.removeElement(nums, target);

  for (int i = 0; i < (int)nums.size(); i++) cout << nums[i] << ' ';
  cout << endl;
  cout << result << endl;
  return 0;
}