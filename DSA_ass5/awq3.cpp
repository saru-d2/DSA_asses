#include <iostream>
#define lint long long int
using namespace std;
#define mod 1000000007

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
    node *par = NULL;
    int tot_child = 0;
    int multiplicity = 0;
} * root;

void insert(int n)
{
    bool ind;
    bool flag = 0;
    node *np = root;
    for (int i = 31; i >= 0; i--)
    {
        // np->multiplicity++;
        ind = (n >> i) & 1;
        if (np->child[ind] == NULL)
        {
            flag = 1;
            node *t = new node;
            np->child[ind] = t;
            t->par = np;
            t->bit = ind;
        }
        np = np->child[ind];
        np->multiplicity+=1;
    }
    if (flag)
    {
        while (np != root)
        {
            np = np->par;
            np->tot_child++;
        }
    }
}

void del(int n)
{
    bool ind;
    node *np = root;
    for (int i = 31; i >= 0; i--)
    {
        ind = (n >> i) & 1;
        if (np->child[ind] == NULL)
            ;
        else
            np = np->child[ind];
    }

    np->multiplicity--;
    // cout<<"mul "<<np->multiplicity<<endl;
    if (np->multiplicity <= 0)
    {
        node *temp = np;
        while (np != root)
        {
            np->tot_child -= 1;
            if (np->tot_child <= 0)
            {
                // cout<<"nulling\n";
                temp = np;
                ind = np->bit;
                np->par->child[ind] = NULL;
                delete temp;
            }
            np = np->par;
        }
    }
}

int get_min(int xo)
{
    int ret = 0;
    bool ind;
    node *np = root;
    for (int i = 31; i >= 0; i--)
    {
        ind = (xo >> i) & 1;
        // cout<<ind<<" ";
        if (ind == 0)
        {
            if (np->child[0] == NULL)
            {
                // cout<<i<<" a\n";
                break;
            }
            else if (i > 0 && np->child[0]->tot_child < fast_exp(2, i))
            {
                // cout<<i<<" b\n";
                np = np->child[0];
            }
            else if (np->child[1] == NULL)
            {
                // cout<<" c\n";
                ret += 1 << i;
                break;
            }
            else
            {
                // cout<<" d\n";
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
                ret += fast_exp(2, i);
                break;
            }
            else
            {
                ret += fast_exp(2, i);
                np = np->child[0];
            }
        }
    }
    return ret;
}
int main()
{
    int n, q;
    int a[100005];
    cin >> n >> q;
    root = new node;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    int qtype, x, y, z, xo = 0, f = 0;
    lint ans= 1;
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
            del(a[y]);
            insert(z ^ xo);
            a[y] = z ^ xo;
            break;
        }
        f = get_min(xo);
        // cout << f << endl;

        ans = (ans*fast_exp(100000000, f))%mod;
    }
    cout<<ans<<endl;
}