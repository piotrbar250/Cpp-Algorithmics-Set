#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int M = 100009;
const long long INF = 9999999999999;
int n,m;

long long dis[M];
bool vis[M],vis2[M];

vector<int> adj[M];
vector<int> val[M];
vector<int> vec;
set< pair<long long, int> > s;

void Dijkstra(int x)
{
    for(int i=2; i<=n; i++)
        dis[i]=INF;
    s.insert(make_pair(0,x));
    while(!s.empty())
    {
        int x = s.begin()->second;
        long long curr_dis = s.begin()->first;

        s.erase(s.begin());
        if(vis[x])
            continue;
        vis[x]=true;
        for(int i=0; i<adj[x].size(); i++)
        {
            int v =adj[x][i];
            long long help_dis = curr_dis + val[x][i];

            if(help_dis<dis[v])
            {
                dis[v] = help_dis;
                s.insert(make_pair(help_dis, v));
            }
        }
    }
}

void dfs(int x)
{
    vis2[x]=true;
    vec.push_back(x);
    for(int i=0; i<adj[x].size(); i++)
        if(!vis2[adj[x][i]] && dis[adj[x][i]]+val[x][i]==dis[x])
            dfs(adj[x][i]);
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        val[a].push_back(c);
        val[b].push_back(c);
    }
    Dijkstra(1);
    dfs(n);
    sort(vec.begin(), vec.end());

    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<endl;
}
