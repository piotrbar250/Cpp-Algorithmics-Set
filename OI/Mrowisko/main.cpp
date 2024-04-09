#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 1e6 + 9;
const ll inf = 1e9 + 9;

int n, g, k;
ll res;

vector <int> adj[M];
int group[M], divisor[M];
int root1, root2;
bool leave[M], visited[M];


void dfs(int x, int curr_div)
{
    visited[x] = true;
    divisor[x] = curr_div;
    if(leave[x])
        return; 
        
    ll child_div = min(inf, (ll)(divisor[x]) * (ll)(adj[x].size() -1) );

    for(auto v: adj[x])
        if(!visited[v] and v != root1 and v != root2)
            dfs(v, child_div);
    return;
}

int binary_search_L(int div)
{
    int l = 1, r = g, md, ind = -1;
    while(l <= r)
    {
        md = (l + r) / 2;
        if(group[md] / div >= k)
        {
            r = md - 1;
            if(group[md] / div == k)
                ind = md;
        }
        else
            l = md + 1;
    }
    return ind;
}

int binary_search_R(int div)
{
    int l = 1, r = g, md, ind = -1;
    while(l <= r)
    {
        md = (l + r) / 2;
        if(group[md] / div <= k)
        {
            l = md + 1;
            if(group[md] / div == k)
                ind = md;
        }
        else
            r = md - 1;
    }
    return ind;
}

void solve()
{
    sort(group+1, group+1+g);
    for(int i=1; i<=n; i++)
    {
        if(!leave[i])
            continue;
        int l = binary_search_L(divisor[i]);
        int r = binary_search_R(divisor[i]);
        if(l != -1)
            res += (r-l+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> g >> k;
    for(int i=1; i<=g; i++)
        cin >> group[i];
    
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(i == 1)
            root1 = a, root2 = b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
        if(adj[i].size() == 1)
            leave[i] = true;
    
    dfs(root1, 1);
    dfs(root2, 1);

    solve();

    cout << res * (ll)(k);
    return 0;
}
