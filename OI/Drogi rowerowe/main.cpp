#include <bits/stdc++.h>
using namespace std;

const int M = 5 * 1e4 + 9;
int n,m;
int num;
int blocks[M], blsize[M];
int dp[M];
vector <int> adj[M], adj2[M], dag[M];
stack <int> st;
bool vis[M];

void dfs(int x)
{
    vis[x] = true;
    for(auto v: adj[x])
        if(!vis[v])
            dfs(v);
    st.push(x); 
    return;
}

void scc(int x)
{
    vis[x] = true;
    blocks[x] = num;
    blsize[num]++;
    for(auto v: adj2[x])
        if(!vis[v])
            scc(v);
    return; 
}

void cnt(int x)
{
    vis[x] = true;
    for(auto v: dag[x])
    {
        if(!vis[v])
            cnt(v);
        dp[x] += dp[v];
    }
    return;
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
        if(!vis[i])
            dfs(i);

    for(int i=1; i<=n; i++)
        vis[i] = false;

    while(!st.empty())
    {
        int x = st.top();
        st.pop();
        if(!vis[x])
            num++ , scc(x);
    }

    for(int i=1; i<=n; i++)
        for(auto v: adj[i])
            if(blocks[i] != blocks[v])
                dag[blocks[i]].push_back(blocks[v]);
    
    for(int i=1; i<=n; i++)
    {
        vis[i] = false;
        dp[i] = blsize[i];
    }
 
    for(int i=1; i<=num; i++)
        if(!vis[i])
            cnt(i);

    for(int i=1; i<=n; i++)
        cout << dp[blocks[i]] - 1 << endl;
    return 0;
}
