#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long int lint;
lint big = (lint) 1e15;
lint n, m, x, y, z, s, t, a, b, ans = big, h;
lint disa[200005], disb[200005], visa[200005], visb[200005];
vector<pair<lint, lint>> adj[200005];

//dij from s, t
//min sum
void dij_b(lint n)
{
    priority_queue<pair<lint, lint>,vector<pair<lint,lint> >, greater<pair<int,int> > > pq;
    // cout<<"in dijb "<<n<<endl;
    lint fr, d;
    disb[n] = 0;
    pq.push(make_pair(0, n));
    while (!pq.empty())
    {
        fr = pq.top().second, d = pq.top().first;
        pq.pop();
        for (auto p : adj[fr])
        {

            if (p.second >= b)
                if (disb[p.first] > p.second + d)
                {
                    disb[p.first] = p.second + d;

                    pq.push(make_pair(disb[p.first], p.first));
                }
        }
    }
}
void dij_a(lint n)
{
    priority_queue<pair<lint, lint>, vector<pair<lint, lint>>, greater<pair<int, int>>> pq;
    lint fr, d;
    disa[n] = 0;
    pq.push(make_pair(0, n));
    while (!pq.empty())
    {
        fr = pq.top().second, d = pq.top().first;
       // cout << fr << endl;

        pq.pop();
        // for (lint i = 0; i < adj[fr].size(); i++)
        for (auto p : adj[fr])
        {
            if (p.second <= a)
                if (disa[p.first] > p.second + d)
                {
                    disa[p.first] = p.second + d;
                    // cout << "\t" << disa[adj[fr][i].first] << " " << adj[fr][i].first << endl;

                    pq.push(make_pair(disa[p.first], p.first));
                }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    while (m--)
    {
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
    }

    cin >> s >> t >> a >> b;

    for (lint i = 1; i <= n; i++)
    {
        disa[i] = big;
        disb[i] = big;
    }
    dij_a(s);
    dij_b(t);
    // cout<<"disa: ";
    // for (lint i=1;i<=n;i++)
    // {
    //     cout<<disa[i]<<" ";
    // }
    // cout<<endl;
    // for (lint i = 1; i <= n; i++)
    // {
    //     cout << disb[i] << " ";
    // }
    // cout << endl;
    {
        for (lint i = 1; i <= n; i++)
            if (disa[i] + disb[i] < ans)
                ans = disa[i] + disb[i];
        // cout<<disa[i]<<" "<<disb[i]<<"\t";
    }
    if (ans == big)
        ans = -1;
    cout << ans << endl;
}
