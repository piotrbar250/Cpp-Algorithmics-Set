// Piotr Baranowski
// Zadanie: Licznik dlugu XXVIII Olimpiada Informatyczna

#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 9, N = 1 << 17, inf = 100;
int n, q;
int current_time;
bool is9[N];
string number[3];

struct update
{
    int val;
    int _time;
};

int tree[2 * N + 9];
update tree9[2 * N + 9][3];

update cmp(update a, update b)
{
    if (a._time > b._time)
        return a;
    return b;
}

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

    void modify(int L, int R, int tree_type, int X, int dir, update X9)
    {
        if (L > r || R < l)
            return;
        if (l >= L and r <= R)
        {
            if (tree_type == 1)
                tree[id] += X;
            else if (tree_type == 9)
                tree9[id][dir] = X9;
            return;
        }

        left().modify(L, R, tree_type, X, dir, X9);
        right().modify(L, R, tree_type, X, dir, X9);
    }

    int query(int X)
    {
        int pos = X + N - 1;
        int ret_val = 0;

        while (pos >= 1)
        {
            ret_val += tree[pos];
            pos /= 2;
        }
        return ret_val;
    }

    update query9(int X, int dir)
    {
        int pos = X + N - 1;
        update ret_val = {-1 * inf, -1 * inf};

        while (pos >= 1)
        {
            ret_val = cmp(ret_val, tree9[pos][dir]);
            pos /= 2;
        }
        return ret_val;
    }
};

Node root(1, N, 1);

void init()
{
    for (int i = 1; i < 2 * N; i++)
        for (int j = 1; j <= 2; j++)
            tree9[i][j] = {-1 * inf, -1 * inf};
}

int ci(char x)
{
    int v = (int)(x) - '0';
    return v;
}

char ic(int v)
{
    char x = (char)(v) + '0';
    return x;
}

int col_sum(int pos)
{
    return ci(number[1][pos]) + ci(number[2][pos]);
}

int col_digit(int pos)
{
    return col_sum(pos) % 10;
}

void range_addition(int pos)
{
    int L = pos;
    if (is9[pos - 1])
        L = root.query9(pos - 1, 1).val;
    root.modify(L - 1, pos - 1, 1, 1, 0, {0, 0});
}

void range_subtraction(int pos)
{
    int L = pos;
    if (is9[pos - 1])
        L = root.query9(pos - 1, 1).val;
    root.modify(L - 1, pos - 1, 1, -1, 0, {0, 0});
}

void insert9(int pos)
{
    int L = root.query9(pos - 1, 1).val;
    int R = root.query9(pos + 1, 2).val;

    if (L == -1 * inf)
        L = pos;
    if (R == -1 * inf)
        R = pos;

    if (is9[pos - 1] and is9[pos + 1])
    {
        root.modify(L, R, 9, 0, 1, {L, ++current_time});
        root.modify(L, R, 9, 0, 2, {R, ++current_time});
        if (root.query(pos) == 1)
            root.modify(L - 1, pos - 1, 1, 1, 0, {0, 0});
    }
    else if (is9[pos - 1])
    {
        root.modify(L, pos, 9, 0, 2, {R, ++current_time});
        root.modify(pos, pos, 9, 0, 1, {L, ++current_time});
        if (root.query(pos) == 1)
            root.modify(L - 1, pos - 1, 1, 1, 0, {0, 0});
    }
    else if (is9[pos + 1])
    {
        root.modify(pos, R, 9, 0, 1, {L, ++current_time});
        root.modify(pos, pos, 9, 0, 2, {R, ++current_time});
        if (root.query(pos) == 1)
            root.modify(pos - 1, pos - 1, 1, 1, 0, {0, 0});
    }
    else
    {
        root.modify(pos, pos, 9, 0, 1, {pos, ++current_time});
        root.modify(pos, pos, 9, 0, 2, {pos, ++current_time});
        if (root.query(pos) == 1)
            root.modify(pos - 1, pos - 1, 1, 1, 0, {0, 0});
    }
    is9[pos] = true;
}

void remove9(int pos)
{
    Node root(1, N, 1);
    int L = root.query9(pos, 1).val;
    int R = root.query9(pos, 2).val;

    if (is9[pos - 1] and is9[pos + 1])
    {
        root.modify(pos + 1, R, 9, 0, 1, {pos + 1, ++current_time});
        root.modify(L, pos - 1, 9, 0, 2, {pos - 1, ++current_time});
        if (root.query(pos) == 1)
            root.modify(L - 1, pos - 1, 1, -1, 0, {0, 0});
    }
    else if (is9[pos - 1])
    {
        root.modify(L, pos - 1, 9, 0, 2, {pos - 1, ++current_time});
        if (root.query(pos) == 1)
            root.modify(L - 1, pos - 1, 1, -1, 0, {0, 0});
    }
    else if (is9[pos + 1])
    {
        root.modify(pos + 1, R, 9, 0, 1, {pos + 1, ++current_time});
        if (root.query(pos) == 1)
            root.modify(pos - 1, pos - 1, 1, -1, 0, {0, 0});
    }
    else
    {
        if (root.query(pos) == 1)
            root.modify(pos - 1, pos - 1, 1, -1, 0, {0, 0});
    }
    root.modify(pos, pos, 9, 0, 1, {-1 * inf, ++current_time});
    root.modify(pos, pos, 9, 0, 2, {-1 * inf, ++current_time});
    is9[pos] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> n >> q;
    cin >> number[1] >> number[2];
    number[1] = "00" + number[1];
    number[2] = "00" + number[2];

    for (int i = 1; i <= n; i++)
    {
        if (col_sum(i) >= 10)
            range_addition(i);
        if (col_sum(i) == 9)
            insert9(i), is9[i] = true;
    }

    while (q--)
    {
        int pos, digit, sum;
        char z;
        cin >> z >> pos;
        pos = n - pos + 1;

        if (z == 'W' || z == 'Z')
        {
            cin >> digit;
            if (z == 'W')
                sum = digit + ci(number[2][pos]);
            else if (z == 'Z')
                sum = digit + ci(number[1][pos]);

            if (col_sum(pos) >= 10 and sum < 10)
                range_subtraction(pos);
            else if (col_sum(pos) < 10 and sum >= 10)
                range_addition(pos);

            if (is9[pos] and sum != 9)
                remove9(pos);
            else if (!is9[pos] and sum == 9)
                insert9(pos);

            if (z == 'W')
                number[1][pos] = ic(digit);
            else if (z == 'Z')
                number[2][pos] = ic(digit);
        }

        else if (z == 'S')
            cout << (col_sum(pos) + root.query(pos)) % 10 << "\n";
    }
    return 0;
}