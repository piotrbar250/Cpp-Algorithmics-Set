#include <bits/stdc++.h>
using namespace std;

const int M = 3000009;
int n, k;
int res;
int arr[M];

deque <pair <int,int> > maxdq;
deque <pair <int,int> > mindq;

bool ok(int r)
{
    int ma = max(arr[r], maxdq.front().first);
    int mi = min(arr[r], mindq.front().first);
    if(ma - mi <= k)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];

    int r = 1;
    maxdq.push_back({arr[1],1});
    mindq.push_back({arr[1],1});
    for(int l=1; l<=n; l++)
    {
        if(r < l)
        {
            r++;
            maxdq.push_back({arr[r],r});
            mindq.push_back({arr[r],r});
        }
        while(!maxdq.empty() && maxdq.front().second < l)
            maxdq.pop_front();
        while(!mindq.empty() && mindq.front().second < l)
            mindq.pop_front();
        while(ok(r+1) && r+1 <= n)
        {
            while(!maxdq.empty() && maxdq.back().first <= arr[r+1])
                maxdq.pop_back();
            while(!mindq.empty() && mindq.back().first >= arr[r+1])
                mindq.pop_back();
            maxdq.push_back({arr[r+1],r+1});
            mindq.push_back({arr[r+1],r+1});
            r++;
        }
        res = max(res,r-l+1);
    }
    cout<<res<<endl;
}
