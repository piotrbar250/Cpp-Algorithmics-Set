#include <iostream>
using namespace std;

const int M = 1000009;
int n;
long long sum, target, curr_sum, result;
int arr[2*M];

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        arr[i+n]=arr[i];
    }
    target = sum/2;
    int k=1;   
    for(int p=1; p<=2*n; p++)
    {
        curr_sum+=arr[p];
        if(curr_sum>target)
        {
            while(k<p && curr_sum>target)
            {
                curr_sum-=arr[k];
                k++;
            }
        }
        if(curr_sum<=target)
            result=max(result, curr_sum);
    }
    cout<<result;
}
