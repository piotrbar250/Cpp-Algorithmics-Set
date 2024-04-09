#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1 << 16, ini = 0;
int n,m,z;
//vector <int> 
map<int,int> tree, lazy;

class Node
{ 
public:
    int l,r,id;
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
        {
            lazy[2*id] += lazy[id];
            lazy[2*id+1] += lazy[id];
        }
        tree[id] += lazy[id];
        lazy[id] = ini;
    }

    void modify(int L, int R, int X )
    {
        if(l > R || r < L)
            return;
        if(r <= R && l >= L)
        {
            lazy[id] = X;
            lazy_update();
            return;
        }
        left().modify(L,R,X);
        right().modify(L,R,X);
        tree[id] = max(tree[2*id], tree[2*id+1]);
        return;
    }

    int query(int L, int R)
    {
        if(l > R || r < L)
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
    cin.tie();
    cout.tie();

    cin >> n >> m >> z;
    for(int i=1; i<=z; i++)
    {
        Node root(1,M,1);
        int a,b,c;
        cin >> a >> b >> c;
        b--;
        int var = root.query(a,b);
        // cout << "var " << var << endl;
        if(var+c <= m)
        {
            cout << "T" << endl;
            root.modify(a,b,c);
        }
        else
            cout << "N" << endl;
    }

}
