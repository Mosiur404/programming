#include <iostream>
#define log(x) std::cout << x << std ::endl;
using namespace std;

// class Solution {
// public:
//   bool isPalindrome(string s) {
//     for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
//       while (!isalnum(s[i]) && i < j)
//         i++;
//       while (!isalnum(s[j]) && i < j)
//         j--;
//       if (toupper(s[i]) != toupper(s[j])) return false;
//     }
//     return true;
//   }
// };
class Solution {
public:
  bool isValid(char &c) {
    if (c >= 'a' && c <= 'z') return true;
    if (c >= 'A' && c <= 'Z') {
      c += 32;
      return true;
    }
    if (c >= '0' && c <= '9') return true;
    return false;
  }

  bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
      if (!isValid(s[left])) {
        left++;
        continue;
      }
      if (!isValid(s[right])) {
        right--;
        continue;
      }
      if (s[left] != s[right]) return false;
      left++;
      right--;
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  string s = "00";
  bool result = Solution().isPalindrome(s);
  cout << (result ? "TRUE" : "FALSE") << endl;
}
