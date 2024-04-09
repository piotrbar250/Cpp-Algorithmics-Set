#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 9, N = 2 * 1e6 + 9;
int n,m,k;

vector <int> adj[M];
pair <int, int> edges[N];
vector < pair <int, int> > vec, res;
int F[M];

int _find(int x)
{
    if(F[x] == x)
        return x;
    F[x] = _find(F[x]);
    return F[x];
}

void _union(int a, int b)
{
    if(_find(a) != _find(b))
        F[_find(a)] = _find(b); 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges[i] = {a, b};
    }

    for(int i=1; i<=n; i++)
        F[i] = i;

    for(int i=1; i<=m; i++)
    {
        int a = edges[i].first, b = edges[i].second;

        if(a > k and b > k)
            _union(a, b);
        else
            vec.push_back({a, b});
    }

    for(auto v: vec)
    {
        int a = v.first, b = v.second;
        if(_find(a) != _find(b))
            _union(a, b);
        else
            res.push_back({min(a,b), max(a,b)});
    }

    cout << res.size() << endl;
    for(auto x: res)
        cout << x.first << ' ' << x.second << endl;
    return 0;
}
