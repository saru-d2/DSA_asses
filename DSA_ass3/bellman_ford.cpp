#include <bits/stdc++.h>
using namespace std;
int n, m, s, x, y, z, INF = 10000000, dis[10000];
vector<pair<int, pair<int, int>>> edges;
int main()
{
    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y >> z;
        edges.push_back(make_pair(z, make_pair(x, y)));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    cin >> s;
    dis[s] = 0;
    for (int i = 0; i < n; i++)
        for (auto p : edges)
        {
            //cout<<dis[1]<<" "<<dis[2]<<" "<<dis[3]<<endl;
            x = p.second.first;
            y = p.second.second;
            z = p.first;
            if (dis[y] > dis[x] + z)
                dis[y] = dis[x] + z;
        }
    int flag = 0;
    for (auto p : edges)
    {
        x = p.second.first;
        y = p.second.second;
        z = p.first;
        if (dis[y] > dis[x] + z)
        {
            flag += 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "neg cyc" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] <<" ";
        cout<<endl;
}