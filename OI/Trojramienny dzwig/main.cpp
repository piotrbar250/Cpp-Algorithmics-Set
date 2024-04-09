#include <bits/stdc++.h>
using namespace std;

const int M = 4 * 1e5 + 9;
int n,p,q;
bool vis[M];

struct operation
{
    int a,b,c;
};
vector <operation> vec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> p >> q >> n;
    if(p > q) 
        swap(p,q);

    for(int i=1; i<=n; i++)
    {
        if(vis[i])
            continue;
        vis[i] = true;
        vis[i+p+q] = true;
        if(!vis[i+p])
        {
            vis[i+p] = true;
            vec.push_back({i,i+p,i+p+q});
        }
        else if(!vis[i+q])
        {
            vis[i+q] = true;
            vec.push_back({i,i+q,i+p+q});
        }
    }

    cout << vec.size() << endl;
    for(auto v: vec)
        cout << v.a << " " << v.b << " " << v.c << endl;
    return 0;
}