#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 9, inf = 1e9;
int n, k, res;
int l1, l2;

int arr[M], jump1[M], jump2[M];
int last_pos[M], prefix[M], previous[M];
bool isJump[M];

pair <int,int> path[M], range[M];
vector <int> lasts;

void count_ranges()
{
    /// left to right
    for(int i=1; i<=l1; i++)
    {
        previous[jump1[i]] = jump1[i-1];
        isJump[jump1[i]] = true;
        path[jump1[i]] = {inf, inf};
    }

    for(int i=1; i<=n; i++)
    {
        if(!isJump[arr[i]])
            continue;

        if(jump1[1] == arr[i])
            path[jump1[1]]= {i, i};
        else if(path[previous[arr[i]]].first != inf)
            path[arr[i]] = {i, path[previous[arr[i]]].second};

        if(jump1[l1] == arr[i])
        {
            if(path[jump1[l1]].first != inf)
                range[i].first = path[jump1[l1]].second;
        }
    }

    /// right to left
    for(int i=1; i<=l1; i++)
    {
        previous[jump1[i]] = 0;
        isJump[jump1[i]] = false;
        path[jump1[i]] = {0, 0};
    }

    for(int i=1; i<=l2; i++)
    {
        previous[jump2[i]] = jump2[i-1];
        isJump[jump2[i]] = true;
        path[jump2[i]] = {inf, inf};
    }

    for(int i=n; i>=1; i--)
    {
        if(!isJump[arr[i]])
            continue;
        if(jump2[1] == arr[i])
            path[jump2[1]] = {i, i};
        else if(path[previous[arr[i]]].first != inf)
            path[arr[i]] = {i, path[previous[arr[i]]].second};

        if(jump2[l2] == arr[i])
        {
            if(path[jump2[l2]].first != inf)
                range[i].second = path[jump2[l2]].second;
        }
    }
    return;
}

void solve()
{
    prefix[0] = (-1) * inf;
    for(int i=1; i<=n; i++)
    {
        int var = (-1) * inf;
        if(last_pos[arr[i]] != i)
            var = last_pos[arr[i]];
        prefix[i] = max(prefix[i-1], var);
    }

    for(int i=1; i<=n; i++)
    {
        if(jump1[l1] == arr[i] and min(range[i].first, range[i].second) != 0)
        {
            if(prefix[range[i].first-1] > range[i].second)
            {
                res++;
                lasts.push_back(i);
            }    
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> arr[i], last_pos[arr[i]] = i;

    cin >> l1 >> l2;
    for(int i=1; i<=l1; i++)
        cin >> jump1[i];

    for(int i=1; i<=l2; i++)
        cin >> jump2[i];

    count_ranges();
    solve();

    cout << res << endl;
    for(auto v: lasts)
        cout << v << ' ';
    cout << endl;

    return 0;
}
