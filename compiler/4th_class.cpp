// Write a program to Find identifier, keywords and spaces from input stream
// Sample input: During On campus classes /*everybody\nshould be present the classes.*/\nThe class schedule of CSE17 is Saturday // at\n9 am for online classes students have to join the classes via auto generated link"
// Sample output:

#include <iostream>
#include <regex>
using namespace std;

bool multilineMode = false;
bool commentMode = false;

bool is_comments_single_line(string input)
{
    // /*.*/ = /*test*/
    regex pattern = regex("//[^]*");
    if (regex_match(input, pattern))
    {
        return true;
    }
    else
        return false;
}
bool is_comments_multi_line(string input)
{

    regex pattern = regex("^/*.[^]*.*/$");
    if (regex_match(input, pattern))
    {
        // /*.*/ = /*test*/
        return true;
    }
    else if (regex_match(input, regex("^(/\\*)[^]*")))
    {
        // string starts with /*
        multilineMode = true;
        commentMode = true;
        return true;
    }
    else if (regex_match(input, regex("[^]*.\\*/$")))
    {
        // string ends with */
        multilineMode = false;
        commentMode = false;
        return true;
    }
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
    // getline(cin, input, ';');
    // input = "During On campus classes /*everybody\nshould be present the classes.*/\nThe class schedule of CSE17 is Saturday // at\n9 am for online classes students have to join the classes via auto generated link";
    input = "Hello  /*multi1 hello multi2*/ var2";
    string currentlyReading = "";

    vector<string> comments;
    vector<string> identifiers;
    vector<string> keywords;
    int spaceCounter = 0;

    for (int i = 0; i < input.length(); i++)
    {
        bool newLineFound = input[i] == '\n';

        if (input[i] == ' ' || newLineFound || input[i] == '\t')
        {
            // cout << currentlyReading << '\n';
            // if multiline comments the enable multilineMode
            if (currentlyReading == "\\*")
                multilineMode = true;
            // for //: if new line is found and multilineMode false then disable commnetMode
            // for /* */: if multilineMode true and found '*/' then disable commnetMode
            if (commentMode == true && ((newLineFound && !multilineMode) || (multilineMode && currentlyReading == "*/")))
                commentMode = false;
            // if value is empty then skip
            if (currentlyReading == "")
                continue;
            // if `//` is found then start commentmode
            if (currentlyReading == "//" || currentlyReading == "\\*")
                commentMode = true;

            /* for comment with space ex: // hello -start*/
            //if commentsMode is enabled then everything is comments until \n is found
            if (commentMode == true)
            {
                comments.push_back(currentlyReading + input[i]);
                currentlyReading = "";
                continue;
                // if comments no need for following checks
            }

            /* for comment with space -end */
            if (is_comments_single_line(currentlyReading))
            {
                commentMode = true;
                comments.push_back(currentlyReading + input[i]);
            }
            else if (is_comments_multi_line(currentlyReading))
                comments.push_back(currentlyReading + input[i]);
            else if (is_keyword(currentlyReading))
                keywords.push_back(currentlyReading);

            else if (is_identifier(currentlyReading))
                identifiers.push_back(currentlyReading);

            spaceCounter++;
            currentlyReading = "";
        }
        else
            currentlyReading += input[i];
    }

    // //check last
    if (is_comments_single_line(currentlyReading))
    {
        comments.push_back(currentlyReading);
    }
    else if (is_comments_multi_line(currentlyReading))
        comments.push_back(currentlyReading);
    else if (is_keyword(currentlyReading))
        keywords.push_back(currentlyReading);

    else if (is_identifier(currentlyReading))
        identifiers.push_back(currentlyReading);
    else if (is_keyword(currentlyReading))
        keywords.push_back(currentlyReading);

    else if (is_identifier(currentlyReading))
        identifiers.push_back(currentlyReading);

    // output print
    cout
        << "\nComments:\n\n";
    for (string item : comments)
        cout << item << "";

    cout << "\n\nKeywords:\n\n";
    for (string item : keywords)
        cout << item << "\n";

    cout << "\n\nIdentifiers:\n\n";
    for (string item : identifiers)
        cout << item << "\n";

    cout << "\n\nTotal spaces:\n\n";
    cout << spaceCounter << "\n";
}