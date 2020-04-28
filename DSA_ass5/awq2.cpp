#include <iostream>
#define lint long long int
using namespace std;
int mod = 1000000007;
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
    bool bit;
    int tot_child = 0;
    node *par = NULL;
} * root;

void insert(int n)
{
    // cout << "in insert " << n << endl;
    node *np = root;
    bool ind;
    bool flag = 0;
    for (int i = 31; i >= 0; i--)
    {
        ind = (n >> i) & 1;
        // cout << ind;
        if (np->child[ind] == NULL)
        {
            flag = 1;
            node *t = new node;
            np->child[ind] = t;
            t->bit = ind;
            t->par = np;
        }
        np = np->child[ind];
    }
    // cout << endl;
    if (flag == 1)
        while (np != root)
        {
            np = np->par;
            np->tot_child += 1;
        }
    // cout<<"insert done"<<endl;
}

// void del(lint n)
// {
//     int ind;
//     node *np = root, *temp = root;
//     for (lint i = 31; i >= 0; i--)
//     {
//         ind = (n >> i) & 1;
//         np->tot_child --;
//         if(temp->tot_child <= 0){
//             int q = temp->bit;
//             // temp->par->child[q] = NULL;
//             free(temp);
//         }
//         temp = np;
//         np = np->child[ind];
//     }
//     np->tot_child--;
// }

void del(int n)
{
    // cout << "in delete " << n << endl;
    bool ind;
    node *np = root, *temp = root;
    for (int i = 31; i >= 0; i--)
    {
        ind = (n >> i) & 1;
        if (np->child[ind] == NULL)
            ; // cout << "weird\n";
        else
            np = np->child[ind];
    }
    
    while (np != root)
    {

        np->tot_child -= 1;
        if (np->tot_child <= 0)
        {
            temp = np;
            ind = np->bit;
            np->par->child[ind] = NULL;
            delete temp;
        }
        np = np->par;
    }
}

int get_min(int xo)
{
    node *np = root;
    bool ind;
    int ret = 0;
    for (int i = 31; i >= 0; i--)
    {
        ind = (xo >> i) & 1;
        if (ind == 0)
        {
            if (np->child[0] == NULL)
            {
                break;
            }
            else if (i > 0 && np->child[0]->tot_child < fast_exp(2, i))
            {
                np = np->child[0];
            }
            else if (np->child[1] == NULL)
            {
                ret += 1 << i;
                break;
            }
            else
            {
                ret += 1 << i;
                np = np->child[1];
            }
        }
        else
        {
            if (np->child[1] == NULL)
            {
                break;
            }
            else if (i > 0 && np->child[1]->tot_child < fast_exp(2, i))
            {
                np = np->child[1];
            }
            else if (np->child[0] == NULL)
            {
                ret += 1 << i;
                break;
            }
            else
            {
                ret += 1 << i;
                np = np->child[0];
            }
        }
    }

    return ret;
}

int main()
{
    int n, q, a[100005], xo = 0, ans = 1;
    cin >> n >> q;
    root = new node;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        insert(a[i]);
    }
    int qtype;
    int x, y, z;
    int f;
    while (q--)
    {
        cin >> qtype;
        switch (qtype)
        {
        case 1:
            cin >> x;
            xo = xo ^ x;
            break;
        case 2:
            cin >> y >> z;
            cnt[a[y]]--;
            if (cnt[a[y]] == 0)
            {
                // cout << y << endl;
                // search(a[y]);
                del(a[y]);
                // cout << "hi" << endl;
            }
            // cout << "\t" << z << " " << xo << endl;
            insert(z ^ xo);
            // cout << "inserted" << endl;
            a[y] = (z ^ xo);
            // cout << "hi" << endl;
            cnt[a[y]]++;
            // cout << "night" << endl;
            break;
        }
        // cout << "heyyoo" << endl;
        // cout << "xo: " << xo << endl;
        f = get_min(xo);
        // cout << f << endl;
        ans = (ans * fast_exp((int)100000000, f)) % mod;
        // ans %= mod;
    }
    cout << ans % mod << endl;
    // searc
}
