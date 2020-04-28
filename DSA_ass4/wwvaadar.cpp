#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// vector<pair<ll,ll> > adj[5005];

ll parent[5005];

ll size[5005];

ll inf = 1000000000000000;

vector<pair<ll, pair<ll, ll>>> edges;

priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
void merge(ll c, ll d)
{
    if (c != d)
    {
        if (size[c] > size[d])
        {
            parent[d] = parent[c];
            size[c] += size[d];
        }
        else
        {
            parent[c] = parent[d];
            size[d] += size[c];
        }
    }
}

ll find(ll a)
{
    if (parent[a] == a)
    {
        return a;
    }
    else
        return find(parent[a]);
}

void reset(ll n)
{
    ll i;
    for (i = 1; i <= n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    ll i;
    ll u, v, w;
    for (i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        //	adj[u].push_back(make_pair(w,v));
        //	adj[v].push_back(make_pair(w,v));
        edges.push_back(make_pair(w, make_pair(u, v)));
    }
    ll count = 0;
    ll c, t;
    ll min;
    min = inf;
    ll start = -10000000;
    ll end = 10000000;
    ll mid;
    ll a, b;
    ll ans;
    pair<ll, pair<ll, ll>> temp;
    while (start <= end)
    {
        while (!pq.empty())
        {
            pq.pop();
        }
        reset(n);
        c = 0;
        count = 0;
        ans = 0;
        mid = (start + end) / 2;
 //       cout << "mid" << mid << " " << start << " " << end << endl;
        for (auto p : edges)
        {
            if (p.second.first == 1 || p.second.second == 1)
            {
                pq.push(make_pair(p.first + mid, make_pair(p.second.first, p.second.second)));
            }
            else
            {
                pq.push(make_pair(p.first, make_pair(p.second.first, p.second.second)));
            }
        }
        while (!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            a = temp.second.first;
            b = temp.second.second;
            a = find(a);
            b = find(b);
            if (a == b)
            {
                continue;
            }
            else
            {
                c++;
                if (temp.second.first == 1 || temp.second.second == 1)
                {
                    count++;
                }
                ans += temp.first;
                merge(a, b);
            }
            if (c == n - 1)
            {
                break;
            }
        }
        // cout<<"answer"<<" "<<ans<<endl;
        if (count == k && c == n - 1)
        {
            ans = ans - (k * mid);
            if (min > ans)
            {
                min = ans;
            }
            break;
        }
        if (count > k)
        {
            t = mid;
            start = mid + 1;
        }
        else if (count < k)
        {
            end = mid - 1;
        }
        if (c < n - 1)
        {
            break;
        }
    }
    count = 0;
    reset(n);
    while (!pq.empty())
    {
        pq.pop();
    }
    c = 0;
	ans = 0;
    
    if (min == inf)
    {
        // cout << "hi\n";
        // for (i = 1; i <= n; i++)
        // {
        //     cout << parent[i] << " ";
        // }
        // cout << "\n";
        for (auto p : edges)
        {
            if (p.second.first == 1 || p.second.second == 1)
            {
                pq.push(make_pair(p.first + t, make_pair(p.second.first, p.second.second)));
            }
            else
            {
                pq.push(make_pair(p.first, make_pair(p.second.first, p.second.second)));
            }
        }
        while (!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            a = temp.second.first;
            b = temp.second.second;
            // cout<<a<<" "<<b<<endl;
            a = find(a);
            b = find(b);

            if (a == b)
            {
                continue;
            }
            else
            {
                // cout <<temp.first<<" " <<temp.second.first << " " << temp.second.second << endl;
                c++;
                if ((temp.second.first == 1 || temp.second.second == 1) && count < k)
                {
                    // cout << "\t" << count << endl;
                    // if (count >= k)
                    //     continue;
                    count++;
                }

                ans += temp.first;
                // cout<<"\t" <<ans<<endl;
                merge(a, b);
            }
            if (c == n - 1)
            {
                break;
            }
        }

        // cout << "count, t:" << count << " " << t << " " << c <<" ans"<<ans<<endl;
        if (count == k && c == n - 1)
        {
            ans = ans - (k * t);
            if (min > ans)
            {
                min = ans;
            }
        }
        if (min != inf)
            cout << min << endl;
        else
            cout << "-1\n";
    }

    else
    {
        cout << min << endl;
    }
    return 0;
}