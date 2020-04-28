#include <bits/stdc++.h>
using namespace std;

int tern_search(int l, int r, vector<int> a, int key)
{
    if (l >=r )
        return -1;
    int mid1 = (l + r) / 3;
    int mid2 = 2 * (l + r) / 3;
    if (a[mid1] == key)
        return mid1;
    if (a[mid2] == key)
        return mid2;
    if (a[mid2] > key)
        return tern_search(mid2, r, a, key);
    if (a[mid1] < key)
        return tern_search(l, mid1, a, key);
    return tern_search(mid1, mid2, a, key);
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 6, 8, 12, 13, 15, 16};
    int l = 0, r = a.size() - 1;
    cout << tern_search(l, r, a, 4) << endl;
    cout << tern_search(l, r, a, 5) << endl;
    cout << tern_search(l, r, a, 8) << endl;
}