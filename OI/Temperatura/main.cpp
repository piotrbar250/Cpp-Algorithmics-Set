#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 9;
int n, res;
pair <int,int> arr[M];
deque < pair<int,int> > dq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i].first >> arr[i].second;
    
    int l = 1, r = 1;
    dq.push_back({arr[1].first,1});

    for(l=1; l<=n; l++)
    {
        while(dq.size() != 0 && dq.front().second < l)
            dq.pop_front();
        if(l > r)
            dq.push_back({arr[++r].first,l});
        while(arr[r+1].second >= dq.front().first && r+1 <= n)
        {
            r++;
            while(dq.size() != 0 && dq.back().first <= arr[r].first)
                dq.pop_back();
            dq.push_back({arr[r].first,r});
        }
        res = max(res, r-l+1);
    }
    cout << res << endl;
}
