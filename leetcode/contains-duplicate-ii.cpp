#include <iostream>
#include <vector>
#include <unordered_map>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    if (k <= 0) return false;
    unordered_map<int, int> map;
    int i = 0;
    int j = nums.size() - 1;
    while (i < j) {
      int left = nums[i], right = nums[j];
      if (left == right && abs(i - j) <= k) return true;

      if (map.find(left) == map.end())
        map[left] = i;
      else if (abs(map[left] - i) <= k)
        return true;
      else
        map[left] = i;

      if (map.find(right) == map.end())
        map[right] = j;
      else if (abs(map[right] - j) <= k)
        return true;
      else
        map[right] = j;

      i++;
      j--;
    }
    if (i == j && map.find(nums[i]) != map.end() && abs(map[nums[i]] - i))
      return true;

    return false;
  }
};

int main(int argc, char const *argv[]) {
  Solution leet;
  vector<int> nums = {1, 0, 1, 1};
  int k = 1;
  int result = leet.containsNearbyDuplicate(nums, k);
  cout << (result ? "TRUE" : "FALSE") << endl;
  return 0;
}