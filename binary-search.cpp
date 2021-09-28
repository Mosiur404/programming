#include <bits/stdc++.h>
using namespace std;

bool search(int searchArray[], int searchValue, int left, int right)
{
    if (left > right)
        return false;

    int mid = (left + right) / 2;

    if (searchValue == searchArray[mid])
    {
        return true;
    }
    else if (searchValue < searchArray[mid])
    {
        // go left
        return search(searchArray, searchValue, left, mid - 1);
    }
    else
    {
        // go right
        return search(searchArray, searchValue, mid + 1, right);
    }
}

int main()
{
    int numberOfItems;
    cout << "Number of Items ";
    cin >> numberOfItems;
    cout << "Items\n";
    int arr[numberOfItems];

    for (int i = 0; i < numberOfItems; i++)
        cin >> arr[i];

    int find;
    cout << "Item to search ";
    cin >> find;

    int left = 0;
    bool result = search(arr, find, left, numberOfItems);
    string found = (result) ? "Yes" : "No";

    cout << "Item found: " << found;
}