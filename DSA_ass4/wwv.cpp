#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
vector<pair<lint, pair<lint, lint>>> edges;
lint m = 0;
lint sz[100005], id[100005];

lint root(lint i)
{
    if (id[i] == i)
        return i;
    return id[i] = root(id[i]);
}
lint kruskals2(lint n, lint k)
{
    for (lint i = 1; i <= n; i++)
        id[i] = i, sz[i] = 1;

    lint x, y, wt, px, py, cnt = 0, ret = 0, c = 0;
    for (auto e : edges)
    {
        x = e.second.first;
        y = e.second.second;
        wt = e.first;
        px = root(x);
        py = root(y);

        if (px == py)
            continue;

        if (x == 1 || y == 1)
        {
            if (k == cnt)
                continue;
            cnt++;
        }

        if (sz[px] > sz[py])
            swap(px, py); // sz(py) > sz(px)

        sz[py] += sz[px];
        id[px] = py;
        ret += wt;
        c += 1;
    }
    // cout << "cnt = " << cnt << " m=" << m << endl;
    if (cnt > k)
        return -1;
    if (cnt < k)
        return -1;
    if (c != n - 1)
        return -1;
    return ret;
}

lint kruskals(lint n, lint k)
{
    for (lint i = 1; i <= n; i++)
        id[i] = i, sz[i] = 1;

    lint x, y, wt, px, py, cnt = 0, ret = 0, c = 0;
    for (auto e : edges)
    {
        x = e.second.first;
        y = e.second.second;
        wt = e.first;
        px = root(x);
        py = root(y);

        if (px == py)
            continue;

        if (x == 1 || y == 1)
        {
            cnt++;
        }

        if (sz[px] > sz[py])
            swap(px, py); // sz(py) > sz(px)

        sz[py] += sz[px];
        id[px] = py;
        ret += wt;
        c += 1;
    }
    // cout << "cnt = " << cnt << " m=" << m << endl;
    if (cnt > k)
        return -2;
    if (cnt < k)
        return -3;
    if (c != n - 1)
        return -1;
    return ret;
}

bool cmp(const pair<lint, pair<lint, lint>> &a, const pair<lint, pair<lint, lint>> &b)
{
    if ((a.second.first == 1 || a.second.second == 1) && (b.second.first == 1 || b.second.second == 1))
        return (a.first < b.first);
    if (a.second.first == 1 || a.second.second == 1)
        return (a.first - m < b.first);
    if (b.second.first == 1 || b.second.second == 1)
        return (a.first < b.first - m);
    return (a.first < b.first);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lint n, m, k;
    cin >> n >> m >> k;
    lint x, y, z;
    for (lint i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        edges.push_back({z, {x, y}});
    }
    lint b = -10000000, e = 10000000;
    lint ret, mm;
    while (b <= e)
    {
        ::m = (b + e) / 2;
        sort(edges.begin(), edges.end(), cmp);
        ret = kruskals(n, k);
        cout << b << " " << e << " " << ::m << "\t" << ret << endl;
        if (ret >= -1)
            break;
        if (ret == -2)
            mm = ::m, e = ::m - 1;
        if (ret == -3)
             b = ::m + 1;
    }

    if (ret > 0)
    {
        cout << ret << "\n";
        return 0;
    }
    
    // cout << "mm: " << mm << endl;
    ::m = mm;
    sort(edges.begin(), edges.end(), cmp);
    cout<<kruskals2(n, k)<<"\n";
}