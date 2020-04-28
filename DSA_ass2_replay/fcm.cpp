#include<iostream>
#include<stack>
#include<vector>
using namespace std;
typedef long long int lint;
lint n,l,x,y, m=-1, max_c =100004;
vector<lint> adj[200004];
lint a[200004]={0}, ans[200004]={0};
int main()
{
	cin>>n>>l;
	for (lint i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]<max_c)
			max_c = a[i];
	}

	for (lint j=0;j<l;j++)
	{
		lint flag =0;
		cin>>x>>y;
	//			cout<<x<<" "<<y<<" "<<a[x]<<" "<<a[y]<<endl;

		for (lint i=0;i<adj[a[x]].size();i++)
		{
			if (adj[a[x]][i]==a[y])
			{
				flag=1;

			}
		}
		if (a[x] == a[y])
		{
			flag =1;
		}

		if (flag==0)
		{
	//		cout<<x<<" "<<y<<" "<<a[x]<<" "<<a[y]<<endl;
			adj[a[x]].push_back(a[y]);
			adj[a[y]].push_back(a[x]);
			ans[a[x]]++;
			ans[a[y]]++;
			if (ans[a[x]]>m )
			{
				m = ans[a[x]];
				max_c = a[x];
			}
			else if (ans[a[x]] == m && a[x]<max_c)
			{
				max_c = a[x];
			}
			if (ans[a[y]]>m )
			{
				m = ans[a[y]];
				max_c = a[y];
			}
			else if (ans[a[y]] == m && a[y]<max_c)
			{
				max_c = a[y];
			}



		}
	}
	/*
	   for(lint i=1;i<=10;i++)
	   {
	   cout<<ans[i]<<" ";
	   }

	   cout<<"\n";
	   */

	cout<<max_c<<endl;


}
