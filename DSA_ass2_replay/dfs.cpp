#include<iostream>
#include<vector>
using namespace std;
typedef long long int lint;

vector<lint> adj[100];
lint v,e,x,y;
int vis[1000];
void dfs(lint n, lint parent)
{
	cout<<n<<" ";
	if (vis[n]==1){
		cout<<"loop detected\n";
		return;
	}
	vis[n] = 1;
	for (lint i = 0;i< adj[n].size() ; i++)
	{
		if (adj[n][i]!=parent)
			dfs(adj[n][i], n);
	}
}

int main()
{
	cin>>v>>e;
	while(e--)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout<<endl;
	dfs(1,0);

	cout<<endl;
}
