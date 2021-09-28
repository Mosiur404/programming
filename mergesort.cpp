#include <bits/stdc++.h>
using namespace std;
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

void mergeSort(int low, int high, int arr[])
{
    if (low < high)
    {

        cout << arr[low] << "+" << arr[high] << "\n";
    }
}

int main()
{
    cout << "Number of items:";
    int numberOfItems;
    cin >> numberOfItems;
    int arr[numberOfItems];

    for (int i = 0; i < numberOfItems; i++)
    {
        cin >> arr[i];
    }

    displayArray(arr, numberOfItems);

    mergeSort(0, numberOfItems - 1, arr);
}
