#include <bits/stdc++.h>
using namespace std;

const int M = 1001, K = 80, P = 22, inf = 1e7;
int n, O, N;
class cylinder
{
public:
    int ox;
    int nit;
    int w;
};

cylinder arr[M];
int dp[P][K][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> O >> N;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i].ox >> arr[i].nit >> arr[i].w;

    for(int i=0; i<=n; i++)
        for(int j=0; j<=O; j++)
            for(int k=0; k<=N; k++)
                dp[j][k][i] = inf;


    dp[0][0][0] = 0;

    for(int i=1; i<=n; i++)
        for(int j=0; j<=O; j++)
            for(int k=0; k<=N; k++)
                dp[j][k][i] = min(dp[j][k][i-1], 
                dp[max((int)0,j-arr[i].ox)][max((int)0,k-arr[i].nit)][i-1] + arr[i].w);

    cout << dp[O][N][n] << endl;
}
