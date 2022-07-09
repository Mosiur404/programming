#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  int doArithmatic(int operand1, int operand2, char opr) {
    switch (opr) {
    case '+':
      return operand1 + operand2;
    case '-':
      return operand1 - operand2;
    case '*':
      return operand1 * operand2;
    case '/':
      return operand1 / operand2;
    default:
      return 0;
    }
  }
  bool isCharacter(string &s) {
    if (s.length() != 1) return false;
    switch (s[0]) {
    case '+':
    case '-':
    case '/':
    case '*':
      return true;
      break;

    default:
      return false;
    }
  }
  int evalRPN(vector<string> &tokens) {
    stack<int> result;
    for (string &s : tokens) {
      if (!isCharacter(s))
        result.push(stoi(s));
      else {
        int operand2 = result.top();
        result.pop();
        int operand1 = result.top();
        result.pop();
        result.push(doArithmatic(operand1, operand2, s[0]));
      }
    }
    return result.top();
  }
};
int main(int argc, char const *argv[]) {
  vector<string> tokens = {"2", "1", "+", "3", "*"};
  int result = Solution().evalRPN(tokens);
  cout << result << endl;
  return 0;
}
