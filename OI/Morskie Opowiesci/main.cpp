// Piotr Baranowski - C++ Developer
// Task: Morskie Opowiesci
// Programming Language: C++

#include <bits/stdc++.h>
using namespace std;

const int M = 5009, N = 1000009, INF = 9000;
int n,m;
int k;

int dis[M][3];
bool ans[N];
bool vis[M][3];

struct query
{
    int b;
    int c;
    int number;
};

vector <int> adj[M];
vector <query> lis[N];
queue <int> Q;

void bfs(int x)
{
    Q.push(x);
    while(!Q.empty())
    {
        x = Q.front();
        Q.pop();

        for(int i=0; i<adj[x].size(); i++)
        {
            int v = adj[x][i];
            if(vis[v][1] == false && vis[x][2] == true)
            {
                vis[v][1] = true;
                dis[v][1] = dis[x][2] + 1;
                Q.push(v);
            }

            if(vis[v][2] == false && vis[x][1] == true)
            {
                vis[v][2] = true;
                dis[v][2] = dis[x][1] + 1;
                Q.push(v);
            } 
        }
    }
    return;
}

void conf()
{
    for(int i=1; i<=n; i++)
    {
        vis[i][1] = false;
        vis[i][2] = false;
        dis[i][1] = INF;
        dis[i][2] = INF;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=k; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        query x;
        x.b = b;
        x.c = c;
        x.number = i;

        lis[a].push_back(x);
    }

    for(int i=1; i<=n; i++)
    {
        if(lis[i].size() != 0)
        {
            conf();
            vis[i][2] = true;
            dis[i][2] = 0;
            bfs(i);
            for(int j=0; j<lis[i].size(); j++)
            {
                int v = lis[i][j].b;
                int c = lis[i][j].c;
                int tim = lis[i][j].number;

                if(i == v && adj[i].size() == 0)
                {
                   ans[tim] = false;
                   continue;
                }

                if(c%2 == 0)
                {
                    if(vis[v][2] == true && dis[v][2] <= c)
                        ans[tim] = true;
                    else
                        ans[tim] = false;
                }

                if(c%2 == 1)
                {
                    if(vis[v][1] == true && dis[v][1] <= c)
                        ans[tim] = true;
                    else
                        ans[tim] = false;
                }

            }
        }
    }

    for(int i=1; i<=k; i++)
    {
        if(ans[i] == true)
            cout<<"TAK"<<"\n";
        else
            cout<<"NIE"<<"\n";
    }
    return 0;
}
