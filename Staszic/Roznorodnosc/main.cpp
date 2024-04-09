// Piotr Baranowski - C++ Developer
// Task: Roznorodnosc
// Language: C++
// Algorithm: Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

const int M = 10100, INF = 999999;
int dp[M][30][30];

string s;

int main()
{
    cin>>s;
    s = " " + s;

    for(int i=0; i<M; i++)
        for(int j=0; j<=26; j++)
            for(int k=0; k<=26; k++)
                dp[i][j][k] = INF;

    dp[0][0][0] = 0;

    for(int i=0; i<(s.size()-1); i++)
    {
        for(int j=0; j<=26; j++)
        {
            for(int k=0; k<=26; k++)
            {
                if(dp[i][j][k] == INF)
                    continue;

                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k] + 1);

                if(s[i+1] - 96 != j && s[i+1] - 96 != k)
                    dp[i+1][k][s[i+1]-96] = min(dp[i+1][k][s[i+1]-96],dp[i][j][k]);
            }
        }
    }

    int result = INF;
    for(int i=0; i<=26; i++)
        for(int j=0; j<=26; j++)
            result = min(result, dp[s.size()-1][i][j]);

    cout<<result;
    return 0;
}
