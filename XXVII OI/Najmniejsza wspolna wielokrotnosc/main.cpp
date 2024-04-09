#include <bits/stdc++.h>
using namespace std;

const int M = 100000, N = 10;
int z;
unsigned long long m;
unsigned long long sq;

vector <unsigned long long> conditions[N];
pair <unsigned long long, unsigned long long> res;
bool found;

unsigned long long my_gcd(unsigned long long a, unsigned long long b)
{
    if(a % b == 0)
        return b;
    return my_gcd(b,a%b);
}

bool check(unsigned long long x)
{
    unsigned long long l = x;
    unsigned long long gcd = x;
    unsigned long long lcm = x;
    while(true)
    {
        x++;
        if(m%x != 0)
            return false;
        gcd = __gcd(lcm,x);
        lcm /= gcd;
        unsigned long long mult = x*lcm;
        if(__builtin_mul_overflow(x, lcm, &mult))
            return false;
        lcm = mult;
        if(lcm == m)
        {
            cout<<l <<" " << x <<"\n";
            return true;
        }
    }
}

bool check_divisors()
{
    for(int i=1; i<=sq; i++)
        if(m % i == 0)
            if(check(i) == true)
                return true;
    return false;
}

void change(unsigned long long l, unsigned long long ln)
{
    res.first = l;
    res.second = l + ln - 1;
}

unsigned long long bs_check(unsigned long long md, unsigned long long ln, unsigned long long d)
{
    unsigned long long start = 1; 
    for(unsigned long long i=md; i<md+ln; i++)
    {
        unsigned long long var = start * i;
        if(__builtin_mul_overflow(start, i, &var))
        {
            return (ULLONG_MAX - 1);
        }
     
        start = var; 
    }
    return start;
}

unsigned long long check_24(unsigned long long md)
{
    bool divided = false;
    unsigned long long start = 1; 

    for(unsigned long long i=md; i<md+5; i++)
    {
        unsigned long long j = i;
        if(!divided && j%2 == 0)
        {
            divided = true;
            j /= 2;
        }
        unsigned long long var = start * j;
        if(__builtin_mul_overflow(start, j, &var))
        {
            return (ULLONG_MAX - 1);
        }
     
        start = var; 
    }
    return start;
}

unsigned long long binary_24()
{
    unsigned long long l = 1, r = 1e9, md;
    unsigned long long val = 12*m;

    while(l<r)
    {
        md = (l+r) / 2;
        if(check_24(md) < val)
            l = md + 1;
        else
            r = md;
    }
    return l;
}

void binary_search_function(unsigned long long ln, unsigned long long d)
{
    unsigned long long l = 1, r = 1e9, md;
    unsigned long long val = d*m;
    if(__builtin_mul_overflow(d,m,&val))
    {
        l = binary_24();
        goto lcm_check;
    }
    while(l<r)
    {
        md = (l+r) / 2;
        if(bs_check(md,ln,d) < val)
            l = md + 1;
        else
            r = md;
    }

    lcm_check:

    unsigned long long lcm = l;
    unsigned long long gcd = l;
    for(unsigned long long i=l+1; i<l+ln; i++)
    {   
        if(lcm >= i)
            gcd = my_gcd(lcm,i);
        else if(lcm < i)
            gcd = my_gcd(i,lcm);
        unsigned long long var = i / gcd;
        lcm = lcm * var;
    }
    if(lcm == m) 
    {
        if(!found)
        {
            found = true;
            change(l,ln);
        }
        else
        {
            if(res.first == l && res.second > l+ln-1)
                change(l,ln);
            if(res.first > l);
                change(l,ln);
        }
    }
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    conditions[2] = {1};
    conditions[3] = {1,2};
    conditions[4] = {1,2,6};
    conditions[5] = {1,2,4,6,8,12,24};
    cin>>z;
    for(int i=1; i<=z; i++)
    {
        cin>>m;
        sq = 4000;      
        if(check_divisors() == true)
        {
            found = false;
            res.first = 0;
            res.second = 0;
            continue;
        }
        for(int i=2; i<=5; i++)
            for(auto a: conditions[i])
                binary_search_function(i,a);
        if(found)
            cout<<res.first<<" "<<res.second<<"\n";
        if(!found)
            cout<<"NIE"<<"\n";

        found = false;
        res.first = 0;
        res.second = 0;
    }
    return 0;
}