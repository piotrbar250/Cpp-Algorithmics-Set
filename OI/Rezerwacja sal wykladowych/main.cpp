#include <bits/stdc++.h>
using namespace std;

const int M = 1e4 + 9;
int n;
pair <int,int> arr[M];
int dp[3][M];

int binary_search(int i)
{
    int l = 1, r = i - 1, md, res = 0;
    int x = arr[i].first;

    while(l <= r)
    {
        md = (l + r) / 2;
        if(arr[md].second <= x)
        {
            l = md + 1;
            res = md;
        }
        else
            r = md - 1;
    }
    return max(dp[1][res], dp[2][res]);
}


bool cmp(pair <int,int> a, pair <int,int> b)
{
    return a.second < b.second;
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr+1, arr+1+n, cmp);
    for(int i=1; i<=n; i++)
    {
        dp[1][i] = arr[i].second - arr[i].first + binary_search(i);
        dp[2][i] = max(dp[1][i-1], dp[2][i-1]);
    }

    cout << max(dp[1][n], dp[2][n]) << endl;
    return 0;
}
