#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
lint n, m, x, y, z;
int flag[2000], flag2[2000];
vector<pair<lint, pair<lint, lint>>> edges;
pair<lint, lint> dis[1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lint t;
    cin >> t;
    while (t--)
    {
        while (!edges.empty())
            edges.pop_back();

        cin >> n >> m;
        for (lint i = 1; i <= n; i++)
            dis[i].first = 0, dis[i].second = 0, flag[i] = 0, flag2[i] = 0;

        while (m--)
        {
            cin >> x >> y >> z;
            edges.push_back(make_pair(z, make_pair(x, y)));
        }

        for (lint i = 0; i < n; i++)
        {
            // for (lint i = 1; i <= n; i++)
            //     cout << "(" << dis[i].first << "," << dis[i].second << ") ";
            // cout << endl;
            for (auto p : edges)
            {
                x = p.second.first;
                y = p.second.second;
                z = p.first;
                //dis[i].first is dis *till* that pt, second is dis *frm* that pt
                if (dis[y].first > dis[x].first + z)
                {
                    dis[y].first = dis[x].first + z;
                }
                if (dis[x].second > dis[y].second + z)
                {
                    dis[x].second = dis[y].second + z;
                }
            }
        }

        // for (lint i = 0; i < n; i++)
        for (auto p : edges)
        {
            x = p.second.first;
            y = p.second.second;
            z = p.first;
            //dis[i].first is dis *till* that pt, second is dis *frm* that pt
            if (dis[y].first > dis[x].first + z)
            {
                flag[y] = 1;
                // flag[x] = 1;
                dis[y].first = dis[x].first + z;
            }
            if (dis[x].second > dis[y].second + z)
            {
                flag2[x] = 1;
                // flag[y] = 1;
                dis[x].second = dis[y].second + z;
            }
        }

        for (lint i = 0; i <= n; i++)
            cout << flag[i] << "," << flag2[i] << " ";
        cout << endl;
        int chg = 0;
        for (lint i = 1; i <= n; i++)
        {
            chg = 0;
            for (auto p : edges)
            {
                x = p.second.first;
                y = p.second.second;
                z = p.first;
                if ((flag[x] == 0 && flag2[y] == 1) || (flag[y] == 0 && flag2[x] == 0))
                {
                    // cout<<x<<" "<<y<<endl;
                    flag[x] = 1;
                    flag2[y] = 1;
                    chg = 1;
                }
            }
            if (chg == 0)
                break;
        }
        // for (lint i = 0; i <= n; i++)
        //     cout << flag[i] << "," << flag2[i] << " ";
        // cout << endl;

        // for (lint i = 1; i <= n; i++)
        //     cout << "(" << dis[i].first << "," << dis[i].second << "," << flag[i] << ") ";
        // cout << endl;
        for (lint i = 1; i <= n; i++)
        {
            if (flag[i] != 0 || flag2[i] != 0)
                cout << "INF\n";
            else
                cout << dis[i].first + dis[i].second << endl;
        }
    }
}
