#include <iostream>
using namespace std;
const int M = 1 << 19;
int tab[M], tree[2*M-1];
int sum(int pza, int kza, int jes, int pjes, int kjes)
{
    if(pjes>kza || kjes<pza)
        return 0;
    if(pjes>=pza && kjes<=kza)
        return tree[jes];
    return sum(pza, kza, 2*jes, pjes, (pjes+kjes)/2) ^ sum(pza, kza, 2*jes+1, (pjes+kjes)/2+1, kjes);
}

void order(int n)
{
    for(int i=1; i<=n; i++)
        tree[M+i-1]=tab[i];
    for(int i=M-1; i>=1; i--)
        tree[i] = tree[2*i] ^ tree[2*i+1];
}
void change(int a,int b)
{
    int pom1=a+M-1;
    int pom2=b+M-1;
    int pom3=pom1%2;
    int pom4=pom2%2;
    swap(tree[pom1],tree[pom2]);

    while(pom1>=1)
    {
        pom1/=2;
        pom2/=2;
        tree[pom1] = tree[2*pom1] ^ tree[2*pom1+1];
        tree[pom2] = tree[2*pom2] ^ tree[2*pom2+1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
  cin.tie(0);
  cout.tie(0);
    int n,m,a,b;
    cin>>n>>m;

    for(int i=1; i<=n; i++)
        cin>>tab[i];

    order(n);

    /*for(int i=1; i<=2*M-1; i++)
        cout<<i<<" "<<tree[i]<<endl;*/

    for(int i=1; i<=m; i++)
    {
        string polecenie;
        cin>>polecenie;
        if(polecenie=="czytaj")
        {
            cin>>a>>b;
            cout<<sum(a,b,1,1,M)<<endl;
        }
        else if(polecenie=="zamien")
        {
            cin>>a>>b;
            change(a,b);

        }
    }
}
