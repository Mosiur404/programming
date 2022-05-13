#include <iostream>
#include <regex>
using namespace std;

int main()
{

    string input;
    // getline(cin, input, ';');
    input = "aaaa";

    bool flag = false;

    if (input.length() == 0)
        flag = true;
    else
    {
        flag = true;
        for (int i = 0; i < input.length(); i++)
        {
            // if (input[i] == 'a')
            //     continue;
            // flag = false;
            // break;
            switch (input[i])
            {
            case 'a':
                continue;
            default:
                flag = false;
                break;
            }
        }
    }
    cout << (flag ? "\n accpeted \n" : "\n rejected \n");
}