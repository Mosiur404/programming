#include <iostream>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    // IV (5) and X (10) 4 and 9.
    // XL (50) and C (100) 40 and 90.
    // CD (500) and M (1000) 400 and 900.
    // I             1
    // V             5
    // X             10
    // L             50
    // C             100
    // D             500
    // M             1000
    char prev = ' ';
    int total = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'M')
        total += 1000;
      else if (s[i] == 'D')
        total += 500;
      else if (s[i] == 'C') {
        if (i < s.size() - 1) {
          if (s[i + 1] == 'D') {
            total += 400;
            i++;
          } else if (s[i + 1] == 'M') {
            total += 900;
            i++;
          } else
            total += 100;
        } else
          total += 100;
      } else if (s[i] == 'L')
        total += 50;
      else if (s[i] == 'X') {
        if (i < s.size() - 1) {
          if (s[i + 1] == 'L') {
            total += 40;
            i++;
          } else if (s[i + 1] == 'C') {
            total += 90;
            i++;
          } else
            total += 10;
        } else
          total += 10;
      } else if (s[i] == 'V')
        total += 5;
      else if (s[i] == 'I') {
        if (i < s.size() - 1) {
          if (s[i + 1] == 'V') {
            total += 4;
            i++;
          } else if (s[i + 1] == 'X') {
            total += 9;
            i++;
          } else
            total += 1;
        } else
          total += 1;
      }
    }

    return total;
  }
};

int main(int argc, char const* argv[]) {
  Solution leet;
  int result = leet.romanToInt("LVIII");
  cout << result << endl;
  //   cout << (result ? "TRUE" : "FALSE") << endl;
  //   vector<int> nums = {2, 7, 11, 15};
  //   int target = 9;
  //   vector<int> result = leet.twoSum(nums, target);

  //   for (int i = 0; i < (int)result.size(); i++) cout << result[i] << ' ';
  //   cout << endl;

  return 0;
}
