#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    const string str = to_string(x);
    int start = 0, end = str.size() - 1;

    if (end < 1) return true;
    while (start < end) {
      if (str[start] != str[end]) return false;

      start++;
      end--;
    }
    return true;
  }
};

int main(int argc, char const* argv[]) {
  Solution leet;
  bool result = leet.isPalindrome(10);
  cout << (result ? "TRUE" : "FALSE") << endl;
  //   vector<int> nums = {2, 7, 11, 15};
  //   int target = 9;
  //   vector<int> result = leet.twoSum(nums, target);

  //   for (int i = 0; i < (int)result.size(); i++) cout << result[i] << ' ';
  //   cout << endl;

  return 0;
}
