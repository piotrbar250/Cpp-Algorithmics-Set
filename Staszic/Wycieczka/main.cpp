// Piotr Baranowski - C++ Developer
// Task: Wycieczka
// Programming language: C++
// Algorithm: Binary Search on the result

#include <bits/stdc++.h>
using namespace std;

int check(int *arr, int n, int k, long long mid)
{
    long long sum = 0, m = 0;
    int days = 1;
    for(int i=1; i<n; i++)
    {
        if(sum + arr[i] <= mid)
            sum += arr[i];
        else
        {
            sum = arr[i];
            days++;
        }
        m = max(m,sum);
    }
    if(days > k)
        return 0;
    if(m < mid)
        return 1;
    return 2;
}

long long binary_search(int *arr, int n, int k, long long sum, int m)
{
    long long l = m, r = sum, mid, res = -1;
    while(l <= r)
    {
        mid = l + (r - l) / 2;
        if(check(arr,n,k,mid))
        {
            r = mid - 1;
            if(check(arr,n,k,mid) == 2)
                res = mid;
        }
        else
            l = mid + 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,k;
    cin >> n >> k;
    int *arr;
    arr = new int [n];
    int m = 0;
    long long sum = 0;

    for(int i=1; i<n; i++)
    {
        cin >> arr[i];
        m = max(m,arr[i]);
        sum += arr[i];
    }

    cout << binary_search(arr, n, k, sum, m) << endl;

    delete [] arr;
}
