#include <iostream>
#include <algorithm>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    string result = "";
    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0) {
        carry += a[i] - '0';
        i--;
      }
      if (j >= 0) {
        carry += b[j] - '0';
        j--;
      }
      result += carry % 2 + '0';
      carry = carry / 2;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution leet;
  string a = "100", b = "110010";
  string result = leet.addBinary(a, b);
  cout << result << endl;
  return 0;
}
