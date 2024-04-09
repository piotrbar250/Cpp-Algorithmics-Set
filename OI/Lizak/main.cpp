#include <iostream>
using namespace std;
string napis;

const int M = 2000000+9;
int a,b;

pair <int, int > przedzial[M];

void zapamietaj(int p, int k, long long suma)
{
    przedzial[suma].first = p;
    przedzial[suma].second = k;

    if(suma>=3)
    {
        if(napis[p]=='T')
            zapamietaj(p+1, k, suma-2);
        else if(napis[k]=='T')
            zapamietaj(p, k-1, suma-2);
        else
            zapamietaj(p+1, k-1, suma-2);
    }
}
void wyznacz(int dlu);
long long policz(int p, int k);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    long long suma=0;
    cin>>n>>m;
    cin>>napis;
    int dlu = napis.size();
    napis = " " + napis;

    for(int i=1; i<=n; i++)
        if(napis[i]=='T')
            suma+=2;
        else
            suma+=1;

    zapamietaj(1,dlu,suma);
    wyznacz(dlu);
    zapamietaj(a,b,policz(a,b));

    for(int i=1; i<=m; i++)
    {
        int x;
        cin>>x;
        if(przedzial[x].first==0)
        {
            cout<<"NIE"<<endl;
            continue;
        }
        cout<<przedzial[x].first<<" "<<przedzial[x].second<<endl;
    }
}


void wyznacz(int dlu)
{
    int d1=0, p1=0;
    int d2=0, k2=0;

    for(int i=1; i<=dlu; i++)
    {
        if(napis[i]=='W')
        {
            p1=i+1;
            d1=dlu-p1+1;
            break;
        }
    }
    int j=dlu;
    
    for(int i=dlu; i>=1; i--)
    {
        if(napis[i]=='W')
        {
            k2=j-1;
            d2=j-1;
            break;
        }
        j--;
    }
    if(d2>=d1)
    {
        a=1;
        b=k2;
    }
    if(d1>d2)
    {
        a=p1;
        b=dlu;
    }
}
long long policz(int p, int k)
{
    long long suma=0;
    for(int i=p; i<=k; i++)
    {
          if(napis[i]=='T')
            suma+=2;
        else
            suma+=1;
    }
    return suma;
}
