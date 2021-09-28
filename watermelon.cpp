#include <bits/stdc++.h>
using namespace std;

int main()
{
    int W;
    cin >> W;
    float temp = W % 2;
    if (temp == 0 && W / 2 >= 2)
    {
        if (((W - 1) / 2) % 2 == 0 || (W / 2) % 2 == 0)
        {
            cout << "YES";
        }
    }
    else
    {
        cout << "NO";
    }
}
