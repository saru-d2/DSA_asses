#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;

vector<pair<pair<lint, lint>, pair<lint, lint>>> inp, e;
vector<lint> vec;
lint sz[100005], id[100005];
lint xarr[21];
lint root(lint i)
{
    if (id[i] == i)
        return i;
    return id[i] = root(id[i]);
}

lint kruskals(lint n)
{
    for (lint i = 0; i <= n; i++)
    {
        sz[i] = 1;
        id[i] = i;
    }
    lint x, y, wt, p, px, py, ret = 0, cnt = 0;
    for (auto i : e)
    {
        x = i.first.first;
        y = i.first.second;
        wt = i.second.second;
        px = root(x);
        py = root(y);

        if (px == py)
            continue;
        if (sz[px] > sz[py])
            swap(px, py); //sz(py)>sz(px)
        sz[py] += sz[px];
        id[px] = py;
        cnt++;
        // cout << wt;
        ret += wt;
    }

    if (cnt == n - 1)
        return ret;
    else
        return -1;
}

bool cmp(const pair<pair<lint, lint>, pair<lint, lint>> &a, const pair<pair<lint, lint>, pair<lint, lint>> &b)
{
    return a.second.second < b.second.second;
}

lint fast_exp(lint a, lint b)
{
    lint ret = 1;
    while (b > 0)
    {
        if (b & 1)
            ret *= a;
        b /= 2;
        a *= a;
    }
    return ret;
}
int main()
{
    lint n, m, p, c, x;
    cin >> n >> m >> x;
    lint u, v;
    for (lint i = 0; i < m; i++)
    {
        cin >> u >> v >> p >> c;
        inp.push_back(make_pair(make_pair(u, v), make_pair(p, c)));
    }
    sort(inp.begin(), inp.end(), cmp);
    lint temp = x;
    for (lint i = 0; i <= 20; i++)
    {
        xarr[i] = temp & 1;
        temp /= 2;
    }

    // for (lint i = 0; i <= 20; i++)
    //     cout << xarr[i];
    // cout << endl;

    sort(inp.begin(), inp.end(), cmp);
    lint I, ans, fin_ans = -1;
    for (lint i = 0; i <= 20; i++)
    {
        I = fast_exp(2, i);
        if ((x & I) == 0)
        {
            vec.push_back(x + I);
            // cout << x + I << " ";
        }
        // cout << endl;
    }
    for (lint i : vec)
    {
        e.clear();
        for (auto j : inp)
        {
            p = j.second.first;
            if ((i & p) > x)
            {
                // cout << i<<" "<<p <<" "<<(lint)(i&p)<< " "<<x<<endl;
                e.push_back(j);
            }
        }
        ans = kruskals(n);
        // cout<<"\t"<<ans<<endl;
        if (ans != -1)
        {
            if (fin_ans == -1)
                fin_ans = ans;
            else
                fin_ans = min(ans, fin_ans);
        }
    }
    // cout << "ans\n";
    cout << fin_ans << endl;
}