#include <iostream>
#include <algorithm>
using namespace std;
const int M = 5009;
int tab1[M], tab2[M], dp[3][M];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>tab1[i];
    for(int i=1; i<=n; i++)
        cin>>tab2[i];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(tab1[i]==tab2[j])
                dp[2][j]=dp[1][j-1]+tab1[i];
            else
                dp[2][j]=max(dp[2][j-1],dp[1][j]);
        }
        for(int j=1; j<=n; j++)
            dp[1][j]=dp[2][j];
    }
    cout<<dp[2][n];
}
