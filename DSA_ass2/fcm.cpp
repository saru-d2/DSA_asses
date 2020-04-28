#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int lint;
int main()
{
    lint n, m, x, y;
    cin>>n>>m;
    lint a[100004]={0};

    vector<int> graph[100001];
    //gay array

    for(lint i=0;i<n;i++)
    cin>>a[i];
    //cout<<"sos "<<a[0];

    for(lint i=0;i<m; i++)
    {
        cin>>x>>y;
       // cout<<x<<y;
        if (binary_search(graph[a[x-1]].begin(), graph[a[x-1]].end(), a[y-1]) == 0 
            && a[x-1]!=a[y-1])
        {
          //  cout<<a[x-1]<<"\t"<<a[y-1];
          //  cout<<"hi";
            //insert into right place u fucking retard
            graph[a[x-1]].push_back(a[y-1]);
           // cout<<"cunt "<<graph[a[x-1]].size()<<endl;
            sort(graph[a[x-1]].begin(),graph[a[x-1]].end());
            graph[a[y-1]].push_back(a[x-1]);
           // cout<<"cunt2 "<<graph[a[y-1]].size()<<endl;
            sort(graph[a[y-1]].begin(),graph[a[y-1]].end());
        }

    }
    lint max =0;
    //cout<<"gey "<<graph[a[max]].size()<<endl; 
    for(int i=0;i<100004;i++)        
    {
       // cout<<graph[a[i]].size()<<endl;
        if (graph[a[i]].size() > graph[a[max]].size())
        {
           // cout<<"lesbo "<<i<<endl;
            max=i;
        }
        else if (graph[a[i]].size()== graph[a[max]].size())
        {
            if (a[i]<a[max] && a[i]>0)
            {
               // cout<<"CUNT "<<a[i]<<endl;
                max=i;
            }
        }
       

    }
    //cout<<max;
    cout<<a[max]<<endl;
}