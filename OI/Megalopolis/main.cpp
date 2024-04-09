#include <iostream>
#include <vector>
using namespace std;
const int M = 1 << 18;
vector<int> vec[M];
int number=1,number2;
int preorder[M], postorder[M], distances[M], tree[2*M+9];
bool visited[M], not_leave[M];
void order(int v)
{
    visited[v]=true;
    preorder[v]=number;
    number++;
    for(int i=0; i<vec[v].size(); i++)
    {
        if(!visited[vec[v][i]])
        {
            distances[vec[v][i]]=distances[v]+1;
            order(vec[v][i]);
        }
    }
    if(!not_leave[v])
    {
        number2=preorder[v];
        postorder[v]=number2;
    }
    if(not_leave[v])
        postorder[v]=number2;
}
void find_base(int pza, int kza, int jes, int pjes, int kjes)
{
    if(pza>kjes || kza<pjes)
        return;
    if(pjes>=pza && kjes<=kza)
    {
        tree[jes]++;
        return;
    }
    find_base(pza, kza, 2*jes, pjes, (pjes+kjes)/2);
    find_base(pza, kza, 2*jes+1, (pjes+kjes)/2+1, kjes);
}
int count_values(int v)
{
    int sum=0;
    v+=M-1;
    while(v>=1)
    {
        sum+=tree[v];
        v/=2;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    for(int i=1; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
        not_leave[a]=true;
    }
    distances[1]=0;
    order(1);

    int q;
    cin>>q;
    for(int i=1; i<n+q; i++)
    {
        char z;
        cin>>z;
        if(z=='A')
        {
            int a,b;
            cin>>a>>b;
            find_base(preorder[b], postorder[b],1,1,M);
        }

        else
        {
            int a;
            cin>>a;
            cout<<distances[a]-count_values(preorder[a])<<"\n";
        }
    }
    
    return 0;
}