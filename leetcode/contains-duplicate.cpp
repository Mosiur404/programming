#include <iostream>
#include <vector>
#include <unordered_set>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> set;
    int i = 0;
    int j = nums.size() - 1;
    while (i < j) {
      int left = nums[i], right = nums[j];
      if (left == right) return true;

      if (set.find(left) == set.end())
        set.insert(left);
      else
        return true;
      if (set.find(right) == set.end())
        set.insert(right);
      else
        return true;

      i++;
      j--;
    }
    if (i == j && set.find(nums[i]) != set.end()) return true;
    return false;
  }
};

int main(int argc, char const *argv[]) {
  Solution leet;
  vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  int result = leet.containsDuplicate(nums);
  cout << (result ? "TRUE" : "FALSE") << endl;
  return 0;
}