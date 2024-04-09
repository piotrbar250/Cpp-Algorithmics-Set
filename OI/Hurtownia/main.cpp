#include <bits/stdc++.h>
using namespace std;

const int M = 1 << 18, inf = 1e9 + 100;
int n;
int delivery[M], customer[M];

struct Item
{
    int index;
    int value;
};

Item tree[2*M + 10];
vector <int> results;

bool cmp(const Item &a, const Item &b)
{
    if(a.value != b.value)
        return a.value < b.value;
    
    return a.index < b.index;
}

class Node
{
public:
    int L, R, id;
    Node(int l, int r, int x)
    {
        L = l;
        R = r;
        id = x;
    }

    Node left()
    {
        return Node(L, (L+R)/2, 2*id);
    }

    Node right()
    {
        return Node((L+R)/2+1, R, 2*id+1);
    }

    void build()
    {
        for(int i=1; i<2*M; i++)
            tree[i] = {inf, inf};
        return;
    }

    void modify(int pos, int x)
    {
        int curr_pos = pos + M - 1;
        tree[curr_pos] = {pos, x};
        curr_pos /= 2;
        while(curr_pos >= 1)
        {
            tree[curr_pos] = min(tree[curr_pos*2], tree[curr_pos*2+1], cmp);
            curr_pos /= 2;
        }
        return;
    }

    Item query(int l, int r)
    {
        if(L > r or R < l)
            return {inf, inf};
        if(L >= l and R <= r)
            return tree[id];

        Item i1 = left().query(l, r);
        Item i2 = right().query(l, r);
        return min(i1, i2, cmp);
    }
};

bool proceed(Node &root, int i)
{
    auto var = root.query(i, n);
    if(var.value == inf)
        return false;
    if(delivery[i] == 0 and var.value != 0)
        return false;
    
    return true;
} 

void solve()
{
    Node root(1, M, 1);
    root.build();

    for(int i=n; i>=1; --i)
    {
        root.modify(i, customer[i]);
        while(proceed(root, i))
        {
            auto var = root.query(i, n);
            if(var.value == delivery[i])
            {
                delivery[i] = 0;
                root.modify(var.index, inf);
                results.push_back(var.index);
            }
            else if(var.value < delivery[i])
            {
                delivery[i] -= var.value;
                root.modify(var.index, inf);
                results.push_back(var.index);
            }
            else if(var.value > delivery[i])
            {
                root.modify(var.index, var.value - delivery[i]);
                delivery[i] = 0;
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> delivery[i];

    for(int i=1; i<=n; ++i)
        cin >> customer[i];

    solve();

    sort(results.begin(), results.end());
    
    cout << results.size() << '\n';

    for(auto p: results)
        cout << p << ' ';

    return 0;
}
