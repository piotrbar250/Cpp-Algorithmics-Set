// Piotr Baranowski
// Zadanie: Gang Biciakow XXVIII Olimpiada Informatyczna

#include <bits/stdc++.h>
using namespace std;

const int M = 1 << 18;
int n, m, z;
int teddy[M], tmpteddy[M], father[M], down[M];

vector<int> adj[M];

struct edge
{
    int a, b;
};

struct query
{
    int z, a, b;
};

query arr[M];
edge graph[M];
int ans[M], res[M];

void root(int x)
{
    for (auto v : adj[x])
    {
        if (v == father[x])
            continue;
        father[v] = x;
        root(v);
    }
}

void solve2()
{
    struct kludge
    {
        static void go_up(int x, unordered_set<int> &mset)
        {
            if (x == 1)
                return;
            mset.insert(teddy[x]);
            go_up(father[x], mset);
        }
    };

    for (int i = 1; i <= z; i++)
    {
        if (arr[i].z == 0)
        {
            unordered_set<int> mset;
            mset.clear();
            kludge::go_up(arr[i].a, mset);
            ans[i] = mset.size();
        }
        else if (arr[i].z == 1)
            teddy[down[arr[i].a]] = arr[i].b;
    }
}

void solve3()
{
    set<int> mset;

    struct kludge
    {
        static void dfs(int x, set<int> &mset)
        {
            bool added = false;
            if (x != 1 and mset.find(teddy[x]) == mset.end())
                mset.insert(teddy[x]), added = true;

            res[x] = mset.size();
            for (auto v : adj[x])
            {
                if (v == father[x])
                    continue;
                dfs(v, mset);
            }
            if (added)
                mset.erase(teddy[x]);
        }
    };
    kludge::dfs(1, mset);

    for (int i = 1; i <= z; i++)
        cout << res[arr[i].a] << "\n";
}

void solve4()
{
    int **tree = new int *[2 * M + 9];
    int *preorder = new int[2 * M + 9], *mx_preorder = new int[M];
    for (int i = 0; i < 2 * M + 9; i++)
        tree[i] = new int[16];

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
            return {l, (l + r) / 2, 2 * id};
        }
        Node right()
        {
            return {(l + r) / 2 + 1, r, 2 * id + 1};
        }
        void modify(int L, int R, int X, int V, int **tree)
        {
            if (l > R || r < L)
                return;
            if (l >= L and r <= R)
            {
                tree[id][X] += V;
                return;
            }
            left().modify(L, R, X, V, tree);
            right().modify(L, R, X, V, tree);
        }

        int query(int pos, int X, int **tree)
        {
            pos += (M - 1);
            int cnt = 0;
            while (pos >= 1)
            {
                cnt += tree[pos][X];
                pos /= 2;
            }
            return (bool)(cnt);
        }
    };
    Node root(1, M, 1);

    static int num = 0;
    struct structure
    {
        static void dfs(int x, int *preorder, int *mx_preorder)
        {
            preorder[x] = ++num;
            mx_preorder[x] = preorder[x];
            for (auto v : adj[x])
                if (v != father[x])
                {
                    dfs(v, preorder, mx_preorder);
                    mx_preorder[x] = max(mx_preorder[x], mx_preorder[v]);
                }
        }
    };

    structure::dfs(1, preorder, mx_preorder);

    for (int i = 2; i <= n; i++)
        root.modify(preorder[i], mx_preorder[i], teddy[i], 1, tree);

    for (int i = 1; i <= z; i++)
    {
        if (arr[i].z == 0)
        {
            int cnt = 0;
            for (int j = 1; j <= m; j++)
                cnt += root.query(preorder[arr[i].a], j, tree);
            ans[i] = cnt;
        }
        else if (arr[i].z == 1)
        {
            root.modify(preorder[down[arr[i].a]], mx_preorder[down[arr[i].a]], teddy[down[arr[i].a]], -1, tree);
            teddy[down[arr[i].a]] = arr[i].b;
            root.modify(preorder[down[arr[i].a]], mx_preorder[down[arr[i].a]], teddy[down[arr[i].a]], 1, tree);
        }
    }
}

void solve5()
{
    set<int> *mset = new set<int>[M];

    for (int i = 1; i < M; i++)
        mset[i].clear();

    int *tree = new int[2 * M + 9];

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
            return {l, (l + r) / 2, 2 * id};
        }
        Node right()
        {
            return {(l + r) / 2 + 1, r, 2 * id + 1};
        }
        void modify(int L, int R, int V, int *tree)
        {
            if (l > R || r < L)
                return;
            if (l >= L and r <= R)
            {
                tree[id] += V;
                return;
            }
            left().modify(L, R, V, tree);
            right().modify(L, R, V, tree);
        }

        int query(int pos, int *tree)
        {
            pos += (M - 1);
            int cnt = 0;
            while (pos >= 1)
            {
                cnt += tree[pos];
                pos /= 2;
            }
            return cnt;
        }
    };
    Node root(1, M, 1);

    for (int i = 2; i <= n; i++)
    {
        if (mset[teddy[i]].size() == 0)
        {
            root.modify(i, n, 1, tree);
        }
        mset[teddy[i]].insert(i);
    }

    for (int i = 1; i <= z; i++)
    {
        if (arr[i].z == 0)
        {
            ans[i] = root.query(arr[i].a, tree);
        }
        else if (arr[i].z == 1)
        {
            if (teddy[down[arr[i].a]] == arr[i].b)
                continue;

            if (mset[teddy[down[arr[i].a]]].size() != 0 and down[arr[i].a] == *mset[teddy[down[arr[i].a]]].begin())
            {
                root.modify(down[arr[i].a], n, -1, tree);
                mset[teddy[down[arr[i].a]]].erase(mset[teddy[down[arr[i].a]]].begin());
                if (mset[teddy[down[arr[i].a]]].size() != 0)
                    root.modify(*mset[teddy[down[arr[i].a]]].begin(), n, 1, tree);
            }
            else
                mset[teddy[down[arr[i].a]]].erase(down[arr[i].a]);

            if (mset[arr[i].b].size() == 0)
                root.modify(down[arr[i].a], n, 1, tree);
            else if (down[arr[i].a] < *mset[arr[i].b].begin())
            {
                root.modify(*mset[arr[i].b].begin(), n, -1, tree);
                root.modify(down[arr[i].a], n, 1, tree);
            }
            mset[arr[i].b].insert(down[arr[i].a]);

            teddy[down[arr[i].a]] = arr[i].b;
        }
    }
}

void output()
{
    for (int i = 1; i <= z; i++)
    {
        if (arr[i].z == 0)
            cout << ans[i] << "\n";
    }
}

void input()
{
    bool onlyZ = true;

    cin >> n >> m >> z;
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tmpteddy[i] = c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        graph[i] = {a, b};
    }

    for (int i = 1; i <= z; i++)
    {
        int x, y = 0;
        char c;
        cin >> c >> x;
        if (c == 'B')
            cin >> y, onlyZ = false;
        arr[i] = {(bool)(y * 1), x, y};
    }

    root(1);
    for (int i = 1; i < n; i++)
    {
        if (graph[i].a == father[graph[i].b])
            down[i] = graph[i].b;
        else
            down[i] = graph[i].a;

        teddy[down[i]] = tmpteddy[i];
    }

    if (n <= 2000 and z <= 2000)
    {
        solve2();
        output();
        return;
    }
    if (onlyZ)
    {
        solve3();
        return;
    }
    if (m <= 15)
    {
        solve4();
        output();
        return;
    }
    solve5();
    output();
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    return 0;
}