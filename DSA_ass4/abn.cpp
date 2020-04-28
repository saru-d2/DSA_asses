#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;

lint n, m, mod = 1000000007;
lint id[100005], sz[100005];
lint fast_exp(lint a, lint n)
{
    lint ret = 1;
    while (n > 0)
    {
        if ((n & 1) == 1)
            ret = (ret * a) % mod;
        n /= 2;
        a = (a * a) % mod;
    }
    return ret;
}

lint root(lint n)
{
    if (id[n] == n)
        return id[n];
    return id[n] = root(id[n]);
}
lint x, y, px, py, cyc = 0, ans;
int main()
{
    cin >> n >> m;
    for (lint i = 1; i <= n; i++)
        id[i] = i, sz[i] = 1;
    while (m--)
    {

        cin >> x >> y;
        // cyc = 0;
        px = root(x);
        py = root(y);

        if (px == py)
        {
            cyc += 1;
        }
        else
        {
            if (sz[px] > sz[py])
                swap(px, py); //sz(py) > sz(px)

            id[px] = py;
            sz[py] += sz[px];
        }

        ans = fast_exp(2, cyc);
        ans -= 1;
        cout << ans % mod << endl;
    }
    // cout << fast_exp(2, 1);
}