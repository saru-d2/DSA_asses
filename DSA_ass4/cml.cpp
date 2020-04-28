#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
lint mod = 1000000007;
lint id[2000005], sz[2000005], zor[2000005];
lint n, m, k, X;
lint tcc;
vector<pair<pair<lint, lint>, lint>> input;
vector<lint> v;
std::map<lint, lint> Map;
lint fast_exp(lint a, lint n, lint weird = 0)
{
    lint ret = 1;
    while (n > 0)
    {
        if ((n & 1) == 1)
            ret = (ret * a) % (mod + weird);
        n /= 2;
        a = (a * a) % (mod + weird);
    }
    return ret;
}

lint root(lint i)
{

    if (i == id[i])
        return i;

    lint temp = root(id[i]);
    zor[i] = zor[i] ^ zor[id[i]];
    id[i] = temp;
    return temp;
}

lint dsu(lint x, lint y, lint z)
{
    // cout << x << " " << y << " " << z << " ";
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
    cin >> n >> m >> k >> X;
    lint x, y, z;
    for (lint i = 1; i <= k; i++)
    {
        cin >> x >> y >> z;
        input.push_back({{x, y + n}, z});
        v.push_back(x);
        v.push_back(y + n);
        // cout<<x<<" "<<y+n<<endl;
    }

    tcc = n + m;
    sort(v.begin(), v.end());
    lint c = 1;
    for (lint i : v)
    {
        if (!Map[i])
        {
            Map[i] = c;
            c++;
        }
        // cout << "(" << i << ", " << Map[i] << ") ";
    }
    // cout<<"\n";
    lint ans = 1;

    for (lint i = 1; i < 2000005; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }
    lint temp;
    for (auto i : input)
    {
        lint v = dsu(Map[i.first.first], Map[i.first.second], i.second);
        if (v == -1)
        {
            cout << ans << "\n";
            return 0;
        }
        // cout<<"tcc "<<tcc;
        temp = fast_exp(2, 30 * (tcc - 1), -1);
        // cout<<"temp "<<temp;
        ans *= fast_exp(X, temp);
        ans %= mod;
        // cout << tcc << endl;
    }
    cout << ans << endl;
    return 0;
}