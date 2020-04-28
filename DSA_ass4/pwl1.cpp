#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;

lint n, m, x, u, v, p, c, sz[100005], id[100005];
vector<pair<pair<lint, lint>, pair<lint, lint>>> inp, e;

lint root(lint i)
{
    if (id[i] == i)
        return i;
    return id[i] = root(id[i]);
}

lint kruskals()
{
    for (lint i = 0; i <= n; i++)
    {
        sz[i] = 1;
        id[i] = i;
    }
    lint x, y, wt, px, py, cnt = 0, ret = 0, p, a = 0;
    for (auto i : e)
    {
        x = i.first.first;
        y = i.first.second;
        wt = i.second.second;
        px = root(x);
        py = root(y);
        p = i.second.first;
        if (px == py)
            continue;

        if (sz[px] > sz[py])
            swap(px, py); //sz[py]>sz[px]
        cnt++;
        ret += wt;
        if (a == 0)
            a = p;
        else
            a &= p;
        id[px] = py;
        sz[py] += wt;
    }
    if (cnt == n - 1 && ::x < a)
        return ret;
    else
        return -1;
}

bool cmp(const pair<pair<lint, lint>, pair<lint, lint>> &a, const pair<pair<lint, lint>, pair<lint, lint>> &b)
{
    return a.second.second < b.second.second;
}

int main()
{
    cin >> n >> m >> x;
    for (lint i = 0; i < m; i++)
    {
        cin >> u >> v >> p >> c;
        inp.push_back(make_pair(make_pair(u, v), make_pair(p, c)));
    }
    lint I;
    sort(inp.begin(), inp.end(), cmp);

    // for (auto i : inp)
    //     cout << i.second.second << " ";
    // cout << endl;

    lint ans, fin_ans = -1;
    for (lint i = 0; i <= 20; i++)
    {
        // cout << "\n"
        //      << i << "\t";

        e.clear();
        for (auto j : inp)
        {
            p = j.second.first;
            if (p >> i & 1)
            {
                e.push_back(j);
                // cout<<p<<" ";
            }
        }

        ans = kruskals();
        if (ans != -1)
        {
            if (fin_ans == -1)
                fin_ans = ans;
            else
                fin_ans = min(ans, fin_ans);
        }
    }
    cout << fin_ans << endl;
}