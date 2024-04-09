#include <bits/stdc++.h>
using namespace std;

const int N = 609, K = 59;
int n, k, res;
int arr[N][N], prefix_sum[N][N];
int dp[N][K], last[N][K];

int sum(int x1, int x2) // x1 < x2
{
    return prefix_sum[x2][n] - prefix_sum[x1][n] - prefix_sum[x2][x2] + prefix_sum[x1][x2];
}

void print_res(int x, int cnt)
{
    if(cnt == 0)
        return;
    if (last[x][cnt] != 0)
        print_res(last[x][cnt], cnt - 1);
    cout << x << ' ';
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> arr[i][j];

    for (int i = 1; i < n; i++)
        for (int j = 1; j <= n; j++)
            prefix_sum[i][j] = arr[i][j] + prefix_sum[i][j - 1] + prefix_sum[i - 1][j] - prefix_sum[i - 1][j - 1];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= min(i, k); j++)
        {
            for (int h = 0; h < i; h++)
            {
                if (dp[i][j] <= dp[h][j - 1] + sum(h, i))
                {
                    dp[i][j] = dp[h][j - 1] + sum(h, i);
                    last[i][j] = h;
                }
                res = max(res, dp[i][j]);
            }
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        if (dp[i][k] == res)
        {
            print_res(i, k);
            return 0;
        }
    }
    return 0;
}
