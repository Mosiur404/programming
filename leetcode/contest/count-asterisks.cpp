#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int countAsterisks(string s) {
    int asterics = 0;
    bool readMode = true;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '|')
        readMode = !readMode;
      else if (readMode && s[i] == '*')
        asterics++;
    }
    return asterics;
  }
};

int main(int argc, char const *argv[]) {
  string s = "yo|uar|e**|b|e***au|tifu|l";
  int result = Solution().countAsterisks(s);

  cout << "RESULT: " << (result) << endl;
  return 0;
}
