#include <iostream>
#include <vector>
#define lint long long int
using namespace std;

vector<lint> A;
lint parent(lint i)
{
    return (i - 1) / 2;
}
lint left(lint i)
{
    return i * 2 +1;
}
lint right(lint i)
{
    return left(i) + 1;
}
void heap_down(lint i)
{
    int l = left(i);
    int r = right(i);

    int sm = i;
    if (l < A.size() && A[l] < A[sm])
        sm = l;
    if (r < A.size() && A[r] < A[sm])
        sm = r;
    
    if (sm!=i)
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

void push(int i)
{
    cout<<"pushing: "<<i<<endl;
    A.push_back(i);
    heap_up(A.size() - 1);
}

void pop()
{
    if (A.size() != 0)
    A[0] = A[A.size() -1];
    A.pop_back();
    heap_down(0);
}

int main()
{
    int n , m;
    cin>>n;
    while(n--){
    cin>>m;
    push(m);
    for (auto i : A)
        cout << i << " ";
    }
    cout<<"hi";
    cout<< "\n";
    
    while(A.size() > 0)
    {
        cout<<A[0]<<" ";
        pop();
    }
}