// Piotr Baranowski - C++ Developer
// Task: Wieza
// Programming language: C++
// Algorithm: Binary Search

#include <bits/stdc++.h>
using namespace std;

const int M = 5 * 1e5 + 9;
int n,m;
int arr[M];

int binary_search(int x)
{
    int l = 0, r = n, md;
    while(l < r)
    {
        md = (l + r + 1) / 2;
        if(x > arr[md])
            l = md;
        else
            r = md - 1;
    }

    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
        arr[i] = max(arr[i],arr[i-1]);
    }

    for(int i=1; i<=m; i++)
    {
        int a;
        cin >> a;
        int res = binary_search(a);
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
