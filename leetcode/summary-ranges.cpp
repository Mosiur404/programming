#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  string makeRange(int i, int j) {
    return (i == j ? to_string(i) : to_string(i) + "->" + to_string(j));
  }

  vector<string> summaryRanges(vector<int> &nums) {
    if (nums.size() == 0) return {};

    vector<string> result;

    int rangeMin = nums[0];
    int rangeMax = nums[0];

    int i = 0;
    int j = 1;

    while (j < nums.size()) {
      long long left = nums[i], right = nums[j];
      long long dx = right - left;
      if (dx == 1) {
        rangeMax = nums[j];
        j++;
        i++;
        continue;
      }
      result.push_back(this->makeRange(rangeMin, rangeMax));

      rangeMin = nums[i = j];
      rangeMax = nums[j++];
    }
    if (j == nums.size()) result.push_back(this->makeRange(rangeMin, rangeMax));

    return result;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
  vector<string> result = Solution().summaryRanges(nums);

  for (int i = 0; i < (int)result.size(); i++)
    cout << result[i] << ' ';
  cout << endl;
  return 0;
}
