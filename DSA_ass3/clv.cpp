#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
lint N, M, d, l, x, y, t;
lint a[405][405], h[405][405], dis[15][15], dis_o[15], dis_a[15];
vector<pair<lint, lint>> v_l;
lint a0 = -1;
lint ans = -1;

void aarogya()
{
    queue<pair<pair<lint, lint>, lint>> q;
    q.push(make_pair(make_pair(N, M), 0));
    bool vis[405][405] = {0};
    while (!q.empty())
    {
        x = q.front().first.first;
        y = q.front().first.second;
        t = q.front().second;

        q.pop();
        if (vis[x][y] == 1)
        {
            continue;
        }
        vis[x][y] = 1;
        if (a[x][y] == 2)
        {
            continue;
        }
        if (a[x][y] == 1)
            dis_a[h[x][y]] = t;
        if (x - 1 >= 1 && vis[x - 1][y] == 0)
        {
            q.push(make_pair(make_pair(x - 1, y), t + 1));
        }

        if (x + 1 <= N)
        {
            q.push(make_pair(make_pair(x + 1, y), t + 1));
        }
        if (y - 1 >= 1 && vis[x][y - 1] == 0)
        {
            q.push(make_pair(make_pair(x, y - 1), t + 1));
        }
        if (y + 1 <= M && vis[x][y + 1] == 0)
        {
            q.push(make_pair(make_pair(x, y + 1), t + 1));
        }
    }
}

void origin()
{
    queue<pair<pair<lint, lint>, lint>> q;
    q.push(make_pair(make_pair(1, 1), 0));
    bool vis[405][405] = {0};
    while (!q.empty())
    {

        x = q.front().first.first;
        y = q.front().first.second;
        t = q.front().second;

        if (x == N && y == M)
            a0 = t;

        q.pop();
        // //cout << vis[x][y];
        if (vis[x][y] == 1)
        {
            //    //cout << "visited\n";
            continue;
        }
        vis[x][y] = 1;
        if (a[x][y] == 2)
        {
            // //cout << "dead\n";
            continue;
        }
        if (a[x][y] == 1)
            dis_o[h[x][y]] = t;
        // //cout << " \t" << N << " " << M << endl;
        // //cout << vis[x - 1][y] << endl;
        if (x - 1 >= 1 && vis[x - 1][y] == 0)
        {
            // //cout << "1. " << x << " " << y << "\n";
            q.push(make_pair(make_pair(x - 1, y), t + 1));
        }

        if (x + 1 <= N)
        {
            ////cout << "2. " << x << " " << y << " "
            // "\n";
            q.push(make_pair(make_pair(x + 1, y), t + 1));
        }
        if (y - 1 >= 1 && vis[x][y - 1] == 0)
        {
            // //cout << "3. " << x << " " << y << "\n";
            q.push(make_pair(make_pair(x, y - 1), t + 1));
        }
        if (y + 1 <= M && vis[x][y + 1] == 0)
        {
            // //cout << "4. " << x << " " << y << "\n";
            q.push(make_pair(make_pair(x, y + 1), t + 1));
        }
    }
}
void bfs(lint n)
{
    queue<pair<pair<lint, lint>, lint>> q;
    q.push(make_pair(v_l[n], 0));
    bool vis[405][405] = {0};
    while (!q.empty())
    {
        // cout << "hi\n";
        x = q.front().first.first;
        y = q.front().first.second;
        t = q.front().second;
        // cout << "\t" << n << " " << x << " " << y << " "
        //  << " " << t << endl;

        q.pop();
        if (vis[x][y] == 1)
        {
            // cout << "continueing\n";
            continue;
        }
        vis[x][y] = 1;
        if (a[x][y] == 2)
            continue;
        if (a[x][y] == 1)
            dis[h[x][y]][n] = dis[n][h[x][y]] = t;
        // //cout << " \t" << N << " " << M << endl;
        if (x - 1 >= 1 && vis[x - 1][y] == 0)
        {
            // cout << "1. " << x << " " << y << " " << t << "\n";
            q.push(make_pair(make_pair(x - 1, y), t + 1));
        }

        if (x + 1 <= N)
        {
            // cout << "2. " << x << " " << y << " " << t << "\n";
            q.push(make_pair(make_pair(x + 1, y), t + 1));
        }
        if (y - 1 >= 1 && vis[x][y - 1] == 0)
        {
            // cout << "3. " << x << " " << y << " " << t << "\n";
            q.push(make_pair(make_pair(x, y - 1), t + 1));
        }
        if (y + 1 <= M && vis[x][y + 1] == 0)
        {
            // cout << "4. " << x << " " << y << " " << t << "\n";
            q.push(make_pair(make_pair(x, y + 1), t + 1));
        }
    }
}

int main()
{
    cin >> N >> M >> d >> l;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            h[i][j] = -1;
    while (d--)
    {
        cin >> x >> y;
        a[x][y] = 2;
    }
    for (int i = 0; i < l; i++)
    {
        cin >> x >> y;
        if (a[x][y] == 2)
        {
            cout << "-1\n";
            return 0;
        }
        a[x][y] = 1;
        v_l.push_back(make_pair(x, y));
        h[x][y] = i;
        dis_a[i] = -1;
        dis_o[i] = -1;
        for (int j = 0; j < l; j++)
            dis[i][j] = -1;
    }

    for (lint i = 0; i < l; i++)
        bfs(i);

    // cout << "done\n";
    origin();
    aarogya();

    // for (lint i = 0; i < l; i++)
    // {
    //     for (lint j = 0; j < l; j++)
    //     {
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    // for (lint i = 0; i < l; i++)
    //     cout << dis_o[i] << " ";
    // cout << endl;
    // for (lint i = 0; i < l; i++)
    //     cout << dis_a[i] << " ";
    // cout << endl;

    // for (int i = 0; i < l; i++)
    //     perm_arr.push_back(i);

    if (l == 0)
    {
        cout << a0 << "\n";
        return 0;
    }
    lint temp;
    int i = 0;
    vector<lint> perm_arr(l);
    for (int i = 0; i < l; i++)
        perm_arr[i] = i;

    do
    {
        // if (i == 3628800)
        //     break;
        // cout << i++ << " " << ans << endl;
        temp = -1;
        for (int i = 0; i < l; i++)
        {
            // cout << perm_arr[i] << " ";
            if (i == 0)
            {
                if (dis_o[perm_arr[i]] == -1)
                {
                    temp = -1;
                    break;
                }
                temp = dis_o[perm_arr[i]];
                continue;
            }
            if (dis[perm_arr[i]][perm_arr[i - 1]] == -1)
            {
                temp(lint i = 0; i < l; i++)
                    //     cout << dis_o[i] << " ";
                    // cout << endl;
                    // for (lint i = 0; i < l; i++)
                    //     cout << dis_a[i] << " ";
                    // cout << e = -1;
                    break;
            }
            temp += dis[perm_arr[i]][perm_arr[i - 1]];
            // cout << perm_arr[i] << perm_arr[i] - 1 << dis[perm_arr[i]][perm_arr[i - 1]] << " ";
        }
        // cout << "\t"
        //      << temp << "\n";
        // cout<<"\n";

        if (temp != -1 && dis_a[perm_arr[l - 1]] != -1)
        {
            temp += dis_a[perm_arr[l - 1]];
            if (ans == -1)
                ans = temp;
            else
                ans = min(ans, temp);
        }

    } while (next_permutation(perm_arr.begin(), perm_arr.end()));
     // do
        // {
        //     for (int i = 0; i < l; i++)
        //         cout << perm_arr[i] << " ";
        //     cout << "\n";
        // } while (next_permutation(perm_arr.begin(), perm_arr.end()));

        // cout << "don2\n";

        /**********
    perm_arr[0] = 0;
    perm_arr[1] = 4;
    perm_arr[2] = 5;
    perm_arr[3] = 1;
    perm_arr[4] = 2;
    perm_arr[5] = 6;
    perm_arr[6] = 7;
    perm_arr[7] = 3;
    temp = -1;
    for (int i = 0; i < l; i++)
    {
        // cout << perm_arr[i] << " ";
        if (i == 0)
        {
            if (dis_o[perm_arr[i]] == -1)
            {
                temp = -1;
                break;
            }
            temp = dis_o[perm_arr[i]];
            continue;
        }
        if (dis[perm_arr[i]][perm_arr[i - 1]] == -1)
        {
            temp = -1;
            break;
        }
        temp += dis[perm_arr[i]][perm_arr[i - 1]];
        cout << perm_arr[i] << perm_arr[i] - 1 << dis[perm_arr[i]][perm_arr[i - 1]] << " ";
    }
    cout << "\t"
         << temp << "\n";
    // cout<<"\n";

    if (temp != -1 && dis_a[perm_arr[l - 1]] != -1)
    {
        temp += dis_a[perm_arr[l - 1]];
        if (ans == -1)
            ans = temp;
        else
            ans = min(ans, temp);
    }

    *********/
    
    cout << ans << endl;
}