/// Piotr Baranowski - C++ Developer
/// Task: Sabotage
/// Programming language: C++
/// Algorithms: Binary Search on the result and Dynamic Programming

#include <bits/stdc++.h>
using namespace std;
 
const int M = 1000009;
int n,m;
int number;
long double k;

int l[M], r[M], father[M], dp[M];
bool vis[M];
vector <int> adj[M];
 
void set_range(int x)
{
    l[x] = ++number;
    r[x] = l[x];
    vis[x] = true;
    for(auto v: adj[x])
    {
        if(!vis[v])
        {
            father[v] = x;
            set_range(v);
            r[x] = r[v];
        }
    }
    return;
}

void dfs(int x)
{
    for(auto v: adj[x])
    {
        if(v != father[x])
        {
            dfs(v);            
            dp[x] = max(dp[x], dp[v]);
            long double var = dp[v];
            var /= (r[x] - l[x]);
            if(var > k)
                dp[x] = r[x] - l[x] + 1;
        }
    }
    return;
}
 
bool ok(long long x)
{
    k = x;
    k /= 10000000000;
    for(int i=1; i<=n; i++)
        dp[i] = 1;
    dfs(1);
    if(dp[1] > m)
        return false;
    return true;
}
 
void binary_search_function()
{
    long long b = 0, e = 10000000000, md;
    while(b<e)
    {
        md = (b + e) / 2;
        if(!ok(md))
            b = md + 1;
        else
            e = md;
    }
    long double res = b;
    res /= 10000000000;
    cout<<res<<endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout <<setprecision(10);

    cin>>n>>m;
    for(int i=2; i<=n; i++)
    {
        int a;
        cin>>a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    set_range(1);
    binary_search_function();
    return 0;
}
