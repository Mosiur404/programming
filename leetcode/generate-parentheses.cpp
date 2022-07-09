#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>

#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  int hammingWeight(uint16_t n) {
    int result = 0;
    while (n) {
      n &= (n - 1);
      result++;
    }
    return result;
  }

  vector<string> generateParenthesis(int n) {
    vector<string> result;

    // catalan number C(0) - C(8)
    int catalans[9] = {1, 1, 2, 5, 14, 42, 132, 429, 1430};

    uint16_t lengthOfBits = n * 2;
    uint16_t lengthOfHalfBits = n;

    uint16_t currentNumber = pow(2, n) - 1;

    int i = 0;
    while (i < catalans[n]) {
      uint16_t lengthOfSetBits = this->hammingWeight(currentNumber);
      if (lengthOfSetBits != lengthOfHalfBits) {
        currentNumber += 2;
        continue;
      }
      cout << currentNumber << ' ';
      string temp = "";
      int opening = 0, closing = 0;
      bool isValid = true;
      for (int j = 0; j < lengthOfBits; j++) {
        if (!!(currentNumber & (1 << j))) {
          temp += '(';
          opening++;
        } else {
          temp += ')';
          closing++;
        }
        if (opening < closing) {
          isValid = false;
          break;
        }
      }
      currentNumber += 2;

      if (!isValid) continue;

      result.push_back(temp);
      i++;
    }
    return result;
  }
};

// class Solution {
// public:
//   void _generateParenthesis(string s, int opening, int closing, int max,
//                             vector<string> &result) {
//     if (opening == max && closing == max) {
//       result.push_back(s);
//       return;
//     }
//     if (opening < max)
//       _generateParenthesis(s + '(', opening + 1, closing, max, result);
//     if (closing < opening)
//       _generateParenthesis(s + ')', opening, closing + 1, max, result);
//   }
//   vector<string> generateParenthesis(int n) {
//     vector<string> result;
//     this->_generateParenthesis("", 0, 0, n, result);
//     return result;
//   }
// };
int main(int argc, char const *argv[]) {
  vector<string> result = Solution().generateParenthesis(3);
  for (string s : result)
    cout << s << ' ';
  cout << endl;
  // vector<string> test1 = {"000111", "001011", "001101", "010011", "010101"};
  // vector<string> test2 = {"111000", "110100", "110010", "101100", "101010"};
  // for (string t : test1)
  //   cout << (int)((bitset<6>(t)).to_ulong()) << ' ';
  // cout << endl;
  // for (string t : test2)
  //   cout << (int)((bitset<6>(t)).to_ulong()) << ' ';
  // cout << endl;

  return 0;
}
