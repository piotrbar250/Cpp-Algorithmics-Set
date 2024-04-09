#include <bits/stdc++.h>
using namespace std;

const int M = 1<<20;
int n,k;
int arr[M];
int tree[4*M], ad[4*M];

struct object
{
    int x;
    int index;
    pair <int,int> width;
};

object arr2[M];

void make_tree()
{
    for(int i=1; i<=n; i++)
        tree[M + i - 1] = arr[i];
    for(int i=M-1; i>=1; i--)
        tree[i] = max(tree[2*i], tree[2*i+1]);
}

void update(int x)
{
    if(x == 1)
        return;
    x/=2;
    while(x>=1)
    {
        tree[x] = max(tree[2*x], tree[2*x+1]) + ad[x];
        x/=2;
    }
}
void find_base(int pza, int kza, int jes, int pjes, int kjes, int val)
{
    if(pza>kjes || kza<pjes)
        return;
    if(pjes>=pza && kjes<=kza)
    {
        tree[jes] += val;
        ad[jes] += val;
        update(jes);
        return;
    }
    find_base(pza, kza, 2*jes, pjes, (pjes+kjes)/2, val);
    find_base(pza, kza, 2*jes+1, (pjes+kjes)/2+1, kjes, val);
    return;
}

bool cmp(object a, object b)
{
    if(a.x == b.x)
        return a.index > b.index;

    return a.x < b.x;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0)
;    cin>>n;
    for(int i=1; i<=2*n; i+=2)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        arr2[i].x = a;
        arr2[i].width.first = b+M;
        arr2[i].width.second = d+M;
        arr2[i].index = i;

        arr2[i+1].x = c;
        arr2[i+1].width.first = b+M;
        arr2[i+1].width.second = d+M;
        arr2[i+1].index = i * -1;
    }

    sort(arr2+1, arr2+1+2*n,cmp);
  
    int result=0;
    for(int i=1; i<=2*n; i++)
    {
        if(arr2[i].index>=1)
        {
            //cout<<"tu:"<<endl;
            //cout<<arr2[i].width.first<<" "<<arr2[i].width.second<<endl;
            find_base(arr2[i].width.first, arr2[i].width.second,1,1,2*M,1);
        }
        else
        {
            //cout<<"ta"<<endl;
            //cout<<arr2[i].width.first<<" "<<arr2[i].width.second<<endl;
            find_base(arr2[i].width.first, arr2[i].width.second,1,1,2*M,-1);
        }
        //cout<<"tree "<<tree[1]<<endl;
        result = max(result, tree[1]);
    }
    cout<<result<<endl;
    return 0;

}
