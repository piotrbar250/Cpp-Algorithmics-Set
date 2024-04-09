#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 1e5 + 9;
const ll mod = 1e9 + 7;
int n, m, z;

long long fast_ex(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 1)
    {
        ll var = (fast_ex(a, b - 1) * a) % mod;
        return var;
    }
    ll k = fast_ex(a, b / 2);
    ll var = (k * k) % mod;
    return var;
}

vector<int> adj[M];
set<int> val;
int ac[M];
bool vis[M];
int counter;

void dfs(int x)
{
    vis[x] = true;
    counter++;
    for (auto v : adj[x])
        if (!vis[v])
            dfs(v);
}

void solve4p()
{
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            dfs(i);
            val.insert(counter);
            ac[counter]++;
            counter = 0;
        }
}

void solve4(ll k)
{
    ll res = 1;
    for (auto it = val.begin(); it != val.end(); it++)
    {
        ll z = *it;
        ll var = fast_ex(k - 1, z);
        if (z % 2 == 0)
            var += (k - 1);
        if (z % 2 != 0)
            var -= (k - 1);

        var += mod;
        var = var % mod;
        var = fast_ex(var, ac[z]);

        res *= var;
        res = res % mod;
    }
    cout << res << endl;
}

int main()
{
    bool task4 = true;
    cin >> n >> m >> z;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (adj[i].size() != 2)
            task4 = false;
    if (task4)
        solve4p();
    for (int i = 1; i <= z; i++)
    {
        long long a;
        cin >> a;
        if (task4)
            solve4(a);
        else
            cout << "w budowie" << endl;
    }
}