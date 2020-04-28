#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long int lint;
lint vis[200005];
vector<pair<int, int> > adj[200005];
lint n, m, x, y, z, cnt = 0, pairs = 0, tot = 0, thresh, ans;
lint b = 0, mid;
lint e = 0;
void dfs(lint n, lint cost)
{
    cnt += 1;
    tot += 1;
    vis[n] = 1;
    for (lint i = 0; i < adj[n].size(); i++)
    {
       // cout<<"in dfs's for loop"<<endl;
        if (vis[adj[n][i].first] == 0 && adj[n][i].second <= cost)
            dfs(adj[n][i].first, cost);
    }
}

int main()
{
    cin >> n >> m;
    for (lint i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
        e = max(e, z);
    }
    cin >> thresh;
    // cout<<"hi";
    // cout<< thresh;

    // binary_search
    // cout << "hi before loop";
    e++;
    while (b < e)
    {
        // cout << "hi";
        for (lint i = 1; i <= n; i++)
            vis[i] = 0;
        cnt = 0;
        pairs = 0;
        tot = 0;
        mid = (lint)(b + e) / 2;
        // cout << "\nmid " << mid << endl;
        if (b == e)
        {
            // cout << "hi " << mid << endl;
            break;
        }
        // cout << b << " " << mid << " " << e << endl;
        for (int i = 1; i <= n; i++)
        {
            cnt = 0;
          //  cout<<"i: "<<i<<" "<<"vis[i]: "<<vis[i]<<endl;
            if (vis[i] == 0)
            {
                dfs(i, mid);
              //  cout << "tot: " << tot << " "
               //      << "cnt: " << cnt << endl;
                pairs += cnt * (n - tot);
            }
        }
        // cout << mid << " " << pairs << endl;
        // cout << "\t" << pairs << endl;
        if (pairs <= thresh)
        {
            e = mid;
            ans= mid;
        }
        else
        {
            b = mid + 1;
        }
    }
    cout << ans << endl;
}
