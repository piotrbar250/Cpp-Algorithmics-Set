#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define sp " "

const int M = 500009;
int n;

int anc[M][30], depth[M];
long long dis[M];
bool vis[M];

vector<int> tree[M];
vector<int> val[M];
queue<int> Q;

void bfs(int x)
{
    Q.push(x);
    depth[x]=1;
    while(!Q.empty())
    {
        x = Q.front();
        Q.pop();

        vis[x]=true;
        for(int i=0; i<tree[x].size(); i++)
        {
            int v = tree[x][i];
            if(!vis[v])
            {
                Q.push(v);
                anc[v][0]=x;
                depth[v]=depth[x]+1;
                dis[v]=dis[x]+val[x][i];
            }
        }

        for(int i=1; i<=20; i++)
            anc[x][i]=anc[anc[x][i-1]][i-1];
    }
}

int conf(int a, int target)
{
    for(int i=20; i>=0; i--)
        if(depth[anc[a][i]]>=target)
            a=anc[a][i];
    return a;
}

int LCA(int a, int b)
{
    for(int i=20; i>=0; i--)
    {
        if(anc[a][i]!=anc[b][i])
        {
            a=anc[a][i];
            b=anc[b][i];
        }
    }
    if(a!=b)
        return anc[a][0];
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        tree[a].push_back(b);
        tree[b].push_back(a);
        val[a].push_back(c);
        val[b].push_back(c);
    }
    bfs(1);

    while(true)
    {
        int a,b,x,y;
        cin>>a;
        if(a==-1)
            break;
        cin>>b;
        x=a; y=b;
        if(depth[a]<depth[b])
            swap(a,b);
        a = conf(a,depth[b]);
        int v = LCA(a,b);
        cout<<dis[x]+dis[y]-2*dis[v]<<endl;
    }
}
