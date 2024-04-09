#include <bits/stdc++.h>
using namespace std;

const int M = 5e5 + 9;
int n, s, number = 1;
long long res;

pair <long long, long long> arr[M];
long long dif[M], dir[M];
vector <int> blocks;
vector <int> pos;

void set_blocks(int v)
{
    int id = -1, minval = 9999999, val = 1;
    
    if(v == 1)
        goto forw;

    int var;
    if(dir[1] == 1)
        var = n - s + 1;
    if(dir[1] == -1)
        var = s;
    for(int i=1; i<=var; i++)
    {
        if(dif[i] < minval)
        {
            minval = dif[i];
            id = i;
        }
    }
    dir[id] *= -1;
    blocks.clear();

    forw:
    for(int i=2; i<n; i++)
    {
        if(dir[i] == dir[i-1])
            val++;
        else
        {
            blocks.push_back(val);
            val = 1;
        }
    }
    blocks.push_back(val);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for(int i=1; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        arr[i] = {a,b};
        dif[i] = abs(a-b);
    }
    int left = 1, right = n;
    int start = 1;
    if(s == 1)
    {
        left = 2;
        start = 2;
        dir[1] = 1;
    }
    else if(s == n)
    {
        right = n-1;
        start = 2;
        dir[1] = -1;
    }
    else if(dif[1] == 0 && dif[2] != 0)
    {
        if(arr[2].first > arr[2].second)
            dir[2] = 1;
        else
            dir[2] = -1;
        dir[1] = dir[2] * (-1);
        start = 3;
    }
    else if(dif[1] == 0 && dif[2] == 0)
    {
        dir[1] = 1;
        dir[2] = -1;
        start = 3;
    }

    for(int i=start; i<n; i++)
    {
        if(arr[i].first > arr[i].second)
            dir[i] = 1;
        else if(arr[i].first < arr[i].second)
            dir[i] = -1;
        else
            dir[i] = dir[i-1] * (-1);
    }
    
    set_blocks(1);

    if((dir[1] == 1 && s + blocks[0] > n) || (dir[1] == -1 && s - blocks[0] < 1))
        set_blocks(2);

    for(int i=1; i<n; i++)
    {
        if(dir[i] == 1)
            res += arr[i].second;
        else
            res += arr[i].first;
    }

    pos.push_back(s);
    number++;
    for(auto x: blocks)
    {
        if(dir[number-1] == 1)
        {
            int a = right - x + 1;
            int b = right;
            if(s >= a && s < b)
                a--;
            for(int i=a; i<=b; i++)
                if(i != s)
                {
                    pos.push_back(i);
                    number++;
                }
            right = a - 1;
            if(right == s)
                right--;
        }
        else
        {
            int a = left + x - 1;
            int b = left;
            if(s > b && s <= a)
                a++;
            for(int i=a; i>=b; i--)
                if(i != s)
                {
                    pos.push_back(i);
                    number++;
                }
            left = a + 1;
            if(left == s)
                left++;
        }
    }
    cout << res << endl;
    for(auto a: pos)
        cout << a << " ";
    cout << endl;
    return 0;
}
