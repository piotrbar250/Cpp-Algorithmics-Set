#include <bits/stdc++.h>
using namespace std;

struct Airport
{
    int index;
    int degree;
};

struct Compare
{
    bool operator ()(const Airport &a, const Airport &b) const
    {
        if(a.degree != b.degree)
            return a.degree > b.degree;
        return a.index < b.index;
    }
};

const int M = 509;
int n;
int arr[M];
bool added[M][M];
vector <int> adj[M];
queue <Airport> Q;

set <Airport, Compare> mset;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
        mset.insert({i, a});
    }

    while(mset.size() != 0)
    {
        Airport x = *mset.begin();
        mset.erase(mset.begin());
        for(int i=1; i<=x.degree; i++)
        {
            Airport v = *mset.begin();
            mset.erase(mset.begin());
            Q.push(v);
        }
        while(!Q.empty())
        {
            Airport v = Q.front();
            Q.pop();
            adj[x.index].push_back(v.index);
            adj[v.index].push_back(x.index);
            if(--v.degree != 0)
                mset.insert({v.index, v.degree});
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(auto u: adj[i])
        {
            if(!added[i][u] && !added[u][i])
            {
                cout << i << " " << u << "\n";
                added[i][u] = true;
            }
        }
    }
    
    return 0;
}
