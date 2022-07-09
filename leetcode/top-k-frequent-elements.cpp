
// not complete
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    if (nums.size() == 1 && k == 1) return {nums[0]};

    vector<int> result = {};
    sort(nums.begin(), nums.end());

    int i = 0, j = 1;
    int maxSize = nums.size();
    int counter = 1;

    while (j < maxSize) {
      if (nums[i] == nums[j])
        counter++;
      else {
        if (counter >= k) result.push_back(nums[i]);
        counter = 1;
      }

      i++;
      j++;
    }
    if (counter >= k) result.push_back(nums[i]);
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution leet;
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  vector<int> result = leet.topKFrequent(nums, 2);

  for (int i = 0; i < (int)result.size(); i++)
    cout << result[i] << ' ';
  return 0;
}