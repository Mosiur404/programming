#include <iostream>
#include <algorithm>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    int memo[26] = {0};
    for (int i = 0; i < s.length(); i++) {
      int s1 = s[i] - 'a';
      int s2 = t[i] - 'a';
      memo[s1]++;
      memo[s2]--;
    }
    for (int i = 0; i < 26; i++)
      if (memo[i]) return false;

    return true;
  }
};

int main(int argc, char const *argv[]) {
  Solution leet;
  string s = "nl", t = "cx";
  bool result = leet.isAnagram(s, t);
  cout << (result ? "TRUE" : "FALSE") << endl;
  return 0;
}
