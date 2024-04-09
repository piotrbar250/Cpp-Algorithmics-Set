#include <bits/stdc++.h>
using namespace std;

const int M = 5009, INF = 1e8;
int n, result;

int dis[M], entr[M], pr[M];
bool done[M], vis[M];

vector <int> adj[M], edge[M];
set < pair<int,int> > mset;

bool dijkstra()
{
    for(int i=1; i<=n; i++)
    {
        dis[i] = INF;
        vis[i] = false;
    }

    dis[1] = 0;
    mset.insert(make_pair(0,1));

    while(!mset.empty())
    {
        int x = mset.begin()->second;
        int d = mset.begin()->first;
        mset.erase(mset.begin());
        if(vis[x] == true)
            continue;
        vis[x] = true;
        for(int i=0; i<adj[x].size(); i++)
        {
            int v = adj[x][i];
            if(x == 1 && v == n)
                continue;
            if(d + edge[x][i] < dis[v] && !done[v])
            {
                dis[v] = dis[x] + edge[x][i];
                pr[v] = x;
                mset.insert(make_pair(dis[v],v));
            }
        }
    }
    if(vis[n])
        return true;
    return false;
}

void recur(int x)
{
    if(pr[x] == 0)
        return;
    if(x != 1 && x != n)
        done[x] = true;
    recur(pr[x]);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1,m; i<n; i++)
    {
        cin>>m;
        for(int j=1,a; j<=m; j++)
        {
            cin>>a;
            if(i == 1 && a == n)
                result++;
            adj[i].push_back(a);
        }
    }

    for(int i=1; i<=n; i++)
        for(auto v: adj[i])
            entr[v]++;

    for(int i=1; i<=n; i++)
        for(auto v: adj[i])
            edge[i].push_back(entr[v]-1);

    while(true)
    {
        if(dijkstra() == true)
        {
            recur(n);
            result++;
        }
        else
            break;
    }
    cout<<result<<endl;
    return 0;
}
