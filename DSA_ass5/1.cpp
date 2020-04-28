#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
int main()
{
    srand(time(NULL));
    lint n, q;
    cin >> n >> q;
    cout << n << " " << q << endl;
    for (lint i = 0; i < n; i++)
        cout << (rand() % (2 ^ 30) + 1) << " ";
    cout << endl;
    while (q--)
    {
        lint k = (rand() % 2) + 1;
        cout << k << " ";
        if (k == 2)
        {
            lint x = (rand() % n) + 1;
            lint y = (rand() % (2 ^ 30)) + 1;
            cout << x << " " << y << " "
                 << "\n";
        }
        else
        {
            lint x = (rand() % n);
            cout << x << "\n";
        }
    }
}