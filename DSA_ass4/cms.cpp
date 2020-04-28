#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
lint mod = 1000000007;
lint id[1000005], sz[1000005], zor[1000005];
lint n, m, k;
lint tcc;

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

lint root(lint i)
{  
    
    if (i == id[i])
        return i;
   
    lint temp = root(id[i]);
    zor[i] = zor[i] ^ zor[id[i]];
    id[i]=temp;
    return temp;
    // if (i == id[i])
    //     return i ;
    // zor[i] = zor[i] ^ zor[id[i]];
    // return id[i] = root(id[i]);
}

lint dsu(lint x, lint y, lint z)
{
    lint px, py;
    px = root(x);
    py = root(y);

    if (sz[px] > sz[py])
        swap(px, py); //sz(py) > sz(px)

    if (px == py)
    {
        if ((zor[x] ^ zor[y] ^ z) != 0)
            return -1;
        return 0;
    }
    tcc -= 1;

    sz[py] += sz[px];
    id[px] = py;
    zor[px] = zor[x] ^ zor[y] ^ z;
    // cout << zor[x] << " " << zor[y] << " " << zor[px] << " " << zor[py] << "\n";
    return zor[x];
}
int main()
{

    cin >> n >> m >> k;
    lint x, y, z;
    tcc = n + m;
    for (int i = 1; i <= n + m; i++)
        id[i] = i, sz[i] = 1;

    lint v;
    while (k--)
    {
        cin >> x >> y >> z;
        v = dsu(x, y + n, z);
        if (v == -1)
        {
            cout << "0\n";
            return 0;
        }
    }
    lint ans = fast_exp(2, 30 * (tcc - 1));
    // cout<<"\n";
    cout << ans % mod << "\n";
}
