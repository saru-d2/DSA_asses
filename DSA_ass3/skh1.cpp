#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits>
using namespace std;
typedef long long int lint;
lint n, m;
lint s, t, a, b;
lint x, y, z;
lint dis[200005];
vector<pair<lint, lint>> adj[200005];
priority_queue<pair<lint, lint>> pq;
pair<lint, lint> fr;
lint nxt, d;
lint vis[200005];
lint ans = 99999999999;
lint dij_pb(lint n, lint dst)
{
    priority_queue<pair<lint, lint>> p;
    p.push(make_pair(dst, n));
    while (!p.empty())
    {
        lint bnxt = pq.top().second;
        lint bd = pq.top().first;
        pq.pop();
        for (lint i = 0; i < adj[bnxt].size(); i++)
        {
            if (adj[bnxt][i].second >= b)
                if (dis[adj[bnxt][i].first] > adj[bnxt][i].second + bd && vis[adj[bnxt][i].first] == 0)
                {
                    dis[adj[bnxt][i].first] = adj[bnxt][i].second + bd;
                    cout << adj[bnxt][i].first << " " << dis[adj[bnxt][i].first] << endl;
                    p.push(make_pair(dis[adj[bnxt][i].first], adj[bnxt][i].first));
                }
        }
    }
    return dis[t];
}

void dijkstras(lint n, lint parity)
{
    //queue has weight, node
    dis[n] = 0;
    pq.push(make_pair(0, n));
    while (!pq.empty())
    {
        fr = pq.top();
        nxt = fr.second;
        d = fr.first;
        vis[nxt] = 1;
        pq.pop();
        lint p_b = dij_pb(nxt, dis[nxt]);
        if (d + p_b < ans)
            ans = d + p_b;
        cout << "hi";
        for (lint i = 0; i < adj[nxt].size(); i++)
        {
            cout << "\t" << nxt << " " << adj[nxt][i].first << endl;
            if (adj[nxt][i].second <= a)
                if (dis[adj[nxt][i].first] > adj[nxt][i].second + d && vis[adj[nxt][i].first] == 0)
                {
                    dis[adj[nxt][i].first] = adj[nxt][i].second + d;
                    cout << adj[nxt][i].first << " " << dis[adj[nxt][i].first] << endl;
                    pq.push(make_pair(dis[adj[nxt][i].first], adj[nxt][i].first));
                }
        }
    }
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
    }
    for (lint i = 1; i <= n; i++)
        dis[i] = 99999999999;
    cin >> s >> t >> a >> b;
    cout << "in done\n";
    dijkstras(s, 0);
    for (lint i = 1; i <= n; i++)
        cout << dis[i] << " ";
    cout << endl;
    cout << ans << endl;
}