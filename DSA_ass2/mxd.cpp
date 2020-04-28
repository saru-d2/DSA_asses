#include <iostream>
#include <stack>
#include <utility>
typedef long long int lint;
using namespace std;
lint n, a[2000005], max_sum=0, min_sum=0;
stack<lint> stk;
lint l[2000005];
lint r[2000005];
pair<lint, lint> range[2000005];
void printstk(stack<lint> s)
{
    cout << "stack: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

void clear(stack<lint> &s)
{
    while (!s.empty())
    {
        s.pop();
    }
}
int main()
{

    //lint n;
    cin >> n;
    for (lint i = 0; i < n; i++)
    {
        l[i] = -1;
        r[i] = -1;
    }
    for (lint i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (lint i = 0; i < n; i++)
    {
        if (stk.empty())
        {
            stk.push(i);
        }
        else
        {
            while (!stk.empty() && a[stk.top()] < a[i])
            {
               // cout << "gay: " << stk.top() << " " << i << "\n";
                l[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
    }

    for (lint i = 0; i < n; i++)
         cout << l[i] << " ";
        cout << endl;

        clear(stk);

    for (lint i = n - 1; i >= 0; i--)
    {
        if (stk.empty())
        {
            stk.push(i);
        }
        else
        {
            while (!stk.empty() && a[stk.top()] <= a[i])
            {
                //cout << "gay: " << stk.top() << " " << i << "\n";
                r[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        //printstk(stk);
    }

    //check rarr
    for (lint i = 0; i < n; i++)
        cout << r[i] << " ";
    cout << endl;
    
    //getting ranges
    for (lint i = 0; i < n; i++)
    {
        if (l[i] == -1)
            range[i].second = n-1;
        else
            range[i].second = l[i] -1;

        if (r[i]==-1)
            range[i].first = 0;
        else
            range[i].first = r[i]+1;
    }

    //check ranges
    // for(lint i=0; i<n;i++)
    // {
    //     cout<<"("<<range[i].first<<","<<range[i].second<<") ";
    // }
    // cout<<"\n";
    ///
    for (lint i = 0; i < n; i++)
    {
        l[i] = -1;
        r[i] = -1;
    }
    for(lint i=0;i<n;i++)
    {
        max_sum+=(((i-range[i].first+1)*(range[i].second-i+1))*a[i]);
        cout<<max_sum<<" ";
    }
    //cout<<"max_sum: "<<max_sum<<endl;

    clear(stk);
    for (lint i = 0; i < n; i++)
    {
        if (stk.empty())
        {
            stk.push(i);
        }
        else
        {
            while (!stk.empty() && a[stk.top()] >= a[i])
            {
               // cout << "gay: " << stk.top() << " " << i << "\n";
                l[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
       // printstk(stk);
    }
    //check l arr

    // for (lint i = 0; i < n; i++)
    //     cout << l[i] << " ";
    // cout << "\n";

    // for (lint i = 0; i < n; i++)
    //     cout << l[i] << " ";
    // cout << "\n";

    clear(stk);

    for (lint i = n - 1; i >= 0; i--)
    {
        if (stk.empty())
        {
            stk.push(i);
        }
        else
        {
            while (!stk.empty() && a[stk.top()] > a[i])
            {
               // cout << "gay: " << stk.top() << " " << i << "\n";
                r[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        //printstk(stk);
    }
    //check rarr
    // for (lint i = 0; i < n; i++)
    //     cout << r[i] << " ";
    //cout << endl;
    for (lint i = 0; i < n; i++)
    {
        if (l[i] == -1)
            range[i].second = n - 1;
        else
            range[i].second = l[i] - 1;

        if (r[i] == -1)
            range[i].first = 0;
        else
            range[i].first = r[i] + 1;
    }
    //check ranges
    // for (lint i = 0; i < n; i++)
    // {
    //     cout << "(" << range[i].first << "," << range[i].second << ") ";
    // }
    // cout << "\n";
    for (lint i = 0; i < n; i++)
    {
        min_sum += (((i - range[i].first + 1) * (range[i].second - i + 1)) * a[i]);
        //cout<<max_sum<<" ";
    }
    //cout<<"min_sum: "<<min_sum<<endl;
    cout<<max_sum-min_sum<<endl;
}