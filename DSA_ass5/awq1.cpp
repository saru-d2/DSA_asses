#include <iostream>
#include <vector>
#define lint long long int
using namespace std;
lint mod = 1000000007;
lint hsh[100005];
lint fast_exp(lint a, lint n)
{
    lint ret = 1;
    while (n > 0)
    {
        if (n & 1)
            ret = (ret * a) % mod;
        n /= 2;
        a = (a * a) % mod;
    }
    return ret;
}

struct node
{
    node *child[2] = {NULL, NULL};
    int bit;
    int tot_child = 0;
    node *parent = NULL;
} * root;

void insert(lint n)
{
    // cout << "in insert " << n << endl;
    node *np = root;
    int ind;
    int flag = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((n / fast_exp(2, i)) & 1 == 1)
            ind = 1;
        else
            ind = 0;
        if (np->child[ind] == NULL)
        {
            flag = 1;
            node *t = new node;
            np->child[ind] = t;
            t->bit = ind;
            t->parent = np;
        }
        np = np->child[ind];
    }
    if (flag)
    {
        while (np != root)
        {
            np = np->parent;
            np->tot_child += 1;
        }
    }
}

void del(lint n)
{
    cout << "in delete " << n << endl;
    int ind;
    node *np = root;
    for (int i = 31; i >= 0; i--)
    {
        // cout<<i<<endl;
        if ((n / fast_exp(2, i)) & 1 == 1)
            ind = 1;
        else
            ind = 0;
        if (np->child[ind] != NULL)
            np = np->child[ind];
        // cout << i << " " << ind << endl;
    }
    cout << "heyo" << endl;
    int i = 0;
    while (np != root)
    {
        
        if (np->tot_child <= 0)
        {
            ind = np->bit;
            np->parent->tot_child -= 1;
            np->parent->child[ind] = NULL;
            np = np->parent;
        }
        else
        {
            // cout<<"hh"<<endl;
            np->tot_child -= 1;
            np = np->parent;
        }
    }
}
lint get_min(lint xo)
{
    // cout << "in getmin, xo = " << xo << endl;
    node *np = root;
    int ind;
    lint ret = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((xo / fast_exp(2, i)) & 1 == 1)
            ind = 1;
        else
            ind = 0;

        if (ind == 0)
        {
            // cout << "0 ";
            if (np->child[0] == NULL)
            {
                // cout << i << " "
                //      << "a " << ret;
                break;
            }
            else if (i > 0 && np->child[0]->tot_child < fast_exp(2, i))
            {
                // cout << i << " "
                //              "b "
                //      << ret << " " << fast_exp(2, i ) << " " << np->child[0]->tot_child;
                np = np->child[0];
            }
            else if (np->child[1] == NULL)
            {
                // cout << i << " "
                //              "c "
                //      << ret << " " << np->tot_child;
                // cout << np->child[0]->tot_child<<" ";
                ret += fast_exp(2, i);
                break;
            }
            else
            {
                // cout << i << " "
                //              "d "
                //      ;
                ret += fast_exp(2, i);
                np = np->child[1];
                //cout<<ret;
            }
        }
        else
        {
            // cout << "1 ";
            if (np->child[1] == NULL)
            {
                // cout << i << " "
                //              "a "
                //  << ret;
                break;
            }
            else if (i > 0 && np->child[1]->tot_child < fast_exp(2, i))
            {
                // cout << i << " "
                //              "b "
                //      << ret << " " << fast_exp(2, i) << " " << np->child[1]->tot_child;
                np = np->child[1];
            }
            else if (np->child[0] == NULL)
            {
                // cout << i << " "
                //              "c "
                //      << ret;
                ret += fast_exp(2, i);
                break;
            }
            else
            {
                // cout << i << " "
                //  "d "
                //  << ret;
                ret += fast_exp(2, i);
                np = np->child[0];
            }
        }
        // cout << endl;
    }
    // cout << "ret: " << ret << endl;
    return ret;
}
int main()
{
    lint ans = 1;
    lint n, q, a[100005];
    cin >> n >> q;
    root = new node;
    for (lint i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(a[i]);
        hsh[a[i]]++;
    }
    int q_type, xo = 0;
    lint x, y, z, f;
    while (q--)
    {
        cin >> q_type;
        switch (q_type)
        {
        case 1:
            cin >> x;
            xo = xo ^ x;
            break;
        case 2:
            cin >> y >> z;
            hsh[a[y]]--;
            if (hsh[a[y]] == 0)
                del(a[y] ^ xo);
            cout << "hi";
            a[y] = z ^ xo;
            insert(z ^ xo);
            hsh[z ^ xo]++;
            break;
        }
        // cout << "xo: " << xo << endl;
        f = get_min(xo);
        // cout << f << endl;

        ans *= fast_exp(100000000, f);
        ans %= mod;
    }
    cout << ans << endl;
}