#include <bits/stdc++.h>
using namespace std;

const int M = 1 << 20;
int n;

int arr[M], arr2[M];
int tree[2*M + 100];

unordered_map <int,int> mapa;
unordered_map <int,int> mapa2;

bool cmp(int a, int b)
{
    return b<a;
}

void find_base(int pza, int kza, int jes, int pjes, int kjes, int val)
{
    if(pza>kjes || kza<pjes)
        return;
    if(pjes>=pza && kjes<=kza)
    {
        tree[jes] += val;
        return;
    }

    find_base(pza, kza, 2*jes, pjes, (pjes+kjes)/2, val);
    find_base(pza, kza, jes*2+1, (pjes+kjes)/2+1, kjes, val);
    return;
}

int read(int x)
{
    int v = x + M - 1;
    int sum = 0;
    while(v>=1)
    {
        sum += tree[v];
        v/=2;
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        arr[i] = a;
        mapa[a] = i;
        arr2[i] = arr[i];
    }

    sort(arr2+1,arr2+n+1, cmp);

    for(int i=1; i<=n; i++)
    {
        int index = mapa[arr2[i]]; // index of the element
        int result = index - 1 - read(index);
        find_base(index+1, n, 1, 1, M, 1);
        mapa2[arr2[i]] = result;
    }

    for(int i=1; i<=n; i++)
        cout<<mapa2[arr[i]]<<"\n";
}
