#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define lint long long int
using namespace std;

vector<vector<lint>> frends;

lint func(lint n, lint x)
{
    // cout << "n: " << n << endl;
    lint ret = 0;
    lint cnt = 0;
    vector<lint> v, r;
    for (auto i : frends)
    {
        int c = 0;
        while (i.size() - c > n)
        {
            v.push_back(i[c]);
            c++;
        }
        while (c < i.size())
        {
            r.push_back(i[c]);
            c++;
        }
    }
    // cout << "hi " << endl;
    sort(r.begin(), r.end());
    // cout << "szie: " << v.size() << endl;
    for (auto i : v)
        ret += i;
    // cout << endl;
    int i = 0;
    // cout << "ret: " << ret << endl;
    while (!r.empty() && (x + cnt + v.size() <= n))
    {
        // cout << "hi " << r[i] << endl;
        ret += r[i];
        i++;
        cnt++;
        // cout<<"ret :- "<<ret<<endl;
    }
    // cout << endl;
    // cout << ret << " " << cnt << endl;
    return ret;
}

int main()
{
    lint x, n, max_inp = -1;
    vector<lint> ans;
    cin >> x;
    cin >> n;
    for (lint i = 0; i < n; i++)
    {
        lint c, j;
        cin >> c;
        vector<lint> a;
        while (c--)
        {
            cin >> j;
            a.push_back(j);
        }
        sort(a.begin(), a.end());
        max_inp = max(max_inp, (lint)a.size());
        frends.push_back(a);
    }

    lint l = x, r = max_inp, mid1, mid2;

    // while (l < r)
    // {
    //     bool b = false;
    //     lint mid = (l + r) / 2;
    //     lint f1 = func(mid, x), f2 = func(mid + 1, x);
    //     if (f1  f2)
    //         r = mid, ans.push_back(f2);
    //     else
    //         l = mid + 1, ans.push_back(f1);
    // }

    while (r-l > 2)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        // cout<<l<< " " <<r<< " "<<mid1<<" "<<mid2<<endl;
        lint f1 = func(mid1, x), f2 = func(mid2, x);
        if (f1 < f2)
            r = mid2;
        else
            l = mid1;
        // cout<<"\t"<<f1<<" "<<f2<<endl;
    }

    for (lint i = l; i<= r; i++)
    {
        ans.push_back(func(i, x));
    }

    if (ans.size() == 0)
    {
        cout << "0" << endl;
        return 0;
    }

    lint fin = ans[0];
    for (auto i : ans)
        fin = min(fin, i);
    cout << fin << endl;
}