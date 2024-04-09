#include <iostream>
using namespace std;
const int M = 60009;
int licznik;
int tab[M],pom[M];
void scal(int p, int sr, int k);
void mergesort(int p, int k)
{
    if(p<k)
    {
        int sr=(p+k)/2;
        mergesort(p,sr);
        mergesort(sr+1, k);
        scal(p,sr,k);
    }
}
void scal(int p, int sr, int k)
{
    int i,j,q;
    for(int i=p; i<=k; i++) pom[i]=tab[i];

    i=p,j=sr+1,q=p;
        while(i<=sr&&j<=k)
        {
            if(pom[i]<=pom[j])
            {
                tab[q]=pom[i];
                q++,i++;

            }
            else
            {
                tab[q]=pom[j];
                q++,j++;
               // cout<<"sr "<<sr<<" "<<"p "<<p<<endl;
                int buf=sr+1-i;
                licznik+=buf;
            }
        }
    while (i<=sr)
    {
        tab[q]=pom[i];
        i++,q++;
    }
}
int main()
{
      ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>tab[i];
    mergesort(0,n-1);
    cout<<licznik;
}
