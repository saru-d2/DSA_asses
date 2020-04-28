#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long int lint;

vector<lint> adj[100];
lint v,e,x,y, fr;
int vis[1000];
queue<lint> q;
void bfs(lint n)
{
	cout<<n<<" ";
	q.push(n);
	vis[n] = 1;
	while(!q.empty())
	{
		fr = q.front();
		q.pop();

		for(lint i=0;i<adj[fr].size();i++)
			if (vis[adj[fr][i]] == 0)
			{
				vis[adj[fr][i]] = 1;
				q.push(adj[fr][i]);
				cout<<adj[fr][i]<<" ";
			}

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
	bfs(1);
	cout<<endl;
}
