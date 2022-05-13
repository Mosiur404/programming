// Write a program to Find identifier, keywords and spaces from input stream
// Sample input: for hello 1234 tt;
// Sample output: Keywords: for Identifiers: hello tt Total spaces: 3

#include <iostream>
#include <regex>
using namespace std;

bool is_special_chars(string input)
{
    regex pattern = regex("~|!|#|\\$|%|\\*|\\(|\\)|_|\\+|\\||`|-|=|\\{|\\}|\\[|\\]|:|;|>|<|\\?|,|\\.|");
    if (regex_match(input, pattern))
        return true;
    else
        return false;
}

bool is_keyword(string input)
{
    regex pattern = regex("auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while");

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
    string input;
    getline(cin, input, ';');

    string currentlyReading = "";
    vector<string> special_chars, identifiers, keywords;

    int spaceCounter = 0;

    for (int i = 0; i < input.length(); i++)
    {
        if (is_special_chars(string(1, input[i])))
            special_chars.push_back(string(1, input[i]));
        else if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t')
        {
            spaceCounter++;

            // if value is empty then skip
            if (currentlyReading == "")
                continue;

            if (is_keyword(currentlyReading))
                keywords.push_back(currentlyReading);

            else if (is_identifier(currentlyReading))
                identifiers.push_back(currentlyReading);

            currentlyReading = "";
        }
        else
            currentlyReading += input[i];
    }

    //check last
    if (is_keyword(currentlyReading))
        keywords.push_back(currentlyReading);

    else if (is_identifier(currentlyReading))
        identifiers.push_back(currentlyReading);

    // identifiers print
    cout << "\nSpecial Char:\n\n";
    for (string item : special_chars)
        cout << item << "\n";

    cout << "\nKeywords:\n\n";
    for (string item : keywords)
        cout << item << "\n";

    cout << "\nIdentifiers:\n\n";
    for (string item : identifiers)
        cout << item << "\n";

    cout << "\nTotal spaces:\n\n";
    cout << spaceCounter << "\n";
}