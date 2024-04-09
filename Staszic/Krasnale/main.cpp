// Piotr Baranowski - C++ Developer
// Task: Krasnale
// Language: C++
// Algorithm: Bit Mask

#include <bits/stdc++.h>
using namespace std;

const int M = (1 << 19) + 100;
int n,m;

long long dp[M];
pair <int,int> arr[25*25];
bool vis[M], bad[M];

void init()
{
    for(int i=1; i<=19; i++)
    {
        dp[1<<(i-1)] = 1;
        vis[1<<(i-1)] = true;
    }

    for(int i=1; i<(1<<19); i++)
    {
        for(int j=1; j<=m; j++)
        {
            bool ok1 = (1<<(arr[j].first-1))&i;
            bool ok2 = (1<<(arr[j].second-1))&i;

            if(ok2 == true && ok1 == false)
            {
                bad[i] = true;
                break;
            }
        }
    }
}

long long solve(int x)
{
    if(bad[x] == true)
        return 0;
    if(vis[x] == true)
        return dp[x];

    for(int i=1; i<=n; i++)
        if(((1<<(i-1))&x) != 0)
            dp[x]+= solve((~(1<<(i-1)))&x);

    vis[x] = true;
    return dp[x];
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
        cin>>arr[i].first>>arr[i].second;
    init();
    cout<<solve((1<<n)-1);
    return 0;
}
