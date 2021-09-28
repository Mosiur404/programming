#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l;
    cin >> n;
    string W[n];

    for (int i = 0; i < n; i++)
    {
        cin >> W[i];
    }

    for (int i = 0; i < n; i++)
    {
        l = W[i].length();
        if (l > 10)
        {
            cout << W[i][0] << l - 2 << W[i][l - 1] << endl;
        }
        else
            cout << W[i] << endl;
    }
}
