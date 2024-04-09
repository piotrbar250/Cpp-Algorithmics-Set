#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n,m;
const int M = 1000009;
int wspol[M];
bool odw[M];
vector<int> adj[M];
vector<int> wart[M];
set< pair<int,int> > s;

template <typename T> T getczary()
{
    int ujemna = false, znak = getchar_unlocked();
    T wynik = (T)0;
    while(!isdigit(znak))
    {
        if(znak == '-')
            ujemna = true;
        znak = getchar_unlocked();
    }
    while(isdigit(znak))
    {
        wynik *= 10;
        wynik += znak - '0';
        znak = getchar_unlocked();
    }
    if(ujemna)
        wynik *= -1;
    return wynik;
}

void Dijkstra(int x)
{
    s.insert(make_pair(0,1));
    while(!s.empty())
    {
        int akt_wpol = s.begin()->first;
        x = s.begin()->second;
        s.erase(s.begin());
        if(odw[x])
            continue;
        odw[x]=true;
        for(int i=0; i<adj[x].size(); i++)
        {
            int pom_wspol = max(akt_wpol, wart[x][i]);
            if(pom_wspol<wspol[adj[x][i]])
            {
                s.insert(make_pair(pom_wspol, adj[x][i]));
                wspol[adj[x][i]]=pom_wspol;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    n=getczary<int>();
    m=getczary<int>();
    for(int i=1; i<=m; ++i)
    {
        int a,b,c;
        a=getczary<int>();
        b=getczary<int>();
        c=getczary<int>();
        adj[a].push_back(b);
        adj[b].push_back(a);
        wart[a].push_back(c);
        wart[b].push_back(c);
    }
    for(int i=1; i<=n; ++i)
        wspol[i]=999999999;
    wspol[1]=0;
    Dijkstra(1);
    for(int i=1; i<=n; ++i)
    {
        if(wspol[i]!=999999999)
            cout<<wspol[i]<<"\n";
        else
            cout<<"-1"<<"\n";
    }
}
