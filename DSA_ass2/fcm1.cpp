#include<iostream>
using namespace std;

int main()
{
    long long int n,m,x,y,in;
    long long int ctr[200001]={0},ans[200001]={0};
    bool chk[1004][1004]={0};
    cin>>n>>m;
    long long int a[200001]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int maxi=0;
    for(int i=0;i<m;i++)
    {
        //cout<<"hi "<<a[x-1]<<" "<<a[y-1]<<" "<<chk[a[x-1]][a[y-1]]<<endl;
        cin>>x>>y;
        if (a[x-1]!=a[y-1] && chk[a[x-1]][a[y-1]]+chk[a[y-1]][a[x-1]]==0)
        {
        //cout<<a[x-1]<<" "<<a[y-1]<<" "<<chk[a[x-1]][a[y-1]]<<endl<<endl;
        chk[a[x-1]][a[y-1]]=1;
        chk[a[y-1]][a[x-1]]=1;
        ctr[x-1]++;
        ctr[y-1]++;
        }      
        if (x>maxi)
        maxi=x;
        if (y>maxi)
        maxi=y;  
    }

   for (int i=0 ;i<m;i++)
    cout<<ctr[i]<<"\t";
    cout<<endl;

    /*for(int i=0;i<m;i++)
    {
       // cout<<ctr[i]<<"\t";
        if (flag[i]==0)
        for(int j=i+1;j<m;j++)
        {
            flag[i]=1;
            if (a[i]==a[j])
            ctr[i]+=ctr[j];
        }
    }*/
    
    for(long long int i=0;i<=maxi;i++)
    {
        ans[a[i]]+=ctr[i];
    }

    long long int max=-1;
    //cout<<endl;
    for(int i=1;i<=maxi;i++)
    {
        cout<<ans[i]<<"\t";
        if (ans[i]>max )
        {
           // cout<<"hi"<<ans[i]<<endl;
            max = ans[i];
            in =i;

        }
        if (ans[i]==max)
        {
            if (a[i]<a[in])
            max=ans[i];
            in =i;
        }

    }
    cout<<endl;
    cout<<a[in-1]<<endl;




}