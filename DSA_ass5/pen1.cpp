#include <iostream>
#include <vector>
#include <utility>
// #include <stack>
// #include<string.h>
#define lint long long int
using namespace std;
vector<pair<lint, lint>> vp;
vector<pair<lint, lint>> stk;
struct node
{
    node *child[26] = {NULL};
} *root = NULL, *np = NULL;

void insert(string str)
{
    // cout<<"in insert"<<endl;
    lint len = str.size();
    // cout<<"in insert"<<endl;
    lint index;
    // cout<<"in insert"<<endl;
    np = root;
    // cout<<"wayy in insert"<<endl;
    // cout << str[0] << endl;
    for (lint i = 0; i < len; i++)
    {
        index = str[i] - 'a';
        if (!np->child[index])
        {
            node *t = new node;
            np->child[index] = t;
        }
        np = np->child[index];
    }
}

int main()
{
    lint n;
    string str, big;
    root = new node;
    cin >> big;
    cin >> n;
    // cout<<strlen(big)<<endl;
    // cout<<big<<endl;
    while (n--)
    {
        // cout << "hi ";
        cin >> str;
        // cout << str << endl;
        insert(str);
        // cout << "inserted" << endl;
    }
    node *np = root;
    for (int i = 0; i < big.size(); i++)
    {
        lint cnt = 0;
        np = root;
        for (lint j = i; i < big.size(); j++)
        {
            int ind = big[j] - 'a';
            if (!np->child[ind])
                break;
            cnt++;
            np = np->child[ind];
        }
        // cout << i << ": " << cnt << " "<<endl;
        if (cnt > 0)
        {
            vp.push_back({i, i + cnt - 1});
            // cout << vp[vp.size() - 1].first << " " << vp[vp.size() - 1].second << endl;
        }
    }
    if (vp.empty())
    {
        cout << "-1\n";
        return 0;
    }
    if (vp[0].first != 0)
    {
        cout << "-1\n";
        return 0;
    }
    stk.push_back(vp[0]);
    pair<lint, lint> top;
    for (auto i : vp)
    {
        // cout<<"["<<i.first<<", "<<i.second<<"] ->";
        // traverse(stk);
        if (stk[stk.size() - 1].second >= i.second)
            continue;
        if (i.first > stk[stk.size() - 1].second + 1)
        {
            // cout<<i.first<<" "<<stk.#top().second<<"\n ";
            cout << "-1\n";
            return 0;
        }
        int flag = 0;
        while (stk.size() > 1 && i.first <= stk[stk.size() - 2].second + 1)
        {
            stk.pop_back();
        }
        if (!flag)
        {
            stk.push_back(i);
        }
    }

    cout << stk.size() << endl;
}