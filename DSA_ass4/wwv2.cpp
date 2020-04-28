#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;

vector<pair<pair<lint, lint>, pair<lint, lint>>> edges;
lint id[100005], sz[100005];

lint root(lint i)
{
    if (id[i] == i)
        return i;
    return id[i] = root(id[i]);
}

pair<lint, lint> kruskals(lint n, lint k)
{
    for (lint i = 0; i <= n; i++)
        id[i] = i, sz[i] = 1;

    lint x, y, wt, px, py, c1 = 0, cnt = 0, ret = 0, last_wt;
    for (auto p : edges)
    {
        x = p.first.first;
        y = p.first.second;
        wt = p.second.first;

        px = root(x);
        py = root(y);

        if (px == py)
            continue;
        if (x == 1 || y == 1)
            c1++;

        if (sz[px] > sz[py])
            swap(px, py); //sz(py)>sz(px)
        if (x!=1 && y!=1)
            last_wt = wt;
        sz[py] += sz[px];
        id[px] = py;
        cnt++;
        ret += wt;
    }
    if (c1 < k)
        return {-2, last_wt};
    if (c1 > k)
        return {-3, last_wt};
    if (cnt <= n - 1)
        return {-1, last_wt};
    return {ret, last_wt};
}

bool cmp(const pair<pair<lint, lint>, pair<lint, lint>> &a, const pair<pair<lint, lint>, pair<lint, lint>> &b)
{
    return a.second.second < b.second.second;
}

int main()
{
    lint n, m, k;
    cin >> n >> m >> k;
    lint x, y, z;
    for (lint i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        // if (x ==1 || y == 1)
        edges.push_back(make_pair(make_pair(x, y), make_pair(z, z)));
    }

    sort(edges.begin(), edges.end(), cmp);
    pair<lint, lint> l;
    l = kruskals(n, k);
    
    if (l.first == -1)
    {
        cout << "-1\n";
        return 0;
    }

    if 

}