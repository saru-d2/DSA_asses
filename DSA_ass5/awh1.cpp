#include <iostream>
#include <vector>
#include <algorithm>
#define lint long long int
using namespace std;
vector<pair<int, vector<int>>> frend;

bool cmp(const pair<int, vector<int>> a, const pair<int, vector<int>> b)
{

    if (a.first == b.first)
        return a.second[0] < b.second[0];
    return a.first > b.first;
}

int main()
{
    lint x, n;
    cin >> x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int j, c;
        cin >> c;
        vector<int> a;
        while (c--)
        {
            cin >> j;
            a.push_back(j);
        }
        sort(a.begin(), a.end(), greater<int>());
        frend.push_back({a.size(), a});
    }
    sort(frend.begin(), frend.end(), cmp);
    lint ans = 0;
    int cur = x;
    while (cur <= frend[0].first)
    {
        ans += frend[0].second.back();
        frend[0].second.pop_back();
        frend[0].first--;
        cur++;
        sort(frend.begin(), frend.end(), cmp);
    }
    cout << ans << endl;
}