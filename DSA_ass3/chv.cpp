#include <iostream>
#include <vector>
using namespace std;
typedef long long int lint;
lint n, m, ans = 0;
lint x, y, px, py, ms = 1;
lint siz[200005], id[200005];

lint root(lint n)
{
    while (id[n] != n)
    {
        n = id[n];
    }
    return id[n];
}

int main()
{
    cin >> n >> m;

    for (lint i = 1; i <= n; i++)
    {
        siz[i] = 1;
        id[i] = i;
    }

    if (m == 0)
    {
        ans = 1;
    }
    while (m--)
    {
        cin >> x >> y;
        px = root(x);
        py = root(y);

        if (px == py)
        {
            ms = max(ms, siz[px]);
        }
        else if (siz[px] > siz[py])
        {
            id[py] = px;
            siz[px] += siz[py];
            if (siz[px] > ms)
                ms = siz[px];
        }
        else
        {
            id[px] = py;
            siz[py] += siz[px];
            if (siz[py] > ms)
                ms = siz[py];
        }
        ans += ms;
        //cout<<"\t"<<ms<<" "<<siz[px]<<" "<<siz[py]<<endl;
    }
    cout << ans << endl;
}