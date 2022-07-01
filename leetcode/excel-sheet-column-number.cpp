#include <iostream>
#include <algorithm>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  int titleToNumber(string columnTitle) {
    const char c = 'A' - 1;
    unsigned int result = 0;
    unsigned int multiplier = 1;
    for (int i = columnTitle.length() - 1; i >= 0; i--) {
      int number = columnTitle[i] - c;

      result += number * multiplier;
      multiplier *= 26;
    }
    return result;
  }
};
int main(int argc, char const *argv[]) {
  int result = Solution().titleToNumber("ZY");
  cout << result << endl;
  return 0;
}
