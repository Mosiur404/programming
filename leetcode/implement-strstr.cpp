#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int j;
    char selected = needle[0];
    for (int i = 0; i < haystack.length(); i++) {
      if (haystack[i] == selected) {
        for (j = 1; j < needle.length(); j++) {
          if (haystack[i + j] == needle[j]) continue;
          break;
        }
        if (j == needle.length()) return i;
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  Solution leet;
  string haystack = "hello";
  string needle = "ll";
  int result = leet.strStr(haystack, needle);
  cout << result << endl;

  return 0;
}
