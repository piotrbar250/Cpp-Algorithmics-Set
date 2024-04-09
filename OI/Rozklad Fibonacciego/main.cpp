#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1009;
int t, ans;
typedef unsigned long long T;
T n;
T fib[M];

T abs(T a, T b)
{
    if(a >= b)
        return (a - b);
    return (b - a);
}

int binary_search_1(T x)
{
    int l = 1, r = 86, md, res = -1;
    while(l <= r)
    {
        md = l + (r - l) / 2;
        if(fib[md] >= x)
        {
            r = md - 1;
            res = md;
        }
        else
            l = md + 1;
    }
    return res;
}

int binary_search_2(T x)
{
    int l = 1, r = 86, md, res = -1;
    while(l <= r)
    {
        
        md = l + (r - l) / 2;
        if(fib[md] <= x)
        {
            l = md + 1;
            res = md;
        }
        else
            r = md - 1;
    }
    return res;
}

void solve(T x)
{
    if(x == 0)
        return;  
    ans++;
    T var1 = abs(x, fib[binary_search_1(x)]); 
    T var2 = abs(x, fib[binary_search_2(x)]);
    if(var1 <= var2)
        solve(var1);
    else
        solve(var2);
    return;
}

int main()
{

    
    fib[2] = fib[1] = 1;
    for(int i=3; i<=86; i++)
        fib[i] = fib[i-1] + fib[i-2];
    cin >> t;
    while(t--)
    {
        cin >> n;
        solve(n);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
