// Piotr Baranowski
// Task: Wycinek
// Language: C++
// Algorithm: Binary Search

#include <bits/stdc++.h>
using namespace std;

const int M = 1000009;
int n,s,result;

struct number
{
    long long value;
    int index;
};

number x;
number arr[M];
vector <number> bs_vec;

template <typename T> T getcha()
{
    int negat = false, cha = getchar_unlocked();
    T res= (T)0;
    while(!isdigit(cha))
    {
        if(cha == '-')
            negat = true;
        cha = getchar_unlocked();
    }
    while(isdigit(cha))
    {
        res *= 10;
        res += cha - '0';
        cha = getchar_unlocked();
    }
    if(negat)
        res *= -1;
    return res;
}

bool cmp(number a, number b)
{
    if(a.value != b.value)
        return a.value < b.value;
    return a.index < b.index;
}

void bin_search(long long x, int e)
{
    if(x == 0)
    {
        result = max(result, e);
        return;
    }

    int l = 1, r = bs_vec.size() - 1, md;
    while(l < r)
    {
        md = (l + r) / 2;
        if(bs_vec[md].value < x)
            l = md + 1;
        else
            r = md;
    }
    if(bs_vec[l].value == x && bs_vec[l].index <= e)
        result = max(result, e-bs_vec[l].index);
    return;
}

int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    
    n = getcha<int>();
    s = getcha<int>();
    for(int i=1; i<=n; i++)
    {
        int a = getcha<int>();
        arr[i].value = a +arr[i-1].value;
        arr[i].index = i;
    }
    sort(arr+1, arr+1+n, cmp);
    x.value = -M;
    x.index = 0;
    bs_vec.push_back(x);

    for(int i=1; i<=n; i++)
    {
        if(arr[i].value != bs_vec[bs_vec.size()-1].value)
        {
            x.value = arr[i].value;
            x.index = arr[i].index;
            bs_vec.push_back(x);
        }
    }

    for(int i=1; i<=n; i++)
        bin_search(arr[i].value - s, arr[i].index);

    if(result != 0)
        cout<<result<<"\n";
    else
        cout<<"BRAK"<<"\n";
    return 0;
}
