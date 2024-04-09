#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1 << 20, ini = -1;
int n,m;
vector <int> tree(2*M+15,0);

class Node
{
public:
    int l, r, id;

    Node(int L, int R, int X)
    {
        l = L;
        r = R;
        id = X;
    }
    
    Node left()
    {
        return Node(l, (l+r)/2, 2*id);
    }

    Node right()
    {
        return Node((l+r)/2 + 1, r, 2*id+1);
    }

    Node up()
    {
        return Node(ini, ini, id/2);
    }

    void modify(int L, int R, int X)
    {
        if(r < L || l > R)
            return;
        if(r <= R && l >= L)
        {
            tree[id] += X;
            return;
        }
        left().modify(L, R, X);
        right().modify(L, R, X);
        return;
    }

    int check_status()
    {
        if(id == 0)
            return 0;
        return tree[id] + up().check_status();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    for(int i=1; i<=n; i++)
        if(s[i] != 'x')
            tree[i+M-1] = 1;

    for(int i=1; i<=m; i++)
    {
        char c;
        cin >> c;
        if(c == 'Q')
        {
            int v;
            cin >> v;
            Node x(ini,ini,v+M-1);
             if(x.check_status() % 2 == 0)
                cout << "OFF" << endl;
            else
                cout << "ON" << endl;
        }
        else
        {
            int L, R;
            cin >> L >> R;
            Node root(1,M,1);
            root.modify(L, R, 1);
        }
    }
    return 0;
}
