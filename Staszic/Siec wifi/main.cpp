/// Piotr Baranowski - C++ Developer
/// Task: Siec wifi
/// Programming language: C++
/// Algorithm: Binary Search on the result
/// Complexity: O(n * logn) 

#include <bits/stdc++.h>
using namespace std;

const int M = 1000009;
int t;
int n,k;
int arr[M],arr2[M];

bool ok(int md)
{
    int ind = arr2[1] + md;
    int counter = 1;

    for(int i=2; i<=n; i++)
    {
        int var = abs(arr2[i] - ind);
        if(var > md)
        {
            ind = arr2[i] + md;
            counter++;
        }
    }

    if(counter <= k)
        return true;
    return false;
}

int binary_seearch_function(int l, int r)
{
    int md;
    while(l<r)
    {
        md = (l + r) / 2;
        if(!ok(md))
            l = md + 1;
        else
            r = md;
    }   
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    for(int j=1; j<=t; j++)
    {
        cin>>k>>n;
    
        for(int i=1; i<=n; i++)
            cin>>arr[i];
 
        sort(arr+1,arr+1+n);
        for(int i=1; i<=n; i++)
            arr2[i] = arr[i] * 2;

        int res = binary_seearch_function(0,arr2[n]);

        if(res % 2 == 0)
            cout<<res/2<<".0"<<endl;
        else
            cout<<res/2<<".5"<<endl;
    }
    return 0; 
}
