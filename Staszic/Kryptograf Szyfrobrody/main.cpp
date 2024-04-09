#include <bits/stdc++.h>
using namespace std;

const int M = 1009, INF = 9999999;
typedef tuple <int,int,int> T;
int n,m;
bool found;
char arr[5][M][M];
int dx[5] = {0,1,-1,0,0}, dy[5] = {0,0,0,1,-1};
bool vis[5][M][M];
int dis[5][M][M];
T s,e;
queue <T> Q;

void bfs()
{
    int a = get <1> (s);
    int b = get <2> (s);
    int c = get <0> (s);
    vis[c][a][b];
    dis[c][a][b] = 0;
    Q.push(s);
    while(!Q.empty())
    {
        T x = Q.front();
        Q.pop();
        int a = get <1> (x);
        int b = get <2> (x);
        int c = get <0> (x);
        for(int i=1; i<=4; i++)
        {
            int vx = a + dx[i];
            int vy = b + dy[i];
            if(arr[c][vx][vy] == '#' || arr[c][vx][vy] == '$')
                continue;
            if(!vis[c][vx][vy])
            {
                vis[c][vx][vy] = true;
                Q.push(make_tuple(c,vx,vy));
                dis[c][vx][vy] = dis[c][a][b] + 1;
            }
        }
        if(arr[c][a][b] == 'K')
        {
            vis[c+2][a][b] = true;
            dis[c+2][a][b] = dis[c][a][b] + 1;
            Q.push(make_tuple(c+2,a,b));
        }
        if(arr[c][a][b] == '|')
        {
            int var;
            if(c == 1 || c == 3)
                var = 1;
            else if(c == 2 || c == 4)
                var = -1;
            if(!vis[c+var][a][b])
            {
                vis[c+var][a][b] = true;
                dis[c+var][a][b] = dis[c][a][b] + 1;
                Q.push(make_tuple(c+var,a,b));
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int k=1; k<=4; k++)
        for(int i=0; i<=n+1; i++)
            for(int j=0; j<=m+1; j++)
            {
                arr[k][i][j] = '#';
                dis[k][i][j] = INF;
            }
    
    for(int k=1; k<=2; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                cin >> arr[k][i][j];
                arr[k+2][i][j] = arr[k][i][j];

                if(arr[k][i][j] == 'P')
                    s = make_tuple(k,i,j);
                if(arr[k][i][j] == 'X')
                    e = make_tuple(k,i,j);
                if(arr[k][i][j] == 'K' || arr[k][i][j] == '$')
                    arr[k+2][i][j] = '.';
            }
    bfs();

    if(dis[get<0>(e)][get<1>(e)][get<2>(e)] == INF && dis[get<0>(e)+2][get<1>(e)][get<2>(e)] == INF)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << min(dis[get<0>(e)][get<1>(e)][get<2>(e)],dis[get<0>(e)+2][get<1>(e)][get<2>(e)]) << endl;
    return 0;
}
