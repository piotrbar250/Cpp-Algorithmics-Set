#include <iostream>
using namespace std;
const int M = 1 << 20;
int n,m;
int counter=1;
long long tree[2*M], tree2[2*M], tab[2*M];
int pom[2*M];
void fnd_base(int pza, int kza, int jes, int pjes, int kjes)
{
    if(pjes>kza || kjes<pza)
        return;
    if(pjes>=pza && kjes<=kza)
    {
        pom[counter]=jes;
        counter++;
        return;
    }
    fnd_base(pza,kza, jes*2, pjes, (pjes+kjes)/2);
    fnd_base(pza, kza, jes*2+1, (pjes+kjes)/2+1, kjes);
    return;
}
void init()
{
    for(int i=1; i<=n; i++)
        tree[i+M-1]=tab[i];
    for(int i=M-1; i>=1; i--)
        tree[i]=tree[2*i]+tree[2*i+1];
}
void order()
{
    for(int i=M-1; i>=1; i--)
    {
        long long s1 = tree[2*i] * tree[2*i+1];
        long long s2 = tree2[2*i] + tree2[2*i+1];
        tree2[i] = s1 + s2;
    }
}
void update(int a,int b)
{
    int x=a+M-1;
    tree[x]=b;
    x/=2;
    while(x)
    {
        tree[x]=tree[2*x]+tree[2*x+1];
        x/=2;
    }
}
void update2(int a,int b)
{
    int x=a+M-1;
    tree[x]=b;
    x/=2;
    while(x)
    {
        long long s1 = tree[2*x] * tree[2*x+1];
        long long s2 = tree2[2*x] + tree2[2*x+1];
        tree2[x] = s1 + s2;
        x/=2;
    }
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>tab[i];

    init();
    order();
    int a,b;
    for(int i=1; i<=m; i++)
    {
        int wybor;
        cin>>wybor;

        switch(wybor)
        {
        case 1:
        {

            long long wynik=0;
            cin>>a>>b;
            fnd_base(a,b,1,1,M);
            if(counter==2)
            {
                cout<<tree2[pom[1]]<<endl;
            }
            else
            {
                for(int j=1; j<counter; j++)
                {
                    wynik+=tree2[pom[j]];
                    for(int k=j+1; k<counter; k++)
                    {
                        long long buf=tree[pom[j]]*tree[pom[k]];
                        wynik+=buf;
                    }
                }
                cout<<wynik<<endl;
            }

            for(int j=1; j<=counter; j++)
                pom[j]=0;
            counter=1;
            break;
        }
        case 0:
        {
            cin>>a>>b;
            update(a,b);
            update2(a,b);

            break;
        }
        }

    }
}
