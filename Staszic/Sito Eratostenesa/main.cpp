#include <iostream>
using namespace std;
const int M =  16*1000*1000;

bool zlozona[M];
int licznik, licznik2;

void sito(int n)
{
    for(long long i=2; i<=M; i++)
    {
        if(!zlozona[i])
        {
            licznik++;
            cout<<i<<endl;
            for(long long k=i*i; k<=M; k+=i)
                zlozona[k]=true;
        }
        if(licznik==n)
            return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    sito(n);
    /*for(int i=2; i<=M; i++)
    {
        if(!zlozona[i])
        {
            cout<<i<<" ";
            licznik2++;
        }
        if(licznik2==n)
            break;
    }*/
}
