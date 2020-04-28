#include<iostream>
#include<vector>
#include<utility>
using namespace std;
typedef long long int lint;
lint n, a[200004],x,y,z,mod = 1000000007, answer=0;
vector<pair<lint,lint> > adj[200004];
lint dp0[200004],  dp1[200004]; 
lint cnt[2]={0};
lint ans[2][200004];

void dfs(lint n, lint parent, lint parity, lint dp[], lint weight)
{
//	if (vis[n] != 0 )
//		return;
//	cout<<"\t"<<n<<" "<<parent<<" "<<parity<<" "<<weight<<" "<<endl;
	if (a[n] == parity)
		dp[n]+=1;
	for(lint i=0;i<adj[n].size();i++)
	{
		if(adj[n][i].first!= parent)
		{
//			cout<<"\t\t"<<adj[n][i].first<<" "<<n<<" "<<parity<<" "<<adj[n][i].second<<endl;
			dfs(adj[n][i].first, n, parity, dp, adj[n][i].second);
			dp[n]+=dp[adj[n][i].first];

		}
	}

	ans[parity][n] += (weight * (cnt[parity]-dp[n]) * dp[n])%mod;

}




int main()
{
	cin>>n;

	for(lint i=0;i<n;i++)
	{
		cin >> a[i];
		if (a[i]==0)
			cnt[0]++;
		else
			cnt[1]++;
	}

	for(lint i=1;i<n;i++)
	{
		cin>>x>>y>>z;
		adj[x].push_back(make_pair(y,z));
		adj[y].push_back(make_pair(x,z));
	}

	dfs( 0, 0, 0, dp0,0);
	dfs( 0, 0, 1, dp1,0);

/*
	for(lint i=0;i<n;i++)
	{
		cout<<dp0[i]<<" ";
	}
	cout<<endl;
	for (lint i=0;i<n;i++)
	{
		cout<<dp1[i]<<" ";
	}
	cout<<endl;
*/
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<=n;j++)
		{
//			cout<<ans[i][j]<<" ";
			answer+=ans[i][j]%mod;
			answer%=mod;
		}
//		cout<<endl;
	}

	cout<<answer%mod<<endl;


}


