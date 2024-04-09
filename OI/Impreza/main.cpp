#include <bits/stdc++.h>
using namespace std;

const int M = 3009;
int n, m;
int neigh[M][M];
int active[M];
vector <int> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin >> a >> b;
        neigh[a][b] = true;
        neigh[b][a] = true;
        active[a] = active[b] = true;
    }
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(!neigh[i][j] and active[i] and active[j])
                active[i] = active[j] = false;

    for(int i=1; i<=n; i++)
        if(active[i])
            res.push_back(i);

    sort(res.begin(), res.end());

    for(int i=0; i<=(n/3)-1; i++)
        cout << res[i] << ' ';
    return 0;
}
