#include <iostream>
using namespace std;

const int M = 1000*1000+9;
int arb[M],ban[M],prefA[M],prefB[M];

int bin_search_last(int x, int p, int k, int plemie)
{
    if(plemie==2)
    {
        while(p<k)
        {
            int sr=(p+k+1)/2;
            if(prefB[sr]<=x)
                p=sr;
            else
                k=sr-1;
        }
        return p;
    }
    else
    {
        while(p<k)
        {
            int sr=(p+k+1)/2;
            if(prefA[sr]<=x)
                p=sr;
            else
                k=sr-1;
        }
        return p;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,z;
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        cin>>arb[i];
        prefA[i]=prefA[i-1]+arb[i];
    }
    for(int i=1; i<=m; i++)
    {
        cin>>ban[i];
        prefB[i]=prefB[i-1]+ban[i];
    }

    cin>>z;

    for(int i=1; i<=z; i++)
    {
        int a,b;
        char znak;
        cin>>a>>b>>znak;

        switch(znak)
        {
        case 'A':
        {
            int pom=prefA[b-1]+a;
            int wynik = bin_search_last(pom, 1, m, 2);
            if(prefB[wynik]<pom)
                cout<<pom-prefB[wynik]<<" "<<wynik+1<<endl;
            else
                cout<<pom-prefB[wynik-1]<<" "<<wynik<<endl;

            break;
        }
        case 'B':
        {
            int pom=prefB[b-1]+a;
            int wynik = bin_search_last(pom, 1, n, 1);
            if(prefA[wynik]<pom)
                cout<<pom-prefA[wynik]<<" "<<wynik+1<<endl;
            else
                cout<<pom-prefA[wynik-1]<<" "<<wynik<<endl;
                
            break;
        }
        }
    }
}
