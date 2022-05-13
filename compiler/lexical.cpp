#include <iostream>
#include <regex>
using namespace std;

bool is_special_chars(string input)
{
    string part1 = "~|!|#|\\$|%|\\*|\\(|\\)|_|\\+|\\||`|-|=|";
    string part2 = "\\{|\\}|\\[|\\]|:|;|>|<|\\?|,|\\.|";
    regex pattern = regex(part1 + part2);
    if (regex_match(input, pattern))
        return true;
    else
        return false;
}
bool is_keyword(string input)
{
    string part1 = "auto|break|case|char|const|continue|default|do|double|else|enum|";
    string part2 = "extern|float|for|goto|if|int|long|register|return|short|signed|sizeof";
    string part3 = "|static|struct|switch|typedef|union|unsigned|void|volatile|while";
    regex pattern = regex((part1 + part2 + part3));
    if (regex_match(input, pattern))
        return true;
    else
        return false;
}
bool is_identifier(string input)
{
    regex pattern = regex("^([a-zA-Z_]).*[a-zA-Z0-9_]");
    if (regex_match(input, pattern))
        return true;
    else
        return false;
}
int main()
{
    string input, currentWord = "";
    getline(cin, input, ';');
    vector<string> special_chars, identifiers, keywords;
    int spaceCounter = 0;
    for (int i = 0; i < input.length(); i++)
    {
        bool isSpecialChar = is_special_chars(string(1, input[i]));
        if (isSpecialChar)
            special_chars.push_back(string(1, input[i]));
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t' || isSpecialChar)
        {
            if (!isSpecialChar)
                spaceCounter++;
            if (currentWord == "")
                continue;
            if (is_keyword(currentWord))
                keywords.push_back(currentWord);
            else if (is_identifier(currentWord))
                identifiers.push_back(currentWord);
            currentWord = "";
        }
        else
            currentWord += input[i];
    }
    if (is_keyword(currentWord))
        keywords.push_back(currentWord);
    else if (is_identifier(currentWord))
        identifiers.push_back(currentWord);

    cout << "Input:\n" + input << '\n';
    // identifiers print
    cout << "Special Char:\n";
    for (string item : special_chars)
        cout << item << "\n";
    cout << "Keywords:\n";
    for (string item : keywords)
        cout << item << "\n";
    cout << "Identifiers:\n";
    for (string item : identifiers)
        cout << item << "\n";
    cout << "Total spaces:\n";
    cout << spaceCounter << "\n";
}