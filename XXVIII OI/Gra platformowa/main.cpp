// Piotr Baranowski
// Zadanie: Gra platformowa XXVIII Olimpiada Informatyczna

#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 9;
int n, X, z;
vector<pair<int, int>> holes;
int dp[M];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> X >> z;
    for (int i = 1, l; i <= n; i++)
    {
        cin >> l;
        for (int j = 1, v; j <= l; j++)
        {
            cin >> v;
            holes.push_back({v, i});
        }
    }

    sort(holes.begin(), holes.end(), cmp);

    for (auto h : holes)
    {
        int i = h.second;
        if (h.second == n)
            dp[n] = dp[n] + 1;

        else if (h.second == 1)
        {
            dp[2] = min(dp[2], dp[1] + 1);
            dp[1] = min(dp[2], dp[1] + 1);
        }
        else
        {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            dp[i] = min(dp[i] + 1, dp[i + 1]);
        }
    }

    while (z--)
    {
        int q;
        cin >> q;
        cout << dp[q] << "\n";
    }
    return 0;
}