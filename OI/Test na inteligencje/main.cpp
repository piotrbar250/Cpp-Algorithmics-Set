#include <iostream>
#include <vector>
using namespace std;
const int M = 1000009;
int n,m;
int granica=0;
vector<int> vec[M];
int bin_search(int x)
{
    int p=0, k=vec[x].size()-1, sr;
    while(p<k)
    {
        sr=(p+k)/2;
        if(vec[x][sr]<granica)
            p=sr+1;
        else
            k=sr;
    }
    return vec[x][p];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        vec[a].push_back(i);
    }

    cin>>m;
    for(int i=0; i<m; i++)
    {
        bool ok = true;
        granica=0;
        int k;
        cin>>k;

        for(int j=0; j<k; j++)
        {
            int a;
            cin>>a;

            if(vec[a].size()==0)
                ok=false;
            if(ok)
            {
                int wynik = bin_search(a);
                if(wynik<granica)
                    ok=false;
                else
                    granica=wynik+1;
            }
        }
        if(ok)
            cout<<"TAK"<<endl;
        if(!ok)
            cout<<"NIE"<<endl;
    }
}
