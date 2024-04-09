#include <iostream>
#include <map>
using namespace std;

map<string,int> mapa;
int F[200*1009];

int fnd(int x)
{
    if(F[x]==x)
        return x;
    F[x]=fnd(F[x]);
    return (F[x]);
}
void un(int a, int b)
{
    if(fnd(a)!=fnd(b))
        F[fnd(a)]=fnd(b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int j=1;
    cin>>n;

    for(int i=1; i<=2*n; i++)
        F[i]=i;

    for(int i=1; i<=n; i++)
    {
        string polecenie;
        cin>>polecenie;

        if(polecenie=="connect")
        {
            string a,b;
            cin>>a>>b;
            if(mapa.find(a)==mapa.end())
            {
                mapa[a]=j;
                j++;
            }
            if(mapa.find(b)==mapa.end())
            {
                mapa[b]=j;
                j++;
            }
            un(mapa[a],mapa[b]);
        }
        else
        {
            string a,b;
            cin>>a>>b;
            if(a==b)
            {
                cout<<"Tak"<<endl;
                continue;
            }
            if(mapa.find(a)==mapa.end() || mapa.find(b)==mapa.end())
                cout<<"Nie"<<endl;
            else
            {
                if(fnd(mapa[a])==fnd(mapa[b]))
                    cout<<"Tak"<<endl;
                else
                    cout<<"Nie"<<endl;
            }

        }
    }
}
