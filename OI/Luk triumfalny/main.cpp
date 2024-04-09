#include <bits/stdc++.h>
using namespace std;

const int M = 3 * 1e5 +9;
int n;
int rv;
vector <int> adj[M];

int check(int md, int x, int px)
{   
    if(adj[x].size() == 1 && adj[x][1] == px)
        return 0;

    int dp = 0;
    for(auto v: adj[x])
    {
        if(v == px)
            continue;
        dp += check(md,v,x);
    }

    return abs(min(0,md - (int)(adj[x].size()) + 1 - dp));
}

void binary_search_function()
{
    int l = adj[1].size()-1, r = rv, md;
    while(l < r)
    {
        md = (l + r) / 2;
        if(check(md,1,0) > 0)
            l = md + 1;
        else
            r = md;
    }
    cout << l << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    adj[1].push_back(0);

    for(int i=1; i<=n; i++)
        rv = max(rv,(int)(adj[i].size())-1);
    binary_search_function();
}
