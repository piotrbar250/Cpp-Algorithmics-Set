#include <iostream>
using namespace std;
const int M = 1050;
int tab1[M][M];
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
            cin>>tab1[i][j];
    }

    dp[1][1]=tab1[1][1];

    for(int i=2; i<=m; i++)
        dp[1][i]=tab1[1][i] + dp[1][i-1];

    for(int i=2; i<=n; i++)
        dp[i][1]=tab1[i][1] + dp[i-1][1];



    for(int i=2; i<=n; i++)
    {
        for(int j=2; j<=m; j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+tab1[i][j];
        }
    }

    /*for(int i=1; i<=n; i++)
    {
       for(int j=1; j<=n; j++)
           cout<<dp[i][j]<<" ";
       cout<<endl;
    } */
    cout<<dp[n][m];

}
