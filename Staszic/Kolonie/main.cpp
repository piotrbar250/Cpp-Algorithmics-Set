// Kolonie 2 wlasne Find and Union
#include <iostream>
using namespace std;

const int M = 1000009;
int n,z;
int F[M], mass[M], max_iq[M], min_iq[M];

int fnd(int x)
{
    if(F[x]==x)
        return x;
    return fnd(F[x]);
}

void un(int a, int b)
{
    int x=fnd(a), y=fnd(b);
    if(x!=y)
    {
        F[x]=y;
        mass[y]+=mass[x];
        max_iq[y]=max(max_iq[y], max_iq[x]);
        min_iq[y]=min(min_iq[y], min_iq[x]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++)
        F[i]=i;
    for(int i=1; i<=n; i++)
    {
        cin>>mass[i]>>max_iq[i];
        min_iq[i]=max_iq[i];
    }

    //cin>>z;
    string napis;
    while(cin>>napis)
    {
        if(napis=="JOIN")
        {
            int a,b;
            cin>>a>>b;
            un(a,b);
        }
        if(napis=="MASA")
        {
            int a;
            cin>>a;
            cout<<mass[fnd(a)]<<endl;
        }
        if(napis=="IQ_MAX")
        {
            int a;
            cin>>a;
            cout<<max_iq[fnd(a)]<<endl;
        }
        if(napis=="IQ_MIN")
        {
            int a;
            cin>>a;
            cout<<min_iq[fnd(a)]<<endl;
        }
    }
}
