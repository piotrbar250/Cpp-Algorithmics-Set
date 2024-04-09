#include <bits/stdc++.h>
using namespace std;

constexpr int M = 5 * 1e5 + 9;
int n,m;
int num,cnt,order;
int blocks[M], todo[M], todo2[M], toposort[M], fine[M], fine2[M];
int entr[M], entr2[M];
bool vis[M];
vector <int> adj[M], adj2[M], adjc[M];
vector <int> dag[M], dag2[M], cmp[M];
vector <int> tp,res;
stack <int> st;
queue <int> q,q2;
set <int> mset[M]; 

void check_correctness(int x)
{
    cnt++;
    vis[x] = true;
    for(auto v: adjc[x])
        if(!vis[v])
            check_correctness(v);
}

void dfs(int x)
{
    vis[x] = true;
    for(auto v: adj[x])
        if(!vis[v])
            dfs(v);
    st.push(x);
}

void scc(int x) 
{
    vis[x] = true;
    blocks[x] = num;
    cmp[num].push_back(x);
    for(auto v: adj2[x])
        if(!vis[v])
            scc(v);
}

void p()
{
    for(int i=1; i<=n; i++)
        vis[i] = false;
}

void topological_sort()
{
    for(int i=1; i<=num; i++)
        if(entr[i] == 0)
            q.push(i);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        tp.push_back(x);
        for(auto v: dag[x])
        {
            entr[v] --;
            if(entr[v] == 0)
                q.push(v);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
        adjc[a].push_back(b);
        adjc[b].push_back(a);
    }

    check_correctness(1);
    if(cnt != n)
    {
        cout << 0 << endl;
        return 0;
    }

    p();

    for(int i=1; i<=n; i++)
        if(!vis[i])
            dfs(i);
        
    p();

    while(!st.empty())
    {
        int x = st.top();
        st.pop();
        if(!vis[x])
            num++, scc(x);
    }

    for(int i=1; i<=n; i++)
    {
        for(auto j: adj[i])
            if(blocks[i] != blocks[j])
                mset[blocks[i]].insert(blocks[j]);
    }

    for(int i=1; i<=num; i++)
    {
        for(auto it = mset[i].begin(); it != mset[i].end(); it++)
        {
            dag[i].push_back(*it), entr[*it]++;
            dag2[*it].push_back(i), entr2[i]++;
        }
    }

    topological_sort();    
  
    int left = 0;
    for(int i=tp.size()-1; i>=0; i--)
    {
        int x = tp[i];
        for(auto v: dag[x])
        {
            if(todo[v] == true)
            {
                todo[v] = false;
                left--;
            }
        }
        if(left == 0)
            fine[x] = true;
        todo[x] = true;
        left++;
    }

    left = 0;
    for(int i=0; i<tp.size(); i++)
    {
        int x = tp[i];
        for(auto v: dag2[x])
        {
            if(todo2[v] == true)
            {
                todo2[v] = false;
                left--;
            }
        }
        if(left == 0)
            fine2[x] = true;
        todo2[x] = true;
        left++; 
    }

    for(int i=1; i<=n; i++)
        if(fine[blocks[i]] && fine2[blocks[i]])
            res.push_back(i);
            
    cout << res.size() << endl;
    for(auto v: res)
        cout << v << " ";
    return 0;
}
