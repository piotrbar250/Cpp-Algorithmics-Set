#include <bits/stdc++.h>
using namespace std;

const int M = 1000009;
int n,m;
long long result;
int arr[M], dp[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=1; i<=n; i++)
        cin>>arr[i];

    bool first = false;
    int pre = 0;

    dp[n] = n+1;
    for(int i=n-1; i>=1; i--)
    {
        if(arr[i+1]>=m)
            dp[i] = i+1;
        else
            dp[i] = dp[i+1];
    }

    for(int i=1; i<=n; i++)
    {
        long long x;

        if(arr[i] >= m && first)
        {
            x = (i-pre) * (dp[i]-i);
            result += x;
        }

        if(arr[i] >= m && !first)
        {
            first = true;
            x = i * (n - i + 1);
            result += x;
            pre = i;
        }
    }
    cout<<result;

}
