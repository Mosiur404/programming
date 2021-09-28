// Write a program to Find number of spaces from input stream
// Sample input: CSE_412 Compiler Sessional\n#name : Mosiur Rahman\nID : CSE 01706527
// Sample output: 2

#include <iostream>
#include <regex>
using namespace std;

int main()
{

    string input;
    getline(cin, input, ';');
    int counter;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
            counter++;
    }
    cout << "Number of spaces: " << counter;
}