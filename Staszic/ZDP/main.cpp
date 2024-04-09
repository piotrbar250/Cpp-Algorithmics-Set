#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int M = 500009;
const long long INF = 9999999999999999;
vector<int> adj[M];
vector<int> wart[M];
set< pair<long long,int> > s;

long long dis[M];
bool vis[M];

void Dijkstra(int x)
{
    s.insert(make_pair(0,x));
    while(!s.empty())
    {
        x = s.begin()-> second;
        long long akt_odl = s.begin()-> first;
        s.erase(s.begin());
        if(vis[x])
            continue;
        vis[x]=true;

        for(int i=0; i<adj[x].size(); i++)
        {
            long long pom_odl = akt_odl + wart[x][i];
            if(pom_odl<dis[adj[x][i]])
            {
                dis[adj[x][i]] = pom_odl;
                s.insert(make_pair(pom_odl, adj[x][i]));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        wart[a].push_back(c);
        wart[b].push_back(c);
    }
    for(int i=1; i<=n; i++)
        dis[i]=INF;
    dis[1]=0;
    Dijkstra(1);

    for(int i=1; i<=n; i++)
    {
        if(dis[i]==INF)
            cout<<"-1"<<endl;
        else
            cout<<dis[i]<<endl;
    }
}
