#include<iostream>
using namespace std;

int binsearch_last(int x, int n,int rurki_pom[])
{
    int p=1,k=n,sr;
    while(p<k)
    {
        sr=(p+k+1)/2;
        if(rurki_pom[sr]>=x)
            p=sr;
        else
            k=sr-1;
    }
    return p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,pom,a;
    bool ost=true;
    cin>>n>>m;
    if(m>n)
    {
        cout<<"0";
        return 0;
    }
    int granica=n;
    int *rurki_pom;
    rurki_pom = new int[n+7];
    int *krazki;
    krazki = new int [m+7];
    cin>>rurki_pom[1];
    pom=rurki_pom[1];
    
    for(int i=2; i<=n; i++)
    {
        cin>>a;
        if(a<=pom)
        {
            rurki_pom[i]=a;
            pom=rurki_pom[i];
        }
        else
            rurki_pom[i]=pom;
    }

    for(int i=1; i<=m; i++)
    {
        cin>>krazki[i];
        if(krazki[i]>rurki_pom[1])
        {
            cout<<"0";
            return 0;
        }
    }

    for(int i=1; i<=m; i++)
    {
        int wynik=binsearch_last(krazki[i],granica,rurki_pom);
        granica=wynik-1;
        if(wynik==1 && i!=m)
        {
            cout<<"0";
            return 0;
        }    
        if(i==m)
        {
            cout<<wynik;
            return 0;
        }
    }
    if(ost)
        cout<<granica;
    if(!ost)
        cout<<"0";

    delete[]rurki_pom;
    delete[]krazki;
    return 0;
}
