#include <iostream>
#include <cmath>
using namespace std;
const long long M = 1000009;
long long tab[M];
bool zlozona[M];

template <typename T> T getczary()
{
    int ujemna = false, znak = getchar_unlocked();
    T wynik = (T)0;
    while(!isdigit(znak))
    {
        if(znak == '-')
            ujemna = true;
        znak = getchar_unlocked();
    }
    while(isdigit(znak))
    {
        wynik *= 10;
        wynik += znak - '0';
        znak = getchar_unlocked();
    }
    if(ujemna)
        wynik *= -1;
    return wynik;
}

void sito()
{
    for(long long i=1; i<=M-9; i++)
        tab[i]=i;

    for(long long i=2; i*i<=M-9; i++)
        if(!zlozona[i])
            for(long long j=i*i; j<=M-9; j+=i)
            {
                zlozona[j]=true;
                tab[j]=min(tab[j],i);
            }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sito();
    long long n;
    n=getczary<int>();

    for(long long i=1; i<=n; i++)
    {
        long long x;
        x=getczary<int>();
        if(x==1)
        {
            cout<<endl;
            continue;
        }

        while(true)
        {
            if(!zlozona[x])
            {
                cout<<x<<endl;
                break;
            }
            cout<<tab[x]<<" ";
            x/=tab[x];
        }
    }
}
