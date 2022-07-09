#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (i < j) {
      int left = nums[i], right = nums[j];
      int current = left + right;

      if (current == target) break;

      if (current < target)
        i++;
      else
        j--;
    }

    return {i + 1, j + 1};
  }
};
// class Solution {
// public:
//   vector<int> twoSum(vector<int> &nums, int target) {
//     unordered_map<int, int> map;

//     for (int i = 0; i < nums.size(); i++) {
//       int otherPart = target - nums[i];
//       if (map.find(otherPart) != map.end()) {
//         return {map[otherPart] + 1, i + 1};
//       }
//       map[nums[i]] = i;
//     }
//     return {};
//   }
// };
// class Solution {
//  public:
//   vector<int> twoSum(vector<int>& nums, int target) {
//     for (int i = 0; i < (int)nums.size(); i++) {
//       int selected = nums[i];
//       for (int j = 0; j < (int)nums.size(); j++) {
//         if (i == j) continue;
//         int current = nums[j];
//         if (selected + current == target) return {i, j};
//       }
//     }
//     return {};
//   }
// };

int main(int argc, char const *argv[]) {
  Solution leet;
  vector<int> nums = {2, 3, 4};
  int target = 6;
  vector<int> result = leet.twoSum(nums, target);

  for (int i = 0; i < (int)result.size(); i++)
    cout << result[i] << ' ';
  cout << endl;
  return 0;
}
