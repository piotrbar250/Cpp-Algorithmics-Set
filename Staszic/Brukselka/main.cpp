#include <bits/stdc++.h>
using namespace std;

const int M = 1000009;
int arr[M],dp[M];
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>arr[i];

    dp[n] = 1;
    for(int i=n-1; i>=1; i--)
    {
        if(i + arr[i] + 1 > n)
        {
            dp[i] = dp[i+1];
            continue;
        }
        dp[i] = max(1 + dp[i+arr[i]+1], dp[i+1]);

    }
    cout<<dp[1];
}
