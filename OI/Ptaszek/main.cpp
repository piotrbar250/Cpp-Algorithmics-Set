#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 9, inf = 1e6 + 9;
int n, m;
int arr[M], dp[M];

struct dqtype
{
    int value; // dp
    int index;
    int height;
};

deque <dqtype> dq;

bool check(const dqtype &new_tree)
{
    if(!dq.empty() and (dq.back().value > new_tree.value or (dq.back().value == new_tree.value and dq.back().height <= new_tree.height)))
        return true;
    return false;
}

void solve(int k)
{
    for(int i=1; i<=n; i++)
        dp[i] = 0;
    for(int i=1; i<=n; i++)
    {
        while(!dq.empty() and dq.front().index < i - k)
            dq.pop_front();
        if(!dq.empty())
        {
            dp[i] = dq.front().value;
            if(dq.front().height <= arr[i])
                dp[i]++;
        }
        dqtype new_tree = {dp[i], i, arr[i]};
        while(check(new_tree))
            dq.pop_back();
        dq.push_back(new_tree);
    }
    dq.clear();
    return;
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    cin >> m;
    while(m--)
    {
        int k;
        cin >> k;
        solve(k);
        cout << dp[n] << endl;
    }
    return 0;
}
