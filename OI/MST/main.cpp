#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int id, a, b, w;
};

const int M = 1e6 + 9;
int n, m, cost;
vector<vector<int>> adj(M, vector<int>());
vector<edge> arr(M, {0, 0, 0});
vector<int> F(M, 0), res;

bool cmp(const edge &a, const edge &b)
{
    return a.w < b.w;
}

// Find and union

int _find(int x)
{
    if (F[x] == x)
        return x;
    F[x] = _find(F[x]);
    return F[x];
}

void _union(edge e)
{
    if (_find(e.a) != _find(e.b))
    {
        F[_find(e.a)] = _find(e.b);
        cost += e.w;
        cout << e.id << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adj[b].push_back(a);
        arr[i] = {i, a, b, w};
    }

    for (int i = 1; i <= n; i++)
        F[i] = i;

    sort(arr.begin() + 1, arr.begin() + m + 1, cmp);

    for (int i = 1; i <= m; i++)
        _union(arr[i]);
    return 0;
}
