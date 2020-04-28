#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
lint n, m, g;
lint x, y, z;
vector<pair<lint, lint>> adj[100005];
vector<lint> gf;
lint ans = -1, ans2 = -1;
void dij(vector<lint> N)
{
    priority_queue<pair<lint, lint>> pq;
    lint dis[100005], dis2[100005], fr, d;
    for (lint i = 0; i < n; i++)
        dis2[i], dis[i] = (lint)1e15;
    for (lint i = 0; i < N.size(); i++)
    {
        pq.push(make_pair(0, N[i]));
        dis2[N[i]] = dis[N[i]] = 0;
    }

    while (!pq.empty())
    {
        fr = pq.top().second;
        d = pq.top().first;
        pq.pop();
        // cout<<fr<<" "<<d<<endl;
        for (auto p : adj[fr])
        {
            // cout << "\t" << p.first << " "<<dis[p.first]<<" "<<p.second<<endl;
            if (dis[p.first] > d + p.second)
            {
                dis[p.first] = d + p.second;
                pq.push(make_pair(dis[p.first], p.first));
            }
        }
        if (dis[0] != (lint)1e15)
        {
            if (ans == -1)
                ans = dis[0];
            else if (ans > dis[0])
            {
                ans2 = ans;
                ans = dis[0];
            }
            else if (ans2 > dis[0])
                ans2 = dis[0];
        }
    }

    // cout<<ans<<" "<<ans2<<endl;
}

int main()
{
    cin >> n >> m >> g;
    while (m--)
    {
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
    }
    lint h;
    for (lint i = 0; i < g; i++)
    {

        cin >> h;
        gf.push_back(h);
    }
    dij(gf);
    cout << ans2 << endl;
}