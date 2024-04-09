#include <iostream>
using namespace std;
const int M = 1009;
int tab[M][M];
long long dp[M][M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            cin>>tab[i][j];
    }

    dp[1][1]=tab[1][1];

    for(int i=2; i<=m; i++)
        dp[1][i]=tab[1][i]+dp[1][i-1];

    for(int i=2; i<=n; i++)
        dp[i][1]=tab[i][1]+dp[i-1][1];

    for(int i=2; i<=n; i++)
    {
        for(int j=2; j<=m; j++)
            dp[i][j]=max(dp[i][j-1],dp[i-1][j])+tab[i][j];
    }
    if(dp[n][m]>=0)
        cout<<dp[n][m];
    else
        cout<<"0";
}
