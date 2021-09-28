#include <iostream>
using namespace std;

bool checkValidity(string token)
{
    bool isValid = true;
    for (int j = 0; j < token.length(); j++)
    {
        //if first index is valid
        if (j == 0 && !((token[j] >= 'a' && token[j] <= 'z') || (token[j] >= 'A' && token[j] <= 'Z') || token[j] == '_'))
        {
            isValid = false;
            break;
        }
        //check if the rest is valid
        if (!((token[j] >= 'a' && token[j] <= 'z') || (token[j] >= 'A' && token[j] <= 'Z') || (token[j] >= '0' && token[j] <= '9') || token[j] == '_'))
        {
            isValid = false;
            break;
        }
    }
    return isValid;
}

int main()
{
    string str, temp = "", result = "";
    getline(cin, str, '.');

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            if (checkValidity(temp))
                result += temp + "\n";
            temp = "";
        }
        else
        {
            temp += str[i];
        }
    }
    cout << result;
}