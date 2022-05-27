#include <iostream>
#include <stack>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  int getOpeningIndex(char item) {
    char opening[3] = {'[', '{', '('};

    for (int i = 0; i < 3; i++)
      if (item == opening[i]) return i;
    return -1;
  }
  bool isValid(string expr) {
    char closing[3] = {']', '}', ')'};

    stack<int> closingIndex;

    for (int i = 0; i < expr.size(); i++) {
      int openingIndex = this->getOpeningIndex(expr[i]);

      if (openingIndex != -1)
        closingIndex.push(openingIndex);
      else {
        if (closingIndex.empty() || expr[i] != closing[closingIndex.top()])
          return false;
        else
          closingIndex.pop();
      }
    }
    return closingIndex.empty() ? true : false;
  }
};

int main(int argc, char const* argv[]) {
  Solution leet;
  string val = {"(])"};
  bool result = leet.isValid(val);
  //   cout << result << endl;
  cout << (result ? "TRUE" : "FALSE") << endl;
  //   vector<int> nums = {2, 7, 11, 15};
  //   int target = 9;
  //   vector<int> result = leet.twoSum(nums, target);

  //   for (int i = 0; i < (int)result.size(); i++) cout << result[i] << ' ';
  //   cout << endl;

  return 0;
}
