#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;

lint n, m, d, l, x, y, dis[20][20];
int a[405][405];
int h[405][405]; //hash table
map<int, pair<int, int>> l_v;
queue<pair<pair<lint, lint>, lint>> q;

void find_dis(int n)
{
    cout << "find_dis " << n << endl;
    lint index, x, y, t;
    q.push(make_pair(l_v[n], 0));
    while (!q.empty())
    {
        x = q.front().first.first;
        y = q.front().first.second;
        t = q.front().second;
        index = h[x][y];
        cout<<x<<" "<<y<<" "<<t<<" "<<index<<endl;
        q.pop();
        if (a[x][y] == 1)
            dis[n][index] = dis[index][n] = d;
        if (a[x][y] == 2)
            continue;
        if (x - 1 > 0)
            q.push(make_pair(make_pair(x - 1, y), t + 1));
        if (y - 1 > 0)
            q.push(make_pair(make_pair(x, y - 1), t + 1));
        if (x + 1 <= n)
            q.push(make_pair(make_pair(x + 1, y), t + 1));
        if (y + 1 <= m)
            q.push(make_pair(make_pair(x, y + 1), t + 1));
    }
}

int main()
{
    cin >> n >> m >> d >> l;
    while (d--)
    {
        cin >> x >> y;
        a[x][y] = 2;
    }
    for (int i = 0; i < l; i++)
    {
        cin >> x >> y;
        a[x][y] = 1;
        h[x][y] = i;
        l_v.insert(make_pair(i, make_pair(x, y)));
    }

    cout << "***input done****\n";
    for (lint i = 0; i < l_v.size(); i++)
        find_dis(i);

    for (lint i = 1; i <= n; i++)
    {
        for (lint j = 1; j <= m; j++)
        {
            cout << "dis[i][j]"
                 << " ";
        }
        cout << "\n";
    }
}