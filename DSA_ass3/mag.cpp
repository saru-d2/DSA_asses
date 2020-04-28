using namespace std;
#include <bits/stdc++.h>
typedef long long lint;
lint n, m, g;
lint x, y, z;
vector<pair<lint, lint>> adj[100005];
vector<lint> gf;
lint ans = -1, ans2 = -1;
lint dij(vector<lint> N)
{
    priority_queue<pair<lint, lint>, vector<pair<lint, lint>>, greater<pair<lint, lint> > > pq;
    lint dis[100005], dis2[100005], fr, d, vis[100005]={0};

    for (lint i = 0; i < n; i++)
        dis2[i] = (lint)1e15, dis[i] = (lint)1e15;

    for (lint i = 0; i < N.size(); i++)
    {
        pq.push(make_pair(0, N[i]));
        dis2[N[i]] = 0;
        dis[N[i]] = 0;
        // vis[N[i]] = 1;
    }

    while (!pq.empty())
    {
        fr = pq.top().second;
        d = pq.top().first;
        pq.pop();
        if (vis[fr])
            continue;
        // cout<<fr<<" "<<d<<endl;
        for (auto p : adj[fr])
        {
            // cout << "\t" << p.first << " "<<dis[p.first]<<" "<<p.second<<endl;

            if(d==(lint)1e15){
                // cout<<"hi";
            }
            else if (dis[p.first] > d + p.second)
            {
                // cout<<p.first<<endl;
                dis2[p.first] = dis[p.first];
                dis[p.first] = d + p.second;
                pq.push(make_pair(dis2[p.first], p.first));
            }
            else if (dis2[p.first] > d + p.second)
            {
                // cout<<"hi "<<p.first<<endl;
                dis2[p.first] = d + p.second;
                pq.push(make_pair(dis2[p.first], p.first));
            }
        }
        vis[fr] = 1;
    }
    // cout<<dis[0]<<" "<<dis2[0]<<endl;
    return dis2[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

    ans = dij(gf);
    if (ans == (lint)1e15 )
        ans = -1;
    cout << ans << endl;
}