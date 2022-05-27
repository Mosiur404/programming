#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string result = "";
    string selected = strs[0];
    for (int i = 0; i < selected.length(); i++) {
      for (int j = 1; j < strs.size(); j++) {
        if (i >= strs[j].length()) return result;
        if (selected[i] != strs[j][i]) return result;
      }
      result += selected[i];
    }

    return result;
  }
};

int main(int argc, char const* argv[]) {
  Solution leet;
  vector<string> val = {"flower", "flow", "flight"};
  string result = leet.longestCommonPrefix(val);
  cout << result << endl;
  //   cout << (result ? "TRUE" : "FALSE") << endl;
  //   vector<int> nums = {2, 7, 11, 15};
  //   int target = 9;
  //   vector<int> result = leet.twoSum(nums, target);

  //   for (int i = 0; i < (int)result.size(); i++) cout << result[i] << ' ';
  //   cout << endl;

  return 0;
}
