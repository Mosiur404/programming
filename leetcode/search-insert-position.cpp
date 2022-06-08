#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, mid = 0;

    while (low < high) {
      mid = (low + high - 1) / 2;
      if (target == nums[mid]) return mid;

      if (nums[mid] > target)
        high = mid;
      else
        low = mid + 1;
    }
    cout << "L: " << low << ' ' << "H: " << high << ' ' << "M: " << mid << endl;
    return (nums[low] < target) ? low + 1 : low;
  }
};

int main(int argc, char const* argv[]) {
  Solution leet;
  int target = 3;
  vector<int> nums = {1, 2, 4, 6, 7};

  int result = leet.searchInsert(nums, target);

  for (int i = 0; i < (int)nums.size(); i++) cout << nums[i] << ' ';
  cout << endl;
  cout << result << endl;
  return 0;
}