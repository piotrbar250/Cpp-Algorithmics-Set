#include <bits/stdc++.h>
using namespace std;

const int M = 509;
int n;

vector <int> adj[M], commanders;
int sign[M];

bool visited[M];

void dfs(int x)
{
    visited[x] = true;

    for(auto u: adj[x])
    {
        if(!visited[u] and sign[u] != n + 1)
        {
            if(sign[u] == 0)
                sign[u] = sign[x];
            else
                sign[u] = n + 1;
            
            dfs(u);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int k;
        cin >> k;
        if(k == 0)
        {
            commanders.push_back(i);
            sign[i] = i;
            continue;
        }

        for(int j=1; j<=k; j++)
        {
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
    }

    for(auto u: commanders)
    {
        for(int i=1; i<=n; i++)
            visited[i] = false;

        dfs(u);
    }

    bool done = false;
    for(int i=1; i<=n; i++)
        if(sign[i] != n+1 and sign[i] != i)
            cout << i << endl, done = true;

    if(!done)
        cout << "BRAK" << endl;

    return 0;
}
