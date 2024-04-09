#include <iostream>
#include <algorithm>
using namespace std;

const int M = 20009;
int tab[M];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++)
        cin>>tab[i];

    int k=1;
    int koszt=m, wynik=0;

    for(int p=1; p<=n; p++)
    {
        if(p>1 && tab[p]>tab[p-1])
            koszt+=tab[p-1]-tab[p];
        if(koszt<0)
        {
            while(p!=k and koszt<0)
            {
                if(tab[k+1]>tab[k])
                    koszt+=tab[k+1]-tab[k];
                k++;
            }
        }
        wynik=max(wynik, p-k+1);
    }

    reverse(tab+1, tab+1+n);

    k=1;
    koszt=m;
    int wynik2=0;

    for(int p=1; p<=n; p++)
    {
        if(p>1 && tab[p]>tab[p-1])
            koszt+=tab[p-1]-tab[p];
        if(koszt<0)
        {
            while(p!=k and koszt<0)
            {
                if(tab[k+1]>tab[k])
                    koszt+=tab[k+1]-tab[k];
                k++;
            }
        }
        wynik2=max(wynik2, p-k+1);
    }
    cout<<max(wynik,wynik2);
}
