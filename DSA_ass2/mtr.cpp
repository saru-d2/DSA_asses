#include <iostream>
#include <stack>
#include <deque>
using namespace std;
typedef long long int lint;
lint n, a[200005], b[200005], ans = 0;
deque<lint> dq;

void traverse(deque<lint> dq)
{
    //cout << "tra ";
    while (!dq.empty())
    {
        //cout << dq.front() << "  ";
        dq.pop_front();
    }
    cout << endl;
}
int main()
{
    cin >> n;

    for (lint i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lint i = 0; i < n; i++)
    {
        cin >> b[i];
        // cout<<"cunt";
    }
    //cout << n << endl;
    //cout<<"hi\n";
    lint i = 0;
    while (i < n)
    {
        //traverse(dq);
        //cout << "i: " << i << "\n";

        

        while (!dq.empty() && dq.front() > a[i])
        {

            dq.pop_front();
        }

        while (!dq.empty() && dq.back() < b[i])
        {
            dq.pop_back();
        }
        if (a[i] == b[i])
        {
            i++;
            //cout << "AAAA\n";
            continue;
        }

        if (!dq.empty() && dq.back() == b[i])
        {
            //cout << "OOOOO " << i << endl;
            i++;
            continue;
        }

        //cout << "\t" << b[i] << "\n";
        dq.push_back(b[i]);
        ans++;
        i++;
        //cout << "ans: " << ans << "\n";

        //cout << " hola\n";
    }
    //cout << "done\n";
    cout << ans << endl;
}