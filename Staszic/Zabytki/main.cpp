/// Piotr Baranowski - C++ Developer
/// Task: Zabytki
/// Programming language: C++
/// ALgorithms: Binary Search on the result and topological sort
/// Complexity: O(n*logn)

#include <bits/stdc++.h>
using namespace std;

const int M = 1000009;
int n,m, result;

vector <int> adj[M];
queue <int> Q;
pair <int,int> arr[M];
int entr[M];
bool vis[M];

bool is_cycle(int md)
{
    bool inv[M];
    for(int i=1; i<=n; i++)
    {
        adj[i].clear();
        vis[i] = false;
        inv[i] = false;
        entr[i] = 0;
    }

    for(int i=1; i<=md; i++)
    {
        int a = arr[i].first;
        int b = arr[i].second;

        adj[a].push_back(b);
        entr[b]++;
        inv[a] = true;
        inv[b] = true;
    }

    for(int i=1; i<=n; i++)
        if(entr[i] == 0 && inv[i])
            Q.push(i);

    /// Topological Sort
    while(!Q.empty())
    {
        int x = Q.front();
        vis[x] = true;
        Q.pop();

        for(int i=0; i<adj[x].size(); i++)
        {
            entr[adj[x][i]]--;
            if(entr[adj[x][i]] == 0)
                Q.push(adj[x][i]);
        }
    }

    for(int i=1; i<=n; i++)
        if(!vis[i] && inv[i])
            return true;
    return false;
}

void binary_search_function()
{
    // Binary Search on the result
    int l = 1, r = m, md;
    while(l<r)
    {
        md = (l + r) / 2;
        if(!is_cycle(md))
            l = md + 1;
        else
            r = md;
    }

    result = l; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        arr[i].first = a;
        arr[i].second = b;
    }

    if(!is_cycle(m))
    {    
        cout<<"NIE"<<endl;
        return 0;
    }   

    binary_search_function();
    cout<<result<<endl;

    return 0;
}
