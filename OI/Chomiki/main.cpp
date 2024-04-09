#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 209, S = 1e5 + 9, inf = 1e14 + 1;
int n, m;
string arr[M];

ll dp[31][M][M], dp_odd[31][M][M];
ll dp_res[31][M][M], dp_res_odd[31][M][M];

ll common[M][M], pref[S];
ll power[32];
vector <int> decomp;

void init()
{
    power[0] = 1;
    for(ll i=1; i<=30; ++i)
        power[i] = power[i-1] * 2;
    return;
}

void decompose()
{
    ll v = m;
    decomp.push_back(0);
    while(v > 0)
    {
        for(ll i=0; i<=30; ++i)
        {
            if(power[i] > v)
            {
                v -= power[i-1];
                decomp.push_back(i-1);
                break;
            }
        }
    }
    return;
}

int kmp(const string &s)
{
    pref[1] = 0;
    int pointer = 0;

    for(int i=2; i<s.size(); ++i)
    {
        while(pointer > 0 && s[i] != s[pointer + 1])
            pointer = pref[pointer];
     
        if(s[i] == s[pointer + 1])
            pointer++;

        pref[i] = pointer;
    }
    return pref[s.size() - 1];
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; ++i)
        cin >> arr[i];

    for(int i=0; i<=30; ++i)
        for(int j=1; j<=n; ++j)
            for(int k=1; k<=n; ++k)
                dp[i][j][k] = dp_odd[i][j][k] = dp_res[i][j][k] = dp_res_odd[i][j][k] = inf;
    

    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            string s;
            if(i == j)
                s = " " + arr[i];
            else
                s = " " + arr[i] + arr[j];
            common[i][j] = kmp(s);
        }
    }

    init();
    decompose();


    for(int i=1; i<=n; ++i)
        dp[0][i][i] = arr[i].size();

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            dp[1][i][j] = dp[0][i][i] + dp[0][j][j] - common[j][i];

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            for(int k=1; k<=n; ++k)
                dp_odd[1][i][k] = min(dp_odd[1][i][k], dp[1][i][j] + (int) arr[k].size()  - common[k][j]);

    
    for(int i=2; i<=29; ++i)
        for(int j=1; j<=n; ++j)
            for(int k=1; k<=n; ++k)
            {
                for(int h=1; h<=n; ++h)
                    dp[i][j][k] = min(dp[i][j][k], dp_odd[i-1][j][h] + dp[i-1][h][k] - (int) arr[h].size());

                for(int h=1; h<=n; ++h)
                    dp_odd[i][j][h] = min(dp_odd[i][j][h], dp[i][j][k] + (int) arr[h].size() - common[h][k]);
            }

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            dp_res[1][i][j] = dp[decomp[1]][i][j];

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            for(int k=1; k<=n; ++k)
                dp_res_odd[1][i][k] = min(dp_res_odd[1][i][k], dp_res[1][i][j] + (int) arr[k].size() - common[k][j]);

    for(int i=2; i<decomp.size(); ++i)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; ++k)
            {
                for(int h=1; h<=n; ++h)
                    dp_res[i][j][k] = min(dp_res[i][j][k], dp_res_odd[i-1][j][h] + dp[decomp[i]][h][k] - (int) arr[h].size());
                for(int h=1; h<=n; ++h)
                    dp_res_odd[i][j][h] = min(dp_res_odd[i][j][h], dp_res[i][j][k] + (int) arr[h].size() - common[h][k]);
            }

    ll res = inf;

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            res = min(res, dp_res[decomp.size() - 1][i][j]);
    
    cout << res<< endl;
    return 0;
}
