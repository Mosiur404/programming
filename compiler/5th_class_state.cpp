#include <iostream>
#include <regex>
using namespace std;

//start state
string state = "state_0";

void state_0(char character)
{
    switch (character)
    {
    case '\0':
        state = "state_1";
        break;
    case 'a':
        state = "state_1";
        break;
    default:
        break;
    }
}

void state_1(char character)
{
    switch (character)
    {
    case '\0':
        break;
    case 'a':
        break;
    default:
        state = "state_0";
        break;
    }
}
int main()
{

    string input;
    // getline(cin, input, ';');
    input = "aaa";
    if (input.length() == 0)
        state = "state_1";
    else
        for (int i = 0; i < input.length(); i++)
        {
            if (state == "state_0")
                state_0(input[i]);
            else if (state == "state_1")
                state_1(input[i]);
        }

    cout << (state == "state_1" ? "\naccpeted \n" : "\nrejected \n");
}