#include <iostream>
#include <regex>
using namespace std;

//start state
string state = "state_0", finalState = "state_3", dummyState = "state_4";

void state_0(char character)
{
    switch (character)
    {
    case 'a':
        state = "state_1";
        break;
    default:
        state = dummyState;
        break;
    }
}

void state_1(char character)
{
    switch (character)
    {
    case 'b':
        state = "state_2";
        break;
    default:
        state = dummyState;
        break;
    }
}

void state_2(char character)
{
    switch (character)
    {
    case 'b':
        state = "state_3";
        break;
    default:
        state = dummyState;
        break;
    }
}
void state_3(char character)
{
    state = dummyState;
}

int main()
{
    string input;
    cin >> input;

    int currentlyReading = 0, totalChar = input.length();
    do
    {
        if (state == "state_0")
            state_0(input[currentlyReading]);
        else if (state == "state_1")
            state_1(input[currentlyReading]);
        else if (state == "state_2")
            state_2(input[currentlyReading]);
        else if (state == "state_3")
            state_3(input[currentlyReading]);
        else if (state == dummyState)
            break;

        currentlyReading++;
    } while (currentlyReading < totalChar);

    cout << "\nInput: " << ((input == "") ? "λ" : input) << '\n';
    cout << "For (abb) Output: ";
    cout << (state == finalState ? "Accpeted" : "Rejected");
}