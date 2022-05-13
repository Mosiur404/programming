#include <iostream>
#include <regex>
using namespace std;

vector<string> output;

bool is_identifier(string input)
{
    regex pattern = regex("^([a-zA-Z_]).*[a-zA-Z0-9_]");
    if (input.length() == 1)
    {
        pattern = regex("[a-zA-Z_]");
    }
    if (regex_match(input, pattern))
        return true;
    else
        return false;
}
bool is_special_chars(string input)
{
    regex pattern = regex("\\*|\\/|-|;|>|=");
    if (regex_match(input, pattern))
        return true;
    else
        return false;
}

void handleSpecialChar(char input)
{
    switch (input)
    {
    case '=':
        output.push_back("= assignment");
        break;
    case '-':
        output.push_back("- minus");
        break;
    case '*':
        output.push_back("* multiplication");
        break;
    case '/':
        output.push_back("/ division");
        break;
    case '>':
        output.push_back("> relational operator");
        break;
    case ';':
        output.push_back("; special char");
        break;
    default:
        break;
    }
}

int main()
{
    string input;
    // getline(cin, input, '.');
    input = "a=b*c/b-c; and b>=c";

    string currentlyReading = "";

    for (int i = 0; i < input.length(); i++)
    {
        bool is_special_char_input = is_special_chars(string(1, input[i]));

        //if space the skip
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t' || is_special_char_input)
        {
            //if input is character

            if (is_identifier(currentlyReading))
            {
                output.push_back(currentlyReading + " identifier");
            }
            if (is_special_char_input)
            {
                handleSpecialChar(input[i]);
            }

            currentlyReading = "";
        }
        else
            currentlyReading += input[i];
    }

    if (currentlyReading != "")
    {
        if (is_identifier(currentlyReading))
        {
            output.push_back(currentlyReading + " identifier");
        }
    }

    cout << "\nOutput:\n\n";
    for (string item : output)
        cout << item << "\n";
}