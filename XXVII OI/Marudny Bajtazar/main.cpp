// Piotr Baranowski
#include <bits/stdc++.h>
using namespace std;

//unordered_set <string> mset[21]; /// na wejsciowe slowo
unordered_map <string,int> mapa[21];
int vpow[25];
string s;
int n, m;
int d;

void qp()
{
    vpow[1] = 2;
    for(int i=2; i<=20; i++)
        vpow[i] = vpow[i-1] * 2;
}

void modify(int p)
{
    for(int l=max(1,p-d+1); l<=p; l++)
    {
        string slowo = "";
        for(int r=l; r-l+1 <=d; r++)
        {
            if(r > n)
                break;
            slowo += s[r];
            if(p <= r)
            {
                mapa[r-l+1][slowo]--;
                if(mapa[r-l+1][slowo] == 0)
                {
                    mapa[r-l+1].erase(slowo);
                    //mset[r-l+1].erase(slowo);
                }
            }

        }
    }
}

void modify2(int p)
{
    for(int l=max(1,p-d+1); l<=p; l++)
    {
        string slowo = "";
        for(int r=l; r-l+1 <=d; r++)
        {
            if(r > n)
                break;
            slowo += s[r];
            if(p <= r)
            {
                mapa[r-l+1][slowo]++;
                //mset[r-l+1].insert(slowo);
            }
        }
    }
}

int main()
{
    qp();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    d = 15;

    for(int i=1; i<=n; i++)
    {
        string slowo = "";
        for(int j=i; j-i+1 <= d; j++)
        {
            if(j > n)
                break;
            slowo += s[j];
            //mset[j-i+1].insert(slowo);
            mapa[j-i+1][slowo]++;
        }
    }
    for(int i=1; i<=d; i++)
    {
        if((int)(mapa[i].size()) < vpow[i])
        {
            cout << i << "\n";
            break;
        }
    }

    while(m--)
    {
        int a;
        cin >> a;
        modify(a);
        if(s[a] == '0')
            s[a] = '1';
        else if(s[a] == '1')
            s[a] = '0';

        modify2(a);
        for(int i=1; i<=d; i++)
        {
            if((int)(mapa[i].size()) < vpow[i])
            {
                cout << i << "\n";
                break;
            }
        }
    }
}