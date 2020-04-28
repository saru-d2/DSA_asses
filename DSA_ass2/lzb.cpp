#include <iostream>
#include <stack>
typedef long long int lint;
using namespace std;
typedef long long int lint;
stack<int> stk;
lint vis[200005];
lint a[200005];
lint ans[200005];

int main()
{
    lint t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (lint i = 1; i <= n; i++)
            cin >> a[i];
        for (lint i = 1; i <= n; i++)
        {
            if (ans[i] == 0)
            {

                lint j = i;
                if (ans[a[j]] != 0)
                {
                    ans[j] = ans[a[j]];
                    continue;
                }
                vis[j] = 1;
                stk.push(j);
                j = a[j];

                while (!stk.empty() && ans[j] == 0)
                {
                    if (vis[j] == 1)
                    {
                        if (ans[j] == 0)
                        {
                            ans[j] = j;
                        }

                        if (!stk.empty())
                        {
                            while (!stk.empty() && stk.top() != j)
                            {

                                if (ans[stk.top()] == 0)
                                {
                                    ans[stk.top()] = stk.top();
                                }
                                if (!stk.empty())
                                    stk.pop();
                            }
                        }

                        while (!stk.empty())
                        {
                            ans[stk.top()] = ans[j];
                            stk.pop();
                        }
                    }
                    else
                    {
                        stk.push(j);
                        vis[j] = 1;
                        vis[j] = 1;
                        j = a[j];
                    }

                    if (ans[j] != 0)
                    {
                        while (!stk.empty())
                        {
                            ans[stk.top()] = ans[j];
                            stk.pop();
                        }
                    }
                }
            }
        }
        for (lint i = 1; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << ans[n];
        cout << endl;

        for (int i = 1; i <= n; i++)
        {
            a[i] = 0;
            ans[i] = 0;
            vis[i] = 0;
        }
    }
}