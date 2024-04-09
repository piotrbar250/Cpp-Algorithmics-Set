#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 9;
int n, k, res = M;
int arr[M], pref[M];

int main()
{
    cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
        pref[i] = pref[i-1];
        if(arr[i] == 0)
        pref[i]++;
    }
    
    if(n-pref[n] < k)
    {
        cout<<"NIE"<<endl;
        return 0;
    }

    int r = 1, lr = arr[1];
    for(int l=1; l<=n; l++)
    {
        while(lr != k && r+1 <= n && lr + arr[r+1] <= k)
            lr += arr[++r];
        if(lr == k)
            res = min(res, pref[r] - pref[l-1]);
        lr -= arr[l];
    }
    cout<<res<<endl;
    return 0;
}
