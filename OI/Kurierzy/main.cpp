#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> T;
constexpr int M = 1 << 19, ini = 0;
int n,m;
int arr[M], val[M], count_val[M], res[M];

struct Interval
{
    int l, r, v, number;
};

vector <int> tree(2*M+9,ini), tree2(2*M+9,ini);
vector <T> vec;

Interval ans[M];
int pos;
vector <Interval> q[M];

class Node
{
public:
    int l, r, id;
    Node(int L, int R, int X)
    {
        l = L;
        r = R;
        id = X;
        return;
    }

    Node left()
    {
        return Node(l, (l+r)/2, 2*id);
    }

    Node right()
    {
        return Node((l+r)/2+1, r, 2*id+1);
    }

    void query(int L, int R)
    {
        if(r < L || l > R)
            return;
        if(r <= R && l >= L)
        {
            vec.push_back({tree[id],tree2[id]});
            return;
        }
        left().query(L,R);
        right().query(L,R);
        return;
    }

    void build()
    {
        for(int i=1; i<=n; i++)
        {
            tree[M+i-1] = arr[i];
            tree2[M+i-1] = 1;
        }

        for(int i=M-1; i>=1; i--)
        {
            if(tree[2*i] == tree[2*i+1])
            {
                tree[i] = tree[2*i];
                tree2[i] = tree2[2*i] + tree2[2*i+1];
            }
            else if(tree2[2*i] > tree2[2*i+1])
            {
                tree[i] = tree[2*i];
                tree2[i] = tree2[2*i] - tree2[2*i+1];
            }
            else if(tree2[2*i+1] > tree2[2*i])
            {
                tree[i] = tree[2*i+1];
                tree2[i] = tree2[2*i+1] - tree2[2*i];
            }
            else if(tree2[2*i] == tree2[2*i+1])
            {
                tree[i] = ini;
                tree2[i] = ini;
            }   
        }
        return;
    }
};

void find_leader(int L, int R)
{
    T pi = {0,0};

    for(auto x: vec)
    {
        if(x.first == pi.first)
        {
            pi.second += x.second;
        }
        else if(x.second > pi.second)
        {
            pi.first = x.first;
            pi.second = x.second - pi.second;
        }
        else if(x.second < pi.second)
        {
            pi.second -= x.second;
        }
        else if(pi.second == pi.second)
        {
            pi.first = ini;     
            pi.second = ini;
        }
    }


    if(pi.first == ini)
        pi.first = -2;
    
    pos++;
    ans[pos] = {L, R, pi.first, pos};
    vec.clear();
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> arr[i];

    Node root(1, M, 1);
    root.build();

    for(int i=1; i<=m; i++)
    {
        Node root(1, M, 1);
        int a, b;
        cin >> a >> b;
        root.query(a, b);
        find_leader(a, b);
    }

    for(int i=1; i<=m; i++)
    {
        q[ans[i].l].push_back(ans[i]);
        q[ans[i].r].push_back(ans[i]);
    }

    for(int i=1; i<=n; i++)
    {
        count_val[arr[i]]++;
        for(auto x: q[i])
        {
            if(x.l == i)
            {
                val[x.number] -= count_val[x.v];
                if(x.v == arr[i])
                    val[x.number]++;

            }
            
            if(x.r == i)
            {
                val[x.number] += count_val[x.v];
                int len = x.r - x.l + 1;
                if(val[x.number] * 2 > len)
                    res[x.number] = x.v;
            }
        }
        
    }

    for(int i=1; i<=m; i++)
        cout << res[i] << "\n";
    return 0;
}
