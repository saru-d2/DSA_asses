#include <iostream>
#include <vector>
// #include <queue>
#define lint long long int
using namespace std;
// priority_queue<lint, vector<lint>, greater<lint>> pq;
// priority_queue<lint> pq;
lint id[1000005], sz[1000005], indegree[1000005];
vector<lint> input[1000005], adj[1000005], ans;

vector<lint> A;
lint parent(lint i)
{
    return (i - 1) / 2;
}
lint left(lint i)
{
    return i * 2 + 1;
}
lint right(lint i)
{
    return left(i) + 1;
}
void heap_down(lint i)
{
    lint l = left(i);
    lint r = right(i);

    lint sm = i;
    if (l < A.size() && A[l] < A[sm])
        sm = l;
    if (r < A.size() && A[r] < A[sm])
        sm = r;

    if (sm != i)
    {
        swap(A[i], A[sm]);
        heap_down(sm);
    }
}
void heap_up(lint i)
{
    if (i && A[parent(i)] > A[i])
    {
        swap(A[i], A[parent(i)]);
        heap_up(parent(i));
    }
}

void push(lint i)
{
    // cout << "pushing: " << i << endl;
    A.push_back(i);
    heap_up(A.size() - 1);
}

void pop()
{
    if (A.size() != 0)
        A[0] = A[A.size() - 1];
    A.pop_back();
    heap_down(0);
}
//////////////////
int main()
{
    lint n, k;
    cin >> n >> k;
    for (lint i = 1; i <= k; i++)
        id[i] = i, sz[i] = 1;
    int flag = 1;
    lint l, x;
    for (lint i = 0; i < n; i++)
    {
        cin >> l;
        while (l--)
        {
            cin >> x;
            input[i].push_back(x);
        }
    }
    // cout << "input done\n";
    lint A, B;
    for (int i = 1; i < n; i++)
    {
        bool f = false;
        vector<lint> a = input[i - 1], b = input[i];
        for (lint i = 0; i < min(a.size(), b.size()); i++)
        {
            // cout << a[i] << " " << b[i] << endl;
            if (a[i] != b[i])
            {
                A = a[i], B = b[i];

                f = true;
                break;
            }
        }
        // cout<<"f: "<<f<<endl;
        if (!f)
        {
            // cout << "condn 1\n";
            if (a.size() > b.size())
            {
                cout << "-1\n";
                return 0;
            }
            continue;
        }
       

        adj[A].push_back(B);
        indegree[B]++;
    }

 

    for (lint i = 1; i <= k; i++)
    {
        if (indegree[i] == 0)
            push(i);
    }
    lint fr;
    lint cnt = 0;
    while (::A.size() > 0)
    {
        cnt += 1;
        fr = ::A[0];
        pop();
        // cout << fr << " ";
        ans.push_back(fr);
        // stk.push(fr);
        for (lint i = 0; i < adj[fr].size(); i++)
        {
            indegree[adj[fr][i]]--;
            if (indegree[adj[fr][i]] == 0)
                push(adj[fr][i]);
        }
    }
    // cout << "\n";
    // cout<<k<<"\n";
    if (cnt != k)
    {
        cout << "-1\n";
        return 0;
    }
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}
