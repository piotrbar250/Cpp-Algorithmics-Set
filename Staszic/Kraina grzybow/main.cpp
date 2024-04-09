#include "bits/stdc++.h"
using namespace std;

const int M = 1000*1000+6;
int n,m,A,B;

vector <int> adj[M];
queue <int> Q;
int wejscia[M];
int arr[M];
long long dp[M];
int licznik=1;
void toposort()
{
    while (Q.size())
    {
        int x = Q.front();
        Q.pop();
        arr[licznik]=x;
        licznik++;

        for (int i = 0; i < adj[x].size(); i++)
        {
            wejscia[adj[x][i]]--;
            if (wejscia[adj[x][i]] == 0)
                Q.push(adj[x][i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int p=0;
    cin>>n>>m>>A>>B;

    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        wejscia[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (wejscia[i] == 0)
            Q.push(i);
    }

    toposort();
    licznik--;
    /*for(int i=1; i<=licznik; i++)
        cout<<arr[i]<<" ";
    cout<<endl<<endl;*/

    dp[B]=1;
    int q=1000*1000*1000+9;
    for(int i=licznik-1; i>=1; i--)
    {
        int buf=arr[i];
        for(int j=0; j<adj[buf].size(); j++)
            dp[buf]+=dp[adj[buf][j]]%q;
    }

    cout<<dp[A]%q;
