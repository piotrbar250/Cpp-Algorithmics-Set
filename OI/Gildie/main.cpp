#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[200007];
int n,m;
int visited[200007];
int status[200007];
void dfs(int x)
{
    visited[x]=true;
    for(int i=0; i<adj[x].size(); i++)
    {
        if(!visited[adj[x][i]])
        {
            if(status[x]==10) status[adj[x][i]]=20;
            if(status[x]==20) status[adj[x][i]]=10;
            visited[adj[x][i]]=true;
            dfs(adj[x][i]);
        }
    }
}
int main()
{
     ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.tie(NULL);
    cin>>n>>m;
    int pom;
    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        pom=a;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
    {
        if(adj[i].size()==0 || (adj[i].size()==1 && adj[i][0]==i))
        {
            cout<<"NIE";
            return 0;
        }
    }

    status[pom]=10;
    dfs(pom);
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            status[i]=10;
            dfs(i);
        }
    }
    cout<<"TAK"<<endl;
    for(int i=1; i<=n; i++)
    {
        if(status[i]==10)
        {
            cout<<"K"<<endl;
        }
        else
            cout<<"S"<<endl;
    }



}
