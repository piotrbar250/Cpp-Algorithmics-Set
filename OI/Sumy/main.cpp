#include <bits/stdc++.h>
using namespace std;

const int M = 5 * 1e4 + 9, N = 5 * 1e3 + 9, inf = 1e9 + 9;
int n,q, mod;
int arr[N], low_num[M];
bool vis[M];
priority_queue < pair<int,int> > pq;

void dijkstra()
{
    for(int i=1; i<mod; i++)
        low_num[i] = inf;

    low_num[0] = 0;
    pq.push({0,0});
    while(!pq.empty())
    {
        int x = pq.top().second;
        int num = pq.top().first * (-1);
        pq.pop();

        if(vis[x])
            continue;
        vis[x] = true;
        for(int i=1; i<=n; i++)
        {
            int var = num + arr[i];
            int mo = var % mod;
            if(low_num[mo] > var)
            {
                low_num[mo] = var;
                pq.push({var*(-1),mo});
            }
        }
    }

}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    mod = arr[1];
    dijkstra();

    cin >> q;

    while(q--)
    {
        int a;
        cin >> a;
        int mo = a % mod;
        if(low_num[mo] <= a)
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
    }
    return 0;
}
