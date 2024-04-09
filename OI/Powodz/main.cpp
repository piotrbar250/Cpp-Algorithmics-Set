#include <bits/stdc++.h>
using namespace std;

const int M = 1003, N = 1000, ID = 1e6 + 9, inf = 2000;
int n, m, res;

struct square
{
    int id, height;
};

struct cor
{
    int x, y;
};

square arr[M][M];
cor dictionary[ID];
int F[ID];
bool land[ID];
vector<int> height[M];

int _find(int x)
{
    if (F[x] == x)
        return x;
    F[x] = _find(F[x]);
    return F[x];
}

void _union(int a, int b) // a.h >= b.h
{
    int FA = _find(a), FB = _find(b);
    if (FA != FB)
    {
        F[FA] = FB;
        if (land[FA])
            land[FB] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 1001; i++)
        for (int j = 0; j <= 1001; j++)
            arr[i][j] = {0, inf};

    static int id = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int w;
            cin >> w;
            arr[i][j] = {++id, w};
            dictionary[id] = {i, j};
            height[abs(w)].push_back(id);
            F[id] = id;
        }

    int dx[] = {0, 1, -1, 0, 0};
    int dy[] = {0, 0, 0, 1, -1};

    for (int i = 1; i <= N; i++)
    {
        for (int p : height[i]) // p  - id pola o wysokosci i
        {
            int curr_height = arr[dictionary[p].x][dictionary[p].y].height;
            for (int j = 1; j <= 4; j++)
            {
                int x = dictionary[p].x + dx[j];
                int y = dictionary[p].y + dy[j];

                if (abs(arr[x][y].height) > abs(curr_height))
                    continue;

                _union(p, arr[x][y].id);
            }
        }

        for (int p : height[i])
        {
            int curr_height = arr[dictionary[p].x][dictionary[p].y].height;
            if (curr_height > 0 and !land[_find(p)])
                res++;
            if (curr_height > 0)
                land[_find(p)] = true;
        }
    }
    cout << res << endl;
}
