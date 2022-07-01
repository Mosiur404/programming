#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};
// class Solution {
// public:
//   int majorityElement(vector<int> &nums) {
//     int minSize = nums.size() / 2;
//     unordered_map<uintptr_t, int> hashMap;
//     int i, j;
//     for (i = 0, j = nums.size() - 1; i < j; i++, j--) {
//       hashMap[nums[i]]++;
//       hashMap[nums[j]]++;

//       if (hashMap[nums[i]] > minSize) return nums[i];
//       if (hashMap[nums[j]] > minSize) return nums[j];
//     }
//     if (i == j) hashMap[nums[i]]++;
//     if (hashMap[nums[i]] > minSize) return nums[i];
//     return 0;
//   }
// };

int main(int argc, char const *argv[]) {
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  int result = Solution().majorityElement(nums);
  cout << "result: " << result << endl;
  return 0;
}
