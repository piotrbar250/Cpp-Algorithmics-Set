/// bin_search po wyniku
#include <iostream>
#include <algorithm>
using namespace std;

const int M = 1001;
long long a,b,c;
long x,y,z;
long long suma, ile_trojek;
long long tab1[M], tab2[M], tab3[M];

void bin_search(long long f, long long g)
{
    long long ile_mamy=f+g;
    int p=1, k=z, sr;
    while(p<k)
    {
        sr=(p+k)/2;
        if(ile_mamy+tab3[sr]<suma)
            p=sr+1;
        else
            k=sr;
    }
    if(ile_mamy+tab3[p]>=suma)
        ile_trojek+=z-p+1;
}

int main()
{
    cin>>a>>b>>c;
    cin>>x;
    for(int i=1; i<=x; i++)
    {
        cin>>tab1[i];
        tab1[i]*=a;
    }
    cin>>y;
    for(int i=1; i<=y; i++)
    {
        cin>>tab2[i];
        tab2[i]*=b;
    }
    cin>>z;
    for(int i=1; i<=z; i++)
    {
        cin>>tab3[i];
        tab3[i]*=c;
    }
    sort(tab1+1, tab1+1+x);
    sort(tab2+1, tab2+1+y);
    sort(tab3+1, tab3+1+z);
    suma = tab1[x] + tab2[y] + tab3[z];
    suma/=2; suma++;

    for(int i=1; i<=x; i++)
        for(int j=1; j<=y; j++)
            bin_search(tab1[i], tab2[j]);
    cout<<ile_trojek;
}
