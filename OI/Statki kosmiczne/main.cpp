#include <iostream>
#include <algorithm>
using namespace std;

const int M = 1009;
long long a,b,c;
long long x,y,z;
long long m1,m2,m3;
long long suma, ile_trojek;
long long tab1[M], tab2[M], tab3[M];
void bin_search(long long f, long long g)
{
    long long ile_potrzeba=suma-f-g;
    int p=1, k=z, sr;
    while(p<k)
    {
        sr=(p+k)/2;
        if(tab3[sr]<ile_potrzeba)
            p=sr+1;
        else
            k=sr;
    }
    if(f+g+tab3[p]>=suma)
    {
        ile_trojek+=(z-p+1);
        //cout<<f<<" "<<g<<" "<<tab3[p]<<" "<<ile_trojek<<"          "<<p<<endl;

    }
}
int main()
{
    cin>>a>>b>>c;
    cin>>x;
    for(int i=1; i<=x; i++)
    {
        cin>>tab1[i];
        tab1[i]*=a;
        m1=max(m1, tab1[i]);
    }
    cin>>y;
    for(int i=1; i<=y; i++)
    {
        cin>>tab2[i];
        tab2[i]*=b;
        m2=max(m2, tab2[i]);
    }
    cin>>z;
    for(int i=1; i<=z; i++)
    {
        cin>>tab3[i];
        tab3[i]*=c;
        m3=max(m3, tab3[i]);
    }
    suma=m1+m2+m3;
    suma/=2; suma++;
    sort(tab3+1, tab3+1+z);

    for(int i=1; i<=x; i++)
    {
        for(int j=1; j<=y; j++)
        {
            bin_search(tab1[i], tab2[j]);
        }
    }
    cout<<ile_trojek;
}
