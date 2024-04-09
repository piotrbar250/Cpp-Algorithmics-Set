#include <bits/stdc++.h>
using namespace std;

const int M = 1009;
const long long base = 2, mod7 = 1000*1000*1000+9;
int n,m,x,y,result;

int arr[M][M],pa[M][M];
int pref_suf[M];
long long indexx[M][M], pa_index[M][M], power[M];

string pattern = " ";
string words[M];


void init()
{
    power[0]=1;
    for(int i=1; i<M; i++)
        power[i] = (power[i-1]*base)%mod7;
}

void convert(int k)
{
    char c[15];
    sprintf(c, "%d", k);
    pattern+=c;
    pattern+='#';
}

void convert2(int k, int i)
{
    char c[15];
    sprintf(c, "%d", k);
    words[i]+=c;
    words[i]+='#';
}

void patern_hashing()
{
    for(int i=1; i<=y; i++)
    {
        for(int j=1; j<=x; j++)
            pa_index[j][i] = (pa_index[j-1][i]*base + pa[j][i])%mod7;
        convert(pa_index[x][i]);
    }
}

void map_hashing()
{
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            indexx[j][i] = (indexx[j-1][i]*base + arr[j][i])%mod7;
            if(j>=x)
            {
                long long value = (mod7 + indexx[j][i] - (indexx[j-x][i]*power[x])%mod7)%mod7;
                convert2(value, j);
            }
        }
    }
}

void kmp(string s, int j)
{
    int pointer = 0;
    pref_suf[1] = 0;
    for(int i=2; i<=s.size()-1; i++)
    {
        while(pointer>0 && s[i] != s[pointer+1])
            pointer = pref_suf[pointer];
        if(s[i] == s[pointer+1])
            pointer++;
        pref_suf[i] = pointer;

        if(pref_suf[i] == pattern.size()-1)
            result++;
    }
}

int main()
{
    init();
    cin>>n>>m>>x>>y;
    swap(n,m);
    swap(x,y);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            //int a = getcha<int>();
            cin>>arr[i][j];
        }

    for(int i=1; i<=x; i++)
        for(int j=1; j<=y; j++)
        {
            cin>>pa[i][j];
        }

    patern_hashing();
    map_hashing();
    for(int i=x; i<=n; i++)
    {
        string u = pattern + '$' + words[i];
        //cout<<u<<endl;
        kmp(u,i);
    }
    cout<<result<<"\n";
}
