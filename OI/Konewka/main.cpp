#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1 << 20, ini = 0;
constexpr long long in = 1e9 * (-1) - 5;
int N, K;
vector <long long> tree(2*M+15,ini), lazy(2*M+15,ini), grown(2*M+15,ini);

class Node
{
public:
    int l, r, id;
    Node(int L, int R, int X)
    {
        l = L;
        r = R;
        id = X;
        lazy_update();
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
    
    void lazy_update()
    {   
        if(lazy[id] == ini)
            return;
        if(l != r)
        {
            lazy[2*id] += lazy[id];
            lazy[2*id+1] += lazy[id];
        }
        tree[id] += lazy[id];
        lazy[id] = ini;
        return;
    }

    void modify(int L, int R, int X)
    {
        if(r < L || l > R)
            return;
        if(r <= R && l >= L)
        {
            lazy[id] += X;
            lazy_update();
            return;
        }
        left().modify(L,R,X);
        right().modify(L,R,X);
        tree[id] = max(tree[2*id],tree[2*id+1]);
        return;
    }

    int query(int L, int R)
    {
        if(r < L || l > R)
            return 0;
        if(r <= R && l >= L)
        {
            while(tree[id] >= K)
                extract();
            return grown[id];
        }
        int var1 = left().query(L,R);
        int var2 = right().query(L,R);
        tree[id] = max(tree[2*id],tree[2*id+1]);
        return (var1 + var2);
    }

    void extract()
    {
        if(l == r)
        {
            int x = id;
            grown[x]++;
            tree[x] = in;
            x /= 2;
            while(x >= 1)
            {
                grown[x]++;
                tree[x] = max(tree[2*x],tree[2*x+1]);
                x /= 2;
            }
            return;
        }
        left();
        right();
        if(tree[id*2] >= K)
            left().extract();
        else if(tree[id*2+1] >= K)
            right().extract();
        return;
    }

    void build()
    {
        for(int i=M-1; i>=1; i--)
            tree[i] = max(tree[2*i],tree[2*i+1]);
        return;
    }
};

void inicjuj(int n, int k, int *D)
{   
    N = n;
    K = k;
    Node root(1,M,1);
    for(int i=1; i<=N; i++)
        tree[M+i-1] = D[i-1];
    root.build();
    return;
}

void podlej(int a, int b)
{
    a++, b++;
    Node root(1,M,1);
    root.modify(a,b,1);
    return;
}

int dojrzale(int a, int b)
{
    a++, b++;
    Node root(1,M,1);
    int res = root.query(a,b);
    return res;
}
