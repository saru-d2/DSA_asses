#include <iostream>
#include <vector>
#include <utility>
#define lint long long int
using namespace std;
vector<pair<lint, lint>> vp, stk;

struct node
{
    node *child[27];
    void init()
    {
        // cout << "init" << endl; 
        for (int i = 0; i < 27; i++)
            child[i] = NULL;
    }
};
node *root = NULL;

void insert(string s)
{
    node *np = root;
    lint len = s.size();
    int ind;
    for (lint i = 0; i < len; i++)
    {
        ind = s[i] - 'a';
        if (np->child[ind] == NULL)
        {
            node *t = new node;
            t->init();
            np->child[ind] = t;
        }
        np = np->child[ind];
    }
}

int main()
{
    string big, str;
    cin >> big;
    root = new node;
    root->init();
    int n;
    cin >> n;
    while (n--)
    {
        cin >> str;
        insert(str);
    }
    lint ind, cnt;
    for (lint i = 0; i < big.size(); i++)
    {
        cnt = 0;
        node *np = root;
        for (lint j = i; j < big.size(); j++)
        {
            ind = big[j] - 'a';
            if (np->child[ind] == NULL)
            {
                break;
            }
            cnt++;
            np = np->child[ind];
        }
        // cout << i << ": " << cnt << endl;
        if (cnt > 0)
        {
            vp.push_back({i, i + cnt - 1});
            // cout << vp.back().first << ", " << vp.back().second << endl;
        }
    }
    if (vp[0].first != 0)
    {
        cout << "-1" << endl;
        return 0;
    }
    stk.push_back(vp[0]);
    for (auto i : vp)
    {
        if (i.second <= stk.back().second)
            continue;
        if (i.first > stk.back().second + 1)
        {
            cout << "-1\n";
            return 0;
        }
        while (stk.size() >= 2 && stk[stk.size() - 2].second + 1 >= i.first)
        {
            stk.pop_back();
        }
        stk.push_back(i);
    }
    cout<<stk.size()<<endl;
}