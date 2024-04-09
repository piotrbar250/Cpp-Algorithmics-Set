// Piotr Baranowski
// Zadanie: Cukiernia XXVIII Olimpiada Informatyczna

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<pair<ll, ll>, pair<ll, ll>> PII;

const ll M = 3 * 1e5 + 9, inf = 1e16;
ll n, res = inf;
ll arr[M][4], row_mx[M], row_sum[M], col_sum[4], local_diff[M][4];
bool booked[M][4], row_booked[M], is1 = true, is2;

void check(PII candidate)
{
    ll curr_res = 0;
    pair<ll, ll> third_place;
    ll row1 = candidate.first.first, row2 = candidate.second.first, pos1 = candidate.first.second, pos2 = candidate.second.second;
    bool correct = false;

    if (is2)
        goto for2;

    for (int i = 1; i <= n; i++)
    {
        if (i == row1 or i == row2)
            continue;
        for (int j = 1; j <= 3; j++)
        {
            if (j == pos1 or j == pos2)
                continue;
            if (arr[i][j] == row_mx[i] and !correct)
            {
                correct = true;
                third_place = {i, j};
            }
        }
    }

    if (!correct)
        return;

    row_booked[third_place.first] = booked[third_place.first][third_place.second] = true;
for2:
    row_booked[row1] = row_booked[row2] = booked[row1][pos1] = booked[row2][pos2] = true;

    for (int i = 1; i <= n; i++)
    {
        if (!row_booked[i])
            curr_res += row_sum[i] - row_mx[i];
        else
            for (int j = 1; j <= 3; j++)
                if (booked[i][j])
                    curr_res += row_sum[i] - arr[i][j];
    }

    row_booked[third_place.first] = row_booked[row1] = row_booked[row2] = booked[row1][pos1] = booked[row2][pos2] = booked[third_place.first][third_place.second] = false;
    res = min(res, curr_res);
    return;
}

void solve(ll l, ll r)
{
    pair<ll, ll> tmp_mn = {inf, (-1) * inf};
    PII solution;
    ll local_mn = inf;

    for (int i = 1; i <= n; i++)
    {
        local_diff[i][1] = row_mx[i] - arr[i][l];
        local_diff[i][2] = row_mx[i] - arr[i][r];
        local_mn = min(local_mn, local_diff[i][1]);
    }

    for (int i = 1; i <= n; i++)
        if (local_diff[i][1] == local_mn and local_diff[i][2] > tmp_mn.second)
            tmp_mn = {i, local_diff[i][2]};

    solution.first = {tmp_mn.first, l};

    local_mn = inf;
    tmp_mn = {inf, inf};

    for (int i = 1; i <= n; i++)
        if (i == solution.first.first)
            continue;
        else
            local_mn = min(local_mn, local_diff[i][2]);

    for (int i = 1; i <= n; i++)
        if (i != solution.first.first and local_diff[i][2] == local_mn)
            tmp_mn = {i, inf};

    solution.second = {tmp_mn.first, r};
    check(solution);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        row_mx[i] = (-1) * 1e9;
        int cnt = 0;
        for (int j = 1; j <= 3; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
                cnt++;
            row_mx[i] = max(row_mx[i], arr[i][j]);
            row_sum[i] += arr[i][j];
            col_sum[j] += arr[i][j];
        }
        if (cnt > 1)
            is1 = false;
    }

    if (is1)
    {
        cout << "0"
             << "\n";
        return 0;
    }

    if (min(col_sum[1], min(col_sum[2], col_sum[3])) == 0)
    {
        is2 = true;
        vector<int> vec;
        for (int i = 1; i <= 3; i++)
            if (col_sum[i] > 0)
                vec.push_back(i);
        solve(vec[0], vec[1]);
        cout << res << "\n";
        return 0;
    }

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (i == j)
                continue;
            solve(i, j);
        }
    }
    cout << res << "\n";
    return 0;
}