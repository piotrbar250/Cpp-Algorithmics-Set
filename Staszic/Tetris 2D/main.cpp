#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1 << 20, ini = -1;
int n,d;
unordered_map <int,int> tree,lazy;
//vector <int> (2*M+15,ini), lazy(2*M+15,ini);

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
            lazy[2*id] = lazy[2*id+1] = lazy[id];
        tree[id] = lazy[id];
        lazy[id] = ini;
        return;
    }

    void modify(int L, int R, int X)
    {
        if(r < L || l > R)
            return;
        if(r <= R && l >= L)
        {
            lazy[id] = X;
            lazy_update();
            return;
        }
        left().modify(L, R, X);
        right().modify(L, R, X);
        tree[id] = max(tree[2*id],tree[2*id+1]);
    }

    int query(int L, int R)
    {
        if(r < L || l > R)
            return 0;
        if(r <= R && l >= L)
            return tree[id];
        
        int var1 = left().query(L,R);
        int var2 = right().query(L,R);
        return max(var1,var2);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> d >> n;
    for(int i=1; i<=n; i++)
    {
        Node root(1,M,1);
        int a,b;
        cin >> b >> a;
        b += a;
        a++;
        int maxval = root.query(a,b);
        root.modify(a,b,maxval+1);
    }
    cout << tree[1] << endl;
}
