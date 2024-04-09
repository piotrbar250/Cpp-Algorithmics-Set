#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int M = 100009;
int n;

int anc[M][30], depth[M];
bool vis[M];

vector<int> tree[M];
queue<int> Q;

void bfs(int x)
{
    depth[1]=1;
    Q.push(1);

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
                depth[v]=depth[x]+1;
                anc[v][0]=x;
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

bool check(int a, int b, int c)
{
    int x=a, y=b, z=c;
    bool okA=false, okB=false;

    if(depth[a]>=depth[c])
    {
        a=conf(a,depth[c]);
        if(LCA(a,c)==c)
            okA=true;
    }

    if(depth[b]>=depth[c])
    {
        b=conf(b,depth[c]);
        if(LCA(b,c)==c)
            okB=true;
    }

    if(depth[x]<depth[y])
        swap(x,y);
    x=conf(x,depth[y]);
    int res=LCA(x,y);

    if((okA==true && okB==false)||(okA==false && okB==true)||(okA==true && okB==true && res==c))
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    bfs(1);

    int z;
    cin>>z;
    for(int i=1; i<=z; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(check(a,b,c))
            cout<<"TAK"<<endl;
        else
            cout<<"NIE"<<endl;
    }
}
