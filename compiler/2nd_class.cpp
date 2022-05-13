// Write a program to Find identifier from input stream
// Sample input: CSE_412 Compiler Sessional\n#name : Mosiur Rahman\nID : CSE
// 00000000 Sample output: CSE_412, Compiler, Sessional...

#include <iostream>
#include <regex>
using namespace std;

int main() {
  string input;
  getline(cin, input, ';');

  string currentlyReading = "";
  vector<string> result;
  regex pattern = regex("^([a-zA-Z_]).*[a-zA-Z0-9_]");

  for (int i = 0; i < input.length(); i++) {
    if (input[i] == ' ' || input[i] == '\n') {
      // if value is empty then skip
      if (currentlyReading == "") continue;

      if (regex_match(currentlyReading, pattern))
        result.push_back(currentlyReading);
      // if regex match then insert it in result array

      currentlyReading = "";
      continue;
    } else
      currentlyReading += input[i];
  }

  // check last
  if (currentlyReading != "" &&
      regex_match(currentlyReading, regex("^([a-zA-Z_]).*[a-zA-Z0-9_]")))
    result.push_back(currentlyReading);

  // result print
  cout << "Output is here:\n\n";
  for (string item : result) cout << item << "\n";
}