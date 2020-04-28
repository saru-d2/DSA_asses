#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long int lint;
lint n, ans = 0, n1 = 0, n0 = 0, a[100005];
lint mod = 1000000007;
int par[3];
lint vis0[200005];
lint vis1[200005];

vector<pair<int, int>> adj[200005];

void dfs(lint n, lint parent, lint dp[], int parity, lint weight, lint ans[], lint vis[])
{
    //cout<<n<<endl;
    if (vis[n]!=0)
        return;
    if (a[n] == parity)
    {
       // cout<<n<<endl;
        dp[n] = 1;
    }
    for (lint i = 0; i < adj[n].size(); i++)
    {
        if (adj[n][i].first != parent)
        {

            dfs(adj[n][i].first, n, dp, parity, adj[n][i].second, ans,vis);
            // if (vis[n]==0)
                dp[n] += dp[adj[n][i].first];
      //      cout << "\t" << n << " " << adj[n][i].first<< " "<<adj[n][i].second << " " << dp[n] << "\n";
        }
    }
    ans[n] += weight*(dp[n])*(par[parity]-dp[n])%mod;
}

int main()
{
    cin >> n;
    lint x, y, z;
    

    for (lint i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            par[0]++;
        else
            par[1]++;
    }
    //cout<<par[0]<<"\t"<<par[1]<<endl;
    for (lint i = 0; i < n - 1; i++)
    {
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
       
    }

    

    lint dp0[100005] = {0};
    lint ans0[100005] = {0};
    lint ans1[100005] = {0};
    dfs(0, 0, dp0, 0, 0,ans0,vis0);
    // for (lint i = 0; i < n ; i++)
    // {
    //     cout << dp0[i] << " ";

    // }
   //cout << "\n";
    for (lint i = 0; i < n ; i++)
    {
      //  cout << ans0[i] << " ";
        ans+=ans0[i]%mod;

    }
    //cout << "\n";

    lint dp1[100005] = {0};
    dfs(0, -1, dp1, 1, 0,ans1,vis1);
    // for (lint i = 0; i < n ; i++)
    // {
    //     cout << dp1[i] << " ";
    // }
    //cout << "\n";
    for (lint i = 0; i < n ; i++)
    {
      //  cout << ans1[i] << " ";
        ans+=ans1[i]%mod;
    }
    //cout << "\n";

    

    cout << ans%mod << endl;
}