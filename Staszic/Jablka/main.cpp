#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=1000007;
vector<int> adj[MAX_N];
bool visited[MAX_N];
int dis[MAX_N];

void bfs(int v)
{
    visited[v]=true;
    queue<int> Q;
    Q.push(v);
    while(!Q.empty())
    {
        v=Q.front();
        Q.pop();
        for(int i=0; i<adj[v].size(); i++)
        {
            if(!visited[adj[v][i]])
            {
                visited[adj[v][i]]=true;
                Q.push(adj[v][i]);
                dis[adj[v][i]]=dis[v]+1;
            }
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
cin.tie(NULL);
    int n,m;
    int buf=0;
    cin>>n;
    m=n-1;///liczba krawedzi
    for(int i=0,a,b; i<m; i++)
    {
        cin>>a>>b;
        if(i==0) buf=a;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ///cout<<buf;
    dis[buf]=0;
    bfs(buf);
    ///petla pokazujaca wyniki bfs dla buf
   /* for(int i=1; i<=n; i++)
    {
        cout<<"Odleglosc dla "<<i<<" rowna sie "<<dis[i]<<endl;
    }
    */
    int maks=0;
    for(int i=1; i<=n; i++)
    {
        if(dis[i]>dis[maks])
        maks=i;
    }
    ///cout<<endl<<"maks to "<<maks;
    ///cout<<endl<<endl<<endl;
    for(int i=1; i<=n; i++)
        {
            visited[i]=false;
            dis[i]=-1;
        }
    dis[maks]=0;
    bfs(maks);
   /*  for(int i=1; i<=n; i++)
    {
        cout<<"Odleglosc dla "<<i<<" rowna sie "<<dis[i]<<endl;
    }
    */
    maks=0;
    for(int i=1; i<=n; i++)
    {
        if(dis[i]>maks)
        maks=dis[i];
    }
    cout<<maks;

}
