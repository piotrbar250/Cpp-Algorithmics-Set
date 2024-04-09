#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 9, N = 1e6 + 9;
int n, m;
vector < pair <int,int> > adj[M];
vector <int> cycle[N];
int ind;
int pointer[M];

bool vis_new[M], vis_edge[N];

bool found;
int origin;
int vertex;

stack <int> sta;

void dfs(int x)
{
    vis_new[x] = true;
    sta.push(x);

    for(int i = pointer[x]; i < adj[x].size(); i++)
    {
        auto v = adj[x][i];
        pointer[x]++;

        if(vis_edge[v.second])
            continue;
        vis_edge[v.second] = true;

        if(vis_new[v.first])
        {
            cycle[++ind].push_back(v.first);
            while(sta.top() != v.first)
            {
                cycle[ind].push_back(sta.top());
                sta.pop();
            }
            cycle[ind].push_back(v.first);

            vis_new[x] = false;

            if(v.first == origin)
            {
                found = true;
                sta.pop();
                return;
            }

            vertex = v.first;
            return;
        }

        dfs(v.first);

        if(found)
        {
            vis_new[x] = false;
            return;
        }

        if(vertex != 0 and vertex != x)
        {
            vis_new[x] = false;
            return;
        }

        if(vertex == x)
            vertex = 0;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int edge_num = 0;

    for(int i=1; i<=m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if(c != d)
        {
            adj[a].push_back({b, ++edge_num});
            adj[b].push_back({a, edge_num});
        }
    }

    for(int i=1; i<=n; i++)
        if(adj[i].size() % 2 == 1)
        {
            cout << "NIE" << endl;
            return 0;
        }
    
    for(int i=1; i<=n; i++)
    {
        for(auto v: adj[i])
        {
            if(!vis_edge[v.second])
            {
                found = false;
                origin = i;
                dfs(i);       
            }
        }
    }

    cout << ind << endl;
    for(int i=1; i<=ind; i++)
    {
        cout << cycle[i].size() - 1 << ' ';
        for(auto v: cycle[i])
            cout << v << ' ';
        cout << endl;
    } 
}
