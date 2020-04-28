#include <iostream>
#include <vector>
#define lint long long int
#define mod 1000000007
using namespace std;

vector<int> adj[1000006];

lint fast_exp(lint a, lint n)
{
    lint ret = 1;
    while (n > 0)
    {
        if (n & 1)
            ret = (ret * a) % mod;
        n /= 2;
        a = (a * a) % mod;
    }
    return ret;
}

void dfs(lint cur, lint par, vector<lint> &sz, vector<lint> &ret, lint n)
{
    // cout << "hi " << endl;
    bool flag = 1;
    sz[cur] = 1;
    for (auto i : adj[cur])
    {
        if (i != par)
        {
            dfs(i, cur, sz, ret, n);
            sz[cur] += sz[i];
            if (sz[i] > (n / 2))
                flag = 0;
        }
    }
    if (n - sz[cur] > (n / 2))
        flag = 0;
    if (flag == 1)
    {
        // cout << cur << " " << endl;
        ret.push_back(cur);
    }
}

vector<lint> find_cen(lint n)
{
    vector<lint> ret;
    vector<lint> sz(n + 3);
    dfs(1, -1, sz, ret, n);
    return ret;
}

vector<lint> find_no_top_sort(lint cen, lint n)
{
    lint r = 1;
    vector<lint> ret;
    vector<lint> sz(n + 3);
    dfs(cen, -1, sz, ret, n);

    return sz;
}

int main()
{
    lint t;
    cin >> t;
    while (t--)
    {
        lint n, x, y;
        cin >> n;
        for (lint i = 0; i < n - 1; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<lint> centroids = find_cen(n);

        for (auto i : centroids)
        {
            // cout << i << " ";
            // find_no_top_sort(i, n);
        }
        lint cent;
        if (centroids.size() > 1)
            cent = max(centroids[0], centroids[1]);
        else
            cent = centroids[0];

        vector<lint> sz = find_no_top_sort(cent, n);
        // cout << "de: " << de << endl;
        lint fact = 1;
        for (lint i = n; i > 1; i--)
            fact = (fact * i) % mod;
        // lint ans = fact / de;
        for (int i = 1; i <= n; i++)
            fact = (fact*fast_exp(sz[i], mod - 2))%mod;
        cout << cent << " " << fact << endl;
        for (lint i = 1; i <= n; i++)
            adj[i].clear();
    }
}