#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long int lint;

vector<pair<lint, lint> > adj[200005];
lint vis[200005], a[200005], ans = 0;

bool cmp_fn(const pair<lint, lint> &a, const pair<lint, lint> &b)
{
    if (a.second == b.second)
        return (a.first < b.first);
    else
        return (a.second < b.second);
}

lint uppr_bin(pair<lint, lint> rng, lint n)
{

    lint b = rng.first;
    lint e = rng.second + 1;
    lint mid;
    while (b <= e)
    {
        mid = (b + e) / 2;

        if (b == e)
            break;
        if (a[mid] > n)
        {
            e = mid;
        }
        else
        {
            b = mid + 1;
        }
    }
    return mid;
}

void bfs(lint n, pair<lint, lint> rng)
{
    lint lb = -1, rb = -1;
    queue<pair<lint, pair<lint, lint> > > q;
    vis[n] = 1;
    q.push(make_pair(n, make_pair(rng.first, rng.second)));
    while (!q.empty())
    {
        pair<lint, pair<lint, lint>> fr = q.front();
        q.pop();
        sort(adj[fr.first].begin(), adj[fr.first].end(), cmp_fn);

        if (adj[fr.first].size() == 1 && vis[adj[fr.first][0].first] == 1)
        {
            ans += (fr.second.second - fr.second.first + 1) * fr.first;
            continue;
        }
        for (lint i = adj[fr.first].size() - 1; i >= 0; i--)
        {
            if (vis[adj[fr.first][i].first] == 1)
                continue;
            if (lb == -1)
            {
                rb = fr.second.second;
            }
            else
                rb = lb - 1;
            lb = uppr_bin(fr.second, adj[fr.first][i].second);
            if (lb > fr.second.second)
                continue;

            if (vis[adj[fr.first][i].first] == 0)
            {
                q.push(make_pair(adj[fr.first][i].first, make_pair(lb, rb)));
                vis[adj[fr.first][i].first] = 1;
            }
        }
        if (lb != -1)
            ans += (lb - fr.second.first) * fr.first;
        lb = rb = -1;
    }
}

int main()
{
    lint n, q, x, y, z;
    cin >> n >> q;
    for (lint i = 0; i < n - 1; i++)
    {
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
    }
    for (lint i = 0; i < q; i++)
    {
		cin >> a[i];
    }
    sort(a, a + q);

    pair<lint, lint> rng(make_pair(0, q - 1));
    if (n==1)
    {
        for(lint i=0;i<q;i++)
        ans+= 1;
    }
    bfs(1, rng);
    cout << ans << endl;
}
