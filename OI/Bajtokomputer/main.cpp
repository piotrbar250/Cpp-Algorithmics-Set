#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 9, inf = 1e7;
int n;
int arr[M];
int dp[M][4];

int main()
{
    cin >> n;    
    for(int i=1; i<=n; i++)
        cin >> arr[i];

    for(int i=0; i<=n; i++)
        for(int j=1; j<=3; j++)
            dp[i][j] = inf;

    if(arr[1] == -1)
        dp[0][1] = 0;
    else if(arr[1] == 0)
        dp[0][2] = 0;
    else if(arr[1] == 1)
        dp[0][3] = 0; 
    
    // dp[n][1]
    for(int i=1; i<=n; i++)
        dp[i][1] = dp[i-1][1] + abs(arr[i] + 1);

    // dp[n][2]
    for(int i=1; i<=n; i++)
    {
        if(arr[i] == -1)
            dp[i][2] = inf;
        else if(arr[i] == 0)
            dp[i][2] = min(dp[i-1][1], dp[i-1][2]);
        else if(arr[i] == 1)
            dp[i][2] = dp[i-1][1] + 1;
    }

    // dp[n][3]
    for(int i=1; i<=n; i++)
    {
        if(arr[i] == 1)
            dp[i][3] = min(dp[i-1][1], min(dp[i-1][2], dp[i-1][3]));
        else
            dp[i][3] = dp[i-1][3] + abs(1 - arr[i]); 
    }
    int res = min(dp[n][1], min(dp[n][2], dp[n][3]));
    if(res != inf)
        cout << res << endl;
    else
        cout << "BRAK" << endl;
    return 0;
}
