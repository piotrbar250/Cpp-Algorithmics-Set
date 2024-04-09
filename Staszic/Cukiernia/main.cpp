#include <iostream>
using namespace std;

const int M = 1009;
pair<int,int> ciastka[M];
int dp[M][M];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>ciastka[i].first>>ciastka[i].second;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(ciastka[i].first>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],(dp[i-1][j-ciastka[i].first]+ciastka[i].second));
        }
    }
    cout<<dp[n][m];
}
