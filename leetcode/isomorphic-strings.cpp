#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;
    char sMemo[256] = {0};
    char tMemo[256] = {0};

    for (int i = 0; i < s.length(); i++) {
      char sChar = s[i];
      char tChar = t[i];

      if (sMemo[sChar] == 0 && tMemo[tChar] == 0) {
        sMemo[sChar] = tChar;
        tMemo[tChar] = sChar;
        continue;
      }
      if (sMemo[sChar] != tChar || tMemo[tChar] != sChar) return false;
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  Solution leet;
  string s = "paper", t = "title";
  int result = leet.isIsomorphic(s, t);
  cout << (result ? "TRUE" : "FALSE") << endl;

  return 0;
}
