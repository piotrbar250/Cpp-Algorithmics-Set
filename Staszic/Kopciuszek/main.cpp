#include <iostream>
using namespace std;

int main()
{
ios_base::sync_with_stdio(false); 
cin.tie(0);
cout.tie(0);
    int n,licznik=0;
    cin>>n;
    char tab[n];
    bool zero = false;
    for(int i=0; i<n; i++)
    {
        char a;
        cin>>a;
        if(a>48 && a<=58 && zero==false)
        {
            tab[0]=a;
            zero=true;
            licznik=1;
        }
        else if(a>=48 && a<=58 && zero==true)
        {
            tab[licznik]=a;
            licznik++;
        }
    }
    if(licznik==0)
        {
            cout<<"0";
            return 0;
        }
    for(int i=0; i<licznik; i++)
        cout<<tab[i];
}
