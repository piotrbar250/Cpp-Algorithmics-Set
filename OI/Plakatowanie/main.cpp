#include<bits/stdc++.h>
using namespace std;

const int M = 1 << 18;
const long long INF = 10000000000;
int n, counter;
long long minimum = INF;
long long arr[M], tree[2*M+10];

map <long long, int> blocks;

void make_tree()
{
    for(int i=1; i<=n; i++)
        tree[i+M-1] = arr[i];
    for(int i=M-1; i>=1; i--)
        tree[i] = min(tree[2*i], tree[2*i+1]);
}

void find_base(int pza, int kza, int jes, int pjes, int kjes)
{
    if(pza>kjes || kza<pjes)
        return;
    if(pza<=pjes && kza>=kjes)
    {
        minimum = min(minimum, tree[jes]);
        return;
    }

    find_base(pza, kza, 2*jes, pjes, (pjes+kjes)/2);
    find_base(pza, kza, 2*jes+1, (pjes+kjes)/2+1, kjes);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=1; i<2*M; i++)
        tree[i] = INF;

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        long long a,b;
        cin>>a>>b;
        arr[i] = b;
    }
    make_tree();

    for(int i=1; i<=n; i++)
    {
        if(blocks.find(arr[i]) == blocks.end())
        {
            blocks[arr[i]] = i;
            counter++;
        }
        else
        {
            find_base(blocks[arr[i]],i,1,1,M);
            if(minimum == arr[i])
                blocks[arr[i]] = i;
            else
            {
                blocks[arr[i]] = i;
                counter++;
            }
            minimum = INF;
        }
    }

    cout<<counter;
}
