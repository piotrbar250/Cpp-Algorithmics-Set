#include <bits/stdc++.h>
using namespace std;

const int M = 1 << 20;
pair <int,int> arr[M];

bool cmp(pair <int, int> a, pair <int,int> b)
{
    if(a.second > b.second)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>arr[i].first>>arr[i].second;

    sort(arr+1, arr+1+n, cmp);

    int last = arr[1].second;

    for(int i=1; i<=n; i++)
    {
        last = min(last,arr[i].second);
        last -= arr[i].first;
    }
    cout<<last;
}
