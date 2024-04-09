#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct pos
{
    ll val;
    int id;
};

const int M = 2 * 1e6 + 9;
int n, d, res;
ll p;
ll arr[M], pref[M], plank[M];
deque <pos> dq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> p >> d;
    res = d;
    for(int i=1; i<=n; i++)
        cin >> arr[i];

    for(int i=1; i<=n; i++)
        pref[i] = arr[i] + pref[i-1];
    for(int i=1; i<=n-d+1; i++)
        plank[i] = pref[i+d-1] - pref[i-1];
    
    int l = 1, r = d;
    ll sum = pref[d];
    dq.push_back({plank[1],1});
    for(l=1; l<=n-d+1; l++)
    {
        while(dq.size() != 0 && dq.front().id < l)
            dq.pop_front();
        if(r-l+1 < d)
        {
            r++;
            dq.push_back({plank[r-d+1],r-d+1});
            sum += arr[r];
        }
        
        while(r+1 <= n && sum + arr[r+1] - max(plank[r-d+2], dq.front().val) <= p)
        {
            r++;
            while(dq.size() != 0 && dq.back().val <= plank[r-d+1])
                dq.pop_back();
            dq.push_back({plank[r-d+1], r-d+1});
            sum += arr[r];
        }
        res = max(res, r-l+1);
        sum -= arr[l];
    }
    cout << res << endl;
}
