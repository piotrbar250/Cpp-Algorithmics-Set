#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int max_n=1000 * 1000 +15;
int n,m;
long long k;
int pref[max_n];
bool visited[max_n];
int dis[max_n];
int zlicz[max_n];
int kulki[max_n];
vector<int> adj[max_n];

void bfs(int x)
{
    visited[x]=true;
    dis[x]=0;
    queue<int> Q;
    Q.push(x);
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        for(int i=0; i<adj[x].size(); i++)
        {
            if(!visited[adj[x][i]])
            {
                visited[adj[x][i]]=true;
                Q.push(adj[x][i]);
                dis[adj[x][i]]=dis[x]+1;
            }
        }
    }
}
int main()
{
      ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
    cin>>n>>m>>k;
    for(int i=0; i<n; i++)
    {
        int c;
        cin>>c;
        kulki[i]=c;

    }
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        //adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(0);
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
            dis[i]=-1;

           // cout<<i<<" "<<dis[i]<<endl;
    }
    for(int i=0; i<n; i++)
    {
        if(dis[i]!=-1)
        zlicz[dis[i]]+=kulki[i];
    }

    long long por=0;
    for(int i=0; i<n; i++)
    {
        por+=zlicz[i];
        if(por>k)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<"MASTER";
}
