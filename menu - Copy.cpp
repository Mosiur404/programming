#include <bits/stdc++.h>
using namespace std;

void search(int searchArray[], int numberOfItems, int searchItem)
{
    int index = -1;
    for (int i = 0; i < numberOfItems; i++)
    {
        if (searchArray[i] == searchItem)
            index = i;
    }
    //-1 means not found
    if (index == -1)
    {
        cout << "Item not found\n";
    }
    else
    {
        cout << "Item " << searchItem << " found at position " << index + 1 << "\n";
    }
}
void displayArray(int givenArray[], int arraySize)
{
    string result = "[ ";
    for (int i = 0; i < arraySize; i++)
    {
        if (i == 0)
            result += to_string(givenArray[i]);
        else
            result += ", " + to_string(givenArray[i]);
    }
    result += " ]\n";
    cout << result;
}
int main()
{
    int arraySize;
    cout << "Enter array size \n";
    cin >> arraySize;
    int itemList[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        itemList[i] = -1;
    }

    int option, userInput;
    int arrayIsFull = 0;
    while (true)
    {
        cout << "\nChoose option\n";
        cout << "(1) Add\n";
        cout << "(2) Delete\n";
        cout << "(3) Search\n";
        cout << "(4) View\n";
        cout << "(5) Exit\n";
        cin >> option;

        if (option == 1)
        {
            if (arrayIsFull == 1)
            {
                cout << "Array is full, delete an item\n";
            }
            else
            {
                //do add
                cout << "Enter item to add \n";
                cin >> userInput;
                for (int i = 0; i < arraySize; i++)
                {
                    if (itemList[i] == -1)
                    {
                        itemList[i] = userInput;
                        break;
                    }
                }
                // last item not-1 means array is full
                if (itemList[arraySize - 1] != -1)
                    arrayIsFull = 1;
            }
        }
        if (option == 2)
        {
            //do delete
            cout << "Enter item position to delete \n";
            cin >> userInput;
            userInput -= 1;
            if (userInput + 1 > arraySize || userInput < 0)
            {
                cout << "Invalid Input \n";
            }
            else if (itemList[userInput] == -1)
            {
                cout << "Already deleted \n";
            }
            else
            {
                for (int i = userInput; i < arraySize - 1; i++)
                {
                    itemList[i] = itemList[i + 1];
                }
                // lastitem is always -1 after delete
                itemList[arraySize - 1] = -1;
                displayArray(itemList, arraySize);
            }
        }
        if (option == 3)
        {
            //do search
            cout << "Enter item to search \n";
            cin >> userInput;
            search(itemList, arraySize, userInput);
        }
        if (option == 4)
        {
            //view
            displayArray(itemList, arraySize);
        }
        if (option == 5)
        {
            //exit
            cout << "Exited successfully \n";
            break;
        }
    }
}