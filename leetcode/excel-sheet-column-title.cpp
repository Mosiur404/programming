#include <iostream>
#include <algorithm>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  string convertToTitle(int columnNumber) {
    const char c = 'A';
    unsigned int totalAlphabet = 26;
    string result = "";

    unsigned int remainder;
    while (columnNumber != 0) {
      columnNumber--;
      remainder = columnNumber % totalAlphabet;
      columnNumber /= totalAlphabet;

      result += (c + remainder);
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main(int argc, char const *argv[]) {
  string result = Solution().convertToTitle(701);
  cout << result << endl;
  return 0;
}
