#include <iostream>
#include <regex>
using namespace std;

class Notation {
 private:
  string output = "", notation_type = "Infix Notation";
  vector<string> language;
  bool is_special_char(string letter) {
    regex pattern = regex("\\*|\\+|/|-");
    if (regex_match(letter, pattern))
      return true;
    else
      return false;
  }

  int do_math(string symbol, int number1, int number2) {
    if (symbol == "+") {
      return number1 + number2;
    } else if (symbol == "-") {
      return number1 - number2;
    } else if (symbol == "*") {
      return number1 * number2;
    } else if (symbol == "/") {
      return number1 / number2;
    }
    return 1;
  }

 public:
  Notation(string language) {
    int total = language.length();
    for (int i = 0; i < total; i++)
      this->language.push_back(string(1, language[i]));
  }
  Notation &init() {
    int i = 0, totalChar = this->language.size();
    int result = 0;
    if (is_special_char(this->language[i]))
      this->notation_type = "Prefix Notation";
    else if (is_special_char(this->language[totalChar - 1]))
      this->notation_type = "Postfix Notation";
    for (int i = totalChar - 1; i >= 0; i--) {
      this->output += this->language[i];
      if (is_special_char(this->language[i])) {
        result = this->do_math(this->language[i], stoi(this->language[i + 1]),
                               stoi(this->language[i + 2]));
        this->language[i] = to_string(result);

        this->language.erase(this->language.begin() + i + 1);
        this->language.erase(this->language.begin() + i + 1);

        totalChar = this->language.size();
        i = totalChar - 1;
      }
    }
    this->output = this->language[0];
    return *this;
  }

  void print() {
    cout << "It is " << notation_type << '\n' << "Result: " << this->output;
  }
};

int main() {
  cout << "\nInput: ";
  string input = "*+825";
  cout << input << '\n';
  Notation(input).init().print();
}