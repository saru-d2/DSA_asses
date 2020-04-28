#include <iostream>
#include <vector>

using namespace std;

int convention[35];
struct p *index_array[100005];
long long int mod = 1e9 + 7;
struct p
{
    struct p *left;
    struct p *right;
    struct p *parent;
    int digit;
    int number;
    int extra;
};
struct p *create_node(int n)
{
    struct p *base;
    base = (struct p *)malloc(sizeof(struct p));
    base->left = NULL;
    base->right = NULL;
    base->parent = NULL;
    base->digit = n;
    base->number = 0;
    base->extra = 0;
    return base;
}
long long int find_power(long long int a, long long int b)
{
    long long int answer = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            answer *= a;
            answer = answer % mod;
        }
        a = a * a;
        a = a % mod;
        b = b / 2;
    }
    return answer;
}

int create_node(struct p *root, long long int number, int index)
{
    struct p *child;
    int q;
    int flag = 0;

    for (int i = 29; i >= 0; i--)
    {
        q = ((number >> (i)) & 1);
        if ((q == 1 && convention[i + 1] == 0) || (q == 0 && convention[i + 1] == 1))
        {
            if (root->right == NULL)
            {
                flag = 1;
                child = create_node(i);
                root->right = child;
                child->parent = root;
            }
            root = root->right;
        }
        else
        {
            if (root->left == NULL)
            {
                flag = 1;
                child = create_node(i);
                root->left = child;
                child->parent = root;
            }
            root = root->left;
        }
    }

    index_array[index] = root;
    if (flag == 1)
    {
        while (root != NULL)
        {
            root->number += 1;
            root = root->parent;
        }
    }
    else
    {
        root->extra += 1;
    }
    return 0;
}

long long int find_min(struct p *root)
{
    long long int ans = 0;
    for (int i = 29; i >= 0; i--)
    {
        long long int toadd = (((long long int)1) << i);
        if (convention[i + 1] == 0)
        {
            if (root->left == NULL)
            {
                break;
            }
            else if (root->left->number < toadd)
            {
                root = root->left;
            }
            else if (root->right == NULL)
            {
                ans += toadd;
                break;
            }
            else
            {
                ans += toadd;
                root = root->right;
            }
        }
        else
        {
            if (root->right == NULL)
            {
                break;
            }
            else if (root->right->number < toadd)
            {
                root = root->right;
            }
            else if (root->left == NULL)
            {
                ans += toadd;
                break;
            }
            else
            {
                ans += toadd;
                root = root->left;
            }
        }
    }
    return ans;
}

int del_node(struct p *leaf)
{
    if (leaf->extra > 0)
    {
        leaf->extra -= 1;
    }
    else
    {
        struct p *par = leaf->parent;
        while (leaf->number == 1 && par != NULL)
        {
            if (par->left == leaf)
            {
                par->left = NULL;
            }
            else
            {
                par->right = NULL;
            }
            leaf->parent = NULL;
            free(leaf);
            leaf = par;
            par = leaf->parent;
        }
        while (leaf != NULL)
        {
            leaf->number -= 1;
            leaf = leaf->parent;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    struct p *base = create_node(30);

    // long long int okay = 1;
    for (int i = 0; i < 32; i++)
    {
        convention[i] = 0;
        // pow2[i]=okay;
        // okay=okay*2;
        // cout<<i<<" ";
        // cout<<okay<<"\n";
    }
    long long int b, index;
    long long int a;
    long long int number;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        create_node(base, a, i);
        // cout<<"for "<<i<<"\n";
        // prlong long long long int_till_parent(index_array[i]);
    }
    // cout<<"okay\n";
    long long int power = 0;
    for (int i = 0; i < q; i++)
    {

        cin >> a;
        // cout<<"NEW NEW NEW NEW NEW NEW"<<"\n";
        if (a == 1)
        {
            cin >> b;
            // cout<<a<<" "<<b<<"\n";
            for (int i = 0; i < 30; i++)
            {
                int dig = b & 1;
                if (dig == 1)
                {
                    convention[i + 1] = convention[i + 1] ^ 1;
                }
                b = b / 2;
            }

            // for(long long long long int i=0;i<31;i++){
            //     cout<<convention[i]<<" ";
            // }
            // cout<<"\n";
        }
        else
        {

            cin >> index >> number;
            // cout<<a<<" "<<index<<" "<<number<<"\n";
            index--;
            del_node(index_array[index]);
            create_node(base, number, index);

            // cout<<index_array[index]->number<<"\n";
        }
        // cout<<"dude\n";
        long long int add = find_min(base);
        power += add;
        // cout<<add<<"\n";
        if (power > mod - 1)
        {
            power = power % (mod - 1);
        }
        // cout<<add<<"\n";
        // prlong long long long int_it(base);
    }

    power = (power * 8) % (mod - 1);
    long long int answer = find_power(10, power);
    cout << answer << "\n";
}