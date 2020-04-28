#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long int lint;
lint t, n, x;
lint a[200004]; /// 1 based indexing
lint ans[200004];
lint vis[200004];
stack<lint> stk;
vector<lint> adj[200004];
lint flag[200004];
lint in_cycle=0, cyc_start;

void dfs(lint n)
{
	vis[adj[n][0]] = 1;
	dfs(adj[n][0]);
	
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for (lint i=1;i<=n;i++)
		{
			cin >> x;
			adj[i].push_back(x);
		}

		for (lint i=1;i<=n;i++)
		{
			if (vis[n] == 0)
				dfs(i);
		}

	}
}
