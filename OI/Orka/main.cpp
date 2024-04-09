#include <bits/stdc++.h>
using namespace std;

class Program
{
    using vector1d = vector<int>;
    using vector2d = vector<vector1d>;
    using ll = long long;

private:
    const int inf = 1e6;
    int k, n, m;
    vector2d arr, arr2, prefix_sum;

public:
    void input()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        cin >> k >> m >> n;
        arr.resize(n + 9, vector1d(m + 9, 0));
        prefix_sum = arr;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> arr[i][j];
                prefix_sum[i][j] = arr[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
            }
    }

    void solve()
    {
        int res = inf;
        res = det_cuts() + m;

        arr2.resize(m + 9, vector1d(n + 9, 0));
        prefix_sum = arr2;

        for (int j = 1; j <= m; j++)
            for (int i = 1; i <= n; i++)
                arr2[j][i] = arr[i][j];

        swap(n, m);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                prefix_sum[i][j] = arr2[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];

        res = min(res, det_cuts() + m);

        cout << res << endl;
    }

private:
    int det_cuts()
    {
        int res = inf;
        int t = 0, d = n - 1;
        while (t < n)
        {
            bool var = check(1, 1, n, m, t, d);
            if (var)
                res = min(res, t + d);

            if (var and d > 0)
                d--;
            else
                t++;

            if (t + d == n)
                d--;
        }
        return res;
    }

    bool check(int x1, int y1, int x2, int y2, int t, int d)
    {
        bool found = false;
        if (y1 > y2)
            found = true;

        else if (sum(x1, y1, x2, y1) <= k)
            found = check(x1, y1 + 1, x2, y2, t, d);

        else if (sum(x1, y2, x2, y2) <= k)
            found = check(x1, y1, x2, y2 - 1, t, d);

        else if (t > 0 and sum(x1, y1, x1, y2) <= k)
            found = check(x1 + 1, y1, x2, y2, t - 1, d);

        else if (d > 0 and sum(x2, y1, x2, y2) <= k)
            found = check(x1, y1, x2 - 1, y2, t, d - 1);

        return found;
    }

    ll sum(int x1, int y1, int x2, int y2)
    {
        return (prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2] - prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1]);
    }
};

int main()
{
    Program p;
    p.input();
    p.solve();
    return 0;
}
