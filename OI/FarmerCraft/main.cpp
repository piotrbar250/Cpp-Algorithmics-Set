#include <bits/stdc++.h>
using namespace std;

const int M = 5 * 1e5 + 9;
int n;
int c[M], w[M];
int dp[M];
vector <int> adj[M];
vector <pair <int,int> > container;
bool vis[M];

bool cmp(pair <int,int> a, pair <int,int> b)
{
    if(a.first != b.first)  
        return a.first > b.first;
    return a.second < b.second;
}

void predfs(int x, int px)
{
    w[x] = 1;
    for(auto v: adj[x])
    {
        if(v != px)
        {
            predfs(v,x);
            w[x] += w[v];
        }
    }
}

void dfs(int x)
{
    vector <pair <int,int> > container;
    vis[x] = true;
    for(auto v: adj[x])
    {
        if(!vis[v])
        {
            dfs(v);
            container.push_back({dp[v] + 2*(w[x]-1) - 2*(w[v]-1), v});
        }
    }
    sort(container.begin(), container.end(), cmp);
    int k = 1;
    for(auto p: container)
    {
        int v = p.second;
        dp[x] = max(dp[x], dp[v]+k);
        k += 2;
        k += 2*(w[v]-1);
    }
    container.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> c[i];
        dp[i] = c[i];
    }
    dp[1] += 2*(n-1);

    for(int i=1; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    predfs(1,0);
    dfs(1);
    cout << dp[1] << endl;
    return 0;
}