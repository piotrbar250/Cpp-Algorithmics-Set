#include <bits/stdc++.h>
using namespace std;

const int M = 3 * 1e6 + 9;
int n, k;
pair <int, int> res;

vector <int> adj[M], terminal_stations;
int degree[M];
bool cut[M], visited[M];

void cls(queue <int> &Q)
{
    while(!Q.empty())
        Q.pop();
    return;
}

void find_ending(int x)
{
    visited[x] = true;

    if(adj[x].size() == 1)
        terminal_stations.push_back(x);

    for(auto v: adj[x])
    {
        if(!visited[v] and cut[v])
        {
            find_ending(v);
            break;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=1; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    queue <int> Q;
    for(int i=1; i<=n; i++)
        if(degree[i] == 1)
            Q.push(i);
    
    while(!Q.empty())
    {
        if((int)(Q.size()) - k > 0)
            res.first++;
        else
            break;

        queue <int> Q2;
        cls(Q2);

        while(!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            cut[x] = true;

            for(auto u: adj[x])
            {
                degree[u]--;
                if(degree[u] == 1)
                    Q2.push(u);
            }
        }

        Q = Q2;
        cls(Q2);
    }

    vector <int> vec;
    vec.clear();

    ///////////
    //edge case
    int cnt = 0, num;
    for(int i=1; i<=n; i++)
        if(cut[i])
            cnt++;
        else
            num = i;

    if(cnt == n-1)
    {
        vec.push_back(num), vec.push_back(num);
        goto edge_case;
    }
    ///////////

    for(int i=1; i<=n; i++)
        if(!cut[i] and degree[i] == 1)
            vec.push_back(i);

    edge_case:

    res.second = vec.size();

    for(auto u: vec)
        find_ending(u);

    cout << res.first << " " << res.second << endl;
    for(auto u: terminal_stations)
        cout << u << " ";
    
    return 0;
}
