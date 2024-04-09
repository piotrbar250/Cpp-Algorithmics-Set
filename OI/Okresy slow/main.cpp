#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 9;
int n;
long long sum;
string s;
int pref[M], dp[M];

void kmp()
{   
    pref[1] = 0;
    int pointer = 0;
    for(int i=2; i<=n; i++)
    {
        while(pointer > 0 && s[i] != s[pointer+1])
            pointer = pref[pointer];
        if(s[i] == s[pointer+1])
            pointer++;
        pref[i] = pointer;
    }
    return;
}

void solve()
{
    for(int i=1; i<=n; i++)
    {
        if(pref[i] == 0)
            dp[i] = i;
        else
            dp[i] = dp[pref[i]];
        sum += (long long)(i - dp[i]);
    }
}

int main()
{
    cin >> n >> s;
    s = " " + s;
    kmp();
    solve();
    cout << sum;   
}