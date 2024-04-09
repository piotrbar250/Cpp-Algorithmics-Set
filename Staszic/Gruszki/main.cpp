#include <bits/stdc++.h>
using namespace std;

const int M = 1 << 20;
int n,k;
int arr[M],cust[M];
int tree[2*M];

void make_tree()
{
    for(int i=1; i<=n; i++)
        tree[i+M-1] = arr[i];
    for(int i=M-1; i>=1; i--)
        tree[i] = max(tree[2*i],tree[2*i+1]);
}

void find_min(int x)
{
    //cout<<"bef "<<x<<endl;
    if(tree[1]<x)
    {
       // cout<<"WYPIER"<<endl;
        cout<<"-1"<<" ";
        return;
    }
    //cout<<"po "<<x<<endl;
    int jes = 1;
    //cout<<"   "<<x<<endl;
    while(jes<M-1)
    {
        //cout<<"while jes "<<jes<<" "<<x<<endl;
        //cout<<tree[2*jes]<<endl;
        if(tree[2*jes]>=x)
            jes = jes*2;
        else
            jes = jes*2+1;
        //cout<<"po"<<endl;
    }

    tree[jes]-=x;
    cout<<jes-M+1<<" ";
    jes/=2;
    while(jes>=1)
    {
        tree[jes] = max(tree[jes*2],tree[jes*2+1]);
        jes/=2;
    }
   // cout<<"maks "<<tree[1]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    cin>>k;
    for(int i=1; i<=k; i++)
        cin>>cust[i];

    make_tree();

    for(int i=1; i<=k; i++)
    {
        find_min(cust[i]);
    }

}
