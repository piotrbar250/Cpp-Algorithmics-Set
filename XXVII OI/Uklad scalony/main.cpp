#include <bits/stdc++.h>
using namespace std;

const int M = 1000009;
int n,m,k;
int route, number;
bool par, changed;
pair <int,int> arr[M];

typedef pair <int,int> T;
set <T> edges;
set <T> del;
set<T>::iterator it;

void snake()
{
    bool up = false;
    for(int i=1; i<=m; i++)
    {
        int v;
        if(up)
            v = i + (n-1) * m;
        if(!up)
            v = i;
        for(int j=1; j<n; j++)
        {
            if(up)
            {
                edges.insert(make_pair(v,v-m));
                v -= m;
            }
            if(!up)
            {
                edges.insert(make_pair(v, v+m));
                    v += m;
            }
        }
        if(up)
            up = false;
        else if(!up)
            up = true;
        if(i != m)
            edges.insert(make_pair(v,v+1));
    }
}

void update(bool up, bool lr, int q)
{ 
    q--;
    int ind;
    if(lr)
        ind = 0;
    if(!lr)
        ind = m + 1;

    while(q--)
    {
        if(lr)
            ind++;
        if(!lr)
            ind--;

        int v;        
        if(up)
            v = ind + (n-1) * m;
        if(!up)
            v = ind;

        for(int i=1; i<n; i++)
        {
            if(route == k)
                return;

            if(up)
            {
                if(lr)
                    edges.insert(make_pair(v,v+1));
                if(!lr)
                    edges.insert(make_pair(v,v-1));
                del.insert(make_pair(v,v-m));
                v -= m;
            }
            if(!up)
            {  
                if(lr)
                    edges.insert(make_pair(v,v+1));
                if(!lr)
                    edges.insert(make_pair(v,v-1));
                del.insert(make_pair(v, v+m));
                    v += m;
            }
            route--;
        }
        if(up)
            up = false;
        else if(!up)
            up = true;        
    }
}

void bind(int a, int b)
{
    if(route == k)
        return;
    
    bool up;
    if(m%4 == 0)
        up = true;
    else
        up = false;
 
    int v;
    if(up)
    {
        edges.insert(make_pair(a+(n-1) * m,b+(n-1) * m));
        del.insert(make_pair(a+(n-1) * m, a+(n-2) * m));
        v = a+(n-2) * m;
    }
    if(!up)
    {
        edges.insert(make_pair(a,b));
        del.insert(make_pair(a,a+m));
        v = a+m;
    }
    for(int i=1; i<n-1; i++)
    {
        if(route == k)
            return;
        if(up)
        {
            edges.insert(make_pair(v,v+1));
            del.insert(make_pair(v,v-m));
            v -= m;
        }
        if(!up)
        {
            edges.insert(make_pair(v,v+1));
            del.insert(make_pair(v,v+m));
            v += m;
        }
        route--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    if(k < n+m-2 || k > n*m-1)
    {
        cout<<"NIE"<<"\n";
        return 0;
    }
    if(n%2 == 0 && m%2 == 0 && k < n+m-1)
    {  
        cout<<"NIE"<<"\n";
        return 0;
    }
    if(n%2 != 0 && m%2 == 0)
    {
        swap(n,m);
        changed = true;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            arr[++number] = {i,j};

    snake();
    route = n*m-1;
    cout<<"TAK"<<"\n";
    

    int a = m/2;

    if(n%2 == 0 && m%2 == 0)
    {
        update(0,1,a);
        update(0,0,a);
        bind(a,a+1);
    }
    else
    {
        update(0,1,a+1);
        update(1,0,a+1);
    }
    for(it = edges.begin(); it != edges.end(); it++)
    {
        T x = *it, y;
        y.first = x.second;
        y.second = x.first;

        if(del.find(x) == del.end() && del.find(y) == del.end())
        {
            if(!changed)
                cout<<arr[x.first].first<<" "<<arr[x.first].second<<" "<<arr[x.second].first<<" "<<arr[x.second].second<<"\n";
            if(changed)
                cout<<arr[x.first].second<<" "<<arr[x.first].first<<" "<<arr[x.second].second<<" "<<arr[x.second].first<<"\n";
        }
    }
}