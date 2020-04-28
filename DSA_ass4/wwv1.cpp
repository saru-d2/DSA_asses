#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;

vector<pair<lint, pair<lint, lint>>> c1, nc1;
int id[6000], sz[6000];

lint root(lint i)
{
    if (id[i] == i)
        return i ;
    return id[i] = root(id[i]);
}

lint kruskals(lint n, vector<pair<lint, pair<lint, lint>>> edges, lint limit)
{
    for (lint i = 1; i <= n; i++)
        id[i] = i, sz[i] = 1;

    lint x, y, wt, px, py, ret =0, cnt = 0;
    px = root(x), py = root(y);

    for (auto p: edges)
    {
        if (cnt == limit)
            break;
            
        x = p.second.first;
        y = p.second.second;
        wt = p.first;
        px = root(x);
        py = root(y);

        if (px == py)
            continue;
        
        if (sz[px] > sz[py])
            swap(px, py);   //sz(py) > sz(px)
        
        id[px] = py;
        sz[py]+=px;
        ret += wt;
        cnt+=1;
    }
    
}

int main()
{
    lint n, m, k;
    cin >> n >> m >> k;
    lint x, y, wt;
    for (lint i = 0; i < m; i++)
    {
        cin >> x >> y >> wt;
        if (x == 1 || y == 1)
            c1.push_back(make_pair(wt, make_pair(x, y)));
        else
            nc1.push_back(make_pair(wt, make_pair(x, y)));
    }

    sort(c1.begin(), c1.end());
    sort(nc1.begin(), nc1.end());

    kruskals(n, nc1, n-1-k)
}