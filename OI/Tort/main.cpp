#include <bits/stdc++.h>
using namespace std;

const int M = 100009 * 2;
long long a,b,n,k;
long long cutx[M], cuty[M];

long long check(long long md)
{
    int i = 1, j = n + 1;
    long long count = 0;
    while(i != n+2)
    {
        while(cutx[j]*cuty[i] >= md && j != 0)
            j--;
        if(j == 0)
            break;
        count += j;
        i++;
    }
    
    return count;
}

void binary_search()
{
    long long l = cutx[1] * cuty[1];
    long long r = cutx[n+1] * cuty[n+1];
    while(l < r)
    {
        long long md = (l + r + 1) / 2;
        if(check(md) < k)
            l = md;
        else
            r = md - 1;
    }
    cout << l << endl;

    return;
}

int main()
{
    cin >> a >> b >> n >> k;
    long long s = 0;
    for(int i=1; i<=n; i++)
    {
        cin >> cutx[i];
        cutx[i] -= s;
        s += cutx[i];
    }    
    cutx[n+1] = a - s;
    s = 0;
    for(int i=1; i<=n; i++)
    {
        cin >> cuty[i];
        cuty[i] -= s;
        s += cuty[i];
    }
    cuty[n+1] = b - s;

    sort(cutx+1, cutx+2+n);
    sort(cuty+1, cuty+2+n);

    k = (n+1)*(n+1) - k + 1;
    binary_search();

    return 0;
}
