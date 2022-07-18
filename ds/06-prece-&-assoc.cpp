#include <iostream>
#include <stack>
#define log(x) std::cout << x << std::endl;
using namespace std;

string reverseString(string &text, int n) {
  stack<char> newStack = {};

  for (int i = 0; i < text.size(); i++) {
    newStack.push(text[i]);
  }

  for (int i = 0; i < text.size(); i++) {
    text[i] = newStack.top();
    newStack.pop();
  }
  return text;
}

int getOpeningIndex(char item) {
  char opening[] = {'[', '{', '('};

  for (int i = 0; i < 3; i++)
    if (item == opening[i]) return i;
  return -1;
}

bool checkBlalancedParenthesis(string expr) {
  char closing[] = {']', '}', ')'};

  stack<int> closingIndex;

  for (int i = 0; i < expr.size(); i++) {
    int openingIndex = getOpeningIndex(expr[i]);

    if (openingIndex != -1)
      closingIndex.push(openingIndex);
    else {
      if (closingIndex.empty() || expr[i] != closing[closingIndex.top()])
        return false;
      else
        closingIndex.pop();
    }
  }
  return closingIndex.empty() ? true : false;
}

int main(int argc, char const *argv[]) {
  string text = "HELLO";

  log(reverseString(text, 5));

  string text1 = "[()({})]";

  log((checkBlalancedParenthesis(text1) ? "T" : "F"));

  return 0;
}
