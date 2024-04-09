#include <iostream>
using namespace std;
const int M = 5009;
int dp[M][M];
string wynik;
int main()
{
    string n,m;
    cin>>n>>m;
    n=" "+n;
    m=" "+m;
    int d1=n.size()-1;
    int d2=m.size()-1;

    for(int i=1; i<=d1; i++)
    {
        for(int j=1; j<=d2; j++)
        {
            if(n[i]==m[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }

    int i=d1, j=d2;
    while(i>=1 && j>=1)
    {
        if(dp[i][j-1]==dp[i][j])
            j--;
        else if(dp[i-1][j]==dp[i][j])
            i--;
        else
        {
            wynik=n[i]+wynik;
            i--;
            j--;
        }
    }
 cout<<dp[d1][d2]<<endl;
 cout<<wynik;
}
