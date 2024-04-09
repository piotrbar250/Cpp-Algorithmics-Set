#include <bits/stdc++.h>
using namespace std;

const int M = 500010;
int n,m;

class obstacle
{
public:

    int x;
    long long p; /// top
    long long q; /// bottom

    void add_obstacle()
    {
        cin>>x>>q>>p;
    }
};

obstacle arr[M];

void pokaz(pair <int,int> x)
{
    cout<<x.first<<" "<<x.second<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++)
        arr[i].add_obstacle();

    bool ok = true;
    pair <long long, long long> range;
    pair <long long, long long> curr_interval;

    range.first = arr[1].x; /// top
    range.second = arr[1].x * (-1); /// bottom

    for(int i=1; i<=n; i++)
    {
        //cout<<i<<endl;
        if(!ok)
            break;

        if(range.first <= arr[i].q || range.second >= arr[i].p)
            ok = false;

        if(!ok)
            break;

        curr_interval.first = min(range.first, arr[i].p - 1);
        //cout<<"   "<<range.first<<" "<<arr[i].p -1<<endl;
        curr_interval.second = max(range.second, arr[i].q + 1);

        //cout<<" "<<curr_interval.first<<" "<<curr_interval.second<<endl;

        if((curr_interval.first%2 != 0 && arr[i].x%2 == 0) || (curr_interval.first%2 == 0 && arr[i].x%2 != 0))
            curr_interval.first--;

        if((curr_interval.second%2 != 0 && arr[i].x%2 == 0) || (curr_interval.second%2 == 0 && arr[i].x%2 != 0))
            curr_interval.second++;

        if(curr_interval.first < curr_interval.second)
            ok = false;

        if(!ok)
            break;

        range.first = curr_interval.first + (arr[i+1].x - arr[i].x);
        range.second = curr_interval.second - (arr[i+1].x - arr[i].x);

    }
    if(!ok)
        cout<<"NIE"<<endl;
    else
    {
        long long result = (arr[n].x + curr_interval.second)/2;
        cout<<result;
    }
}
