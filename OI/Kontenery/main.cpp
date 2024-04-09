#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 9, SQ = 317;
int n, k;
vector<int> big(M, 0);
vector<vector<int>> small(M, vector<int>(SQ + 9, 0));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int a, l, d;
        cin >> a >> l >> d;
        if (d >= SQ)
        {
            for (int j = a; j <= n; j += d)
                if (l-- > 0)
                    big[j]++;
        }
        else
        {
            small[a][d]++;
            int last = a + l * d;
            if (last <= n)
                small[last][d]--;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int sum = big[i];
        for (int j = 1; j < SQ; j++)
        {
            int jump = i - j;
            if (jump >= 1)
                small[i][j] += small[jump][j];
            sum += small[i][j];
        }
        cout << sum << ' ';
    }
}
