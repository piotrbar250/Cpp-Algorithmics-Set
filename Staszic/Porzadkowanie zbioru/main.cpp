#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 9;
vector<int> adj[M], order;
queue<int> Q;

int n, m;
int in[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }

    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            Q.push(i);

    while (!Q.empty())
    {
        if (Q.size() > 1)
        {
            cout << "NIE";
            return 0;
        }
        int x = Q.front();
        Q.pop();
        order.push_back(x);

        for (int v : adj[x])
            if (--in[v] == 0)
                Q.push(v);
    }
    if(order.size() != n)
    {
        cout << "NIE";
        return 0;
    }
    cout << "TAK" << endl;
    for (int x : order)
        cout << x << ' ';
}
