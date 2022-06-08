#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] == 9) {
        digits[i] = 0;
        continue;
      }
      ++digits[i];
      return digits;
    }
    digits[0] = 1;
    digits.push_back(0);
    return digits;
  }
};

int main(int argc, char const* argv[]) {
  Solution leet;
  vector<int> nums = {8, 9, 9};
  vector<int> result = leet.plusOne(nums);

  for (int i = 0; i < (int)result.size(); i++) cout << result[i] << ' ';
  cout << endl;
  return 0;

  return 0;
}
