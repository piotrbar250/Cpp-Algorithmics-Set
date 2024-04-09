// Piotr Baranowski
// IX Olimpiada Informatyczna
// Second stage
// Task: Izolator
// Programming language: C++
// Time complexity: O(nlogn)

#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 9;
int n;
long long sum, res;
long long arr[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        long long a; 
        cin >> a;
        arr[i] = a;
        res += arr[i];
    }

    sort(arr+1, arr+1+n);

    for(int i=1; i<=(n/2); i++)
        res += (arr[n-i+1] - arr[i]);
    cout << res << endl;
    return 0;
}
