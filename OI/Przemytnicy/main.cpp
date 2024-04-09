#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int M = 10009;
const long long INF =9999999999999;
vector<int> adj[M];
vector<int> adj2[M];
vector<int> wart[M];
set< pair<long long,int> > s;
long long dis[M];
bool vis[M];

void Dijkstra(int x)
{
    s.insert(make_pair(0,x));
    while(!s.empty())
    {
        x = s.begin()->second;
        long long akt_odl = s.begin()->first;
        s.erase(s.begin());
        if(vis[x])
            continue;
        vis[x]=true;
        for(int i=0; i<adj[x].size(); i++)
        {
            long long pom_odl = akt_odl + wart[x][i];
            if(pom_odl<dis[adj[x][i]])
            {
                dis[adj[x][i]]=pom_odl;
                s.insert(make_pair(pom_odl, adj[x][i]));
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        adj[i].push_back(n+i);
        wart[i].push_back(a/2);
    }
    int m;
    cin>>m;
    for(int i=1; i<=m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(b);
        wart[a].push_back(c);
        adj[a+n].push_back(b+n);
        wart[a+n].push_back(c);
    }

    for(int i=1; i<=2*n; i++)
        dis[i]=INF;
    dis[1]=0;
    Dijkstra(1);
    cout<<dis[n+1];
}