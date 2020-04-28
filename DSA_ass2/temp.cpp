#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long int lint;

vector<pair<lint, lint>> adj[100005];
lint vis[200005], a[10]={ 1,3, 4,7,11,23,43,56,67,78}, ans;

lint uppr_bin(pair<lint, lint> rng, lint n)
{
    lint b = rng.first;
    lint e = rng.second + 1;
    lint mid;
    while (b <= e)
    {
        mid = (b + e) / 2;

        if (b == e)
            return mid;
        if (a[mid] > n)
        {
            e = mid;
        }
        else
        {
            b = mid + 1;
        }
    }
    return mid;
}

int main()
{
    cout<<uppr_bin(make_pair(0,9), 5)<<endl;

}