#include <iostream>
#include <algorithm>
using namespace std;
const int M=1000 *1000 +20;
long long tab[M];
int bin_search(int p, int k, long long x)
{
    while(p<k)
    {
        int sr=(p+k)/2;
        if(tab[sr]<x)
            p=sr+1;
        else
            k=sr;
    }
    return p;
}
int main()
{
          ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

    int n,z;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>tab[i];
    n++;
    tab[n]=1000*1000*1000*1000*1000+20;
    sort(tab+1,tab+n);
    cin>>z;
    for(int i=1; i<=z; i++)
    {
        long long a;
        cin>>a;

        int w1 = bin_search(1,n,a);
        int w2 = bin_search(1,n,a+1);
        cout<<w2-w1<<endl;

    }
}
