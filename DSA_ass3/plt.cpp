#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
vector<pair<lint, pair<lint, lint> > > edges;

lint x, y, px, py, m, k, id[200005], sz[200005], ans =0, cnt =0;

lint root(lint n)
{
    while(id[n]!=n)
    {
        n = id[n];
    }
    return n;
}


lint min_xor(vector<lint> a, vector<lint> b)
{
    lint ret = -1;
    for (lint i = 0; i < a.size(); i++)
    {
        for (lint j = 0; j < b.size(); j++)
        {
            // cout<<"\t"<<a[i]<<" "<<b[j]<<endl;
            if (ret == -1)
                ret = a[i]^b[j];
            else if(ret > (a[i]^b[j]))
            {   
                // cout<<"weird"<<ret<<" "<<(a[i]^b[j])<<endl;
                ret = a[i]^b[j];
            }
            // cout<<"\t\t"<<ret<<endl;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> k;
    lint a[m][k], wt;
    vector<lint> b[m];
    for (lint i = 0; i < m; i++)
    {
        for (lint j = 0; j < k; j++)
        {
            cin >> a[i][j];

            // if (j == 0)
            //     b[i].push_back(a[i][j]);

            // if (j > 0)
            // {
            //     a[i][j] = __gcd(a[i][j], a[i][j - 1]);
            //     if (a[i][j] != a[i][j - 1])
            //         b[i].push_back(a[i][j]);
            // }
        }
        sort(a[i], a[i]+k, greater<lint>());
    }
    
    

    for (lint i = 0; i < m; i++)
    {
        for (lint j = 0; j < k; j++)
        {
            if (j == 0)
                b[i].push_back(a[i][j]);

            if (j > 0)
            {
                a[i][j] = __gcd(a[i][j], a[i][j - 1]);
                if (a[i][j] != a[i][j - 1])
                    b[i].push_back(a[i][j]);
            }
        }    
        
    }

    // cout << min_xor(b[0], b[1]) << " " << min_xor(b[2], b[1]) << " " << min_xor(b[0], b[2])<<endl;

    for (lint i=0;i<m;i++)
    {
        for (lint j=i+1;j<m;j++)
        {
            // cout<< i <<" "<<j<<" "<<endl; 
            wt = min_xor(b[i], b[j]);
            edges.push_back(make_pair(wt, make_pair(i,j)));
        }
    }

    sort(edges.begin(), edges.end());

    for (lint i=0;i<m;i++)
        id[i] = i, sz[i] = 1;

    for ( auto p: edges)
    {
        if (cnt == m-1)
            break;
        x = p.second.first;
        y = p.second.second;
        wt = p.first;

        // cout<<x<<" "<<y<<" "<<wt<<endl;
        px = root(x);
        py = root(y);

        if (px == py)
            continue;
        if (sz[px]>sz[py])
            swap(px,py);
        //sz[py] > sz[px]
        
        id[px] = py;
        sz[py]+=sz[px];
        
        ans+=wt;
        cnt++;
        
    }
   
    cout<<ans<<endl;

}