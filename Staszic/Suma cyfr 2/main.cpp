#include <iostream>
using namespace std;
const int M = 500*1000+15;
int tab[M];
long long dp[3][M];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>tab[i];

    dp[1][1] = tab[1];
    dp[2][1] = 9;

    for(int i=2; i<=n; i++)
    {
        dp[1][i]=max(dp[1][i-1],dp[2][i-1])+tab[i];
        dp[2][i]=9+dp[1][i-1];
    }
    long long wynik = max(dp[1][n],dp[2][n]);
    cout<<wynik;
}
