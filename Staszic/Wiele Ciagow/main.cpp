#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int M = 1000001;
int n=1;

int arr[M];
bool be[M];

vector<int> vec;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int a;
    while(cin>>a)
    {
        arr[n]=a;
        n++;
    }
    n--;
    reverse(arr+1, arr+1+n);
    be[0]=true;
    vec.push_back(n);

    for(int i=1; i<n; i++)
    {
        if(i-arr[i]>0)
        {
            if(be[i-arr[i]-1]==true)
            {
                be[i]=true;
                vec.push_back(n-i);
            }
        }
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
}
