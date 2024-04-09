#include <bits/stdc++.h>
using namespace std;

const int M = 65000, inf = INT_MAX - 9;
int n;
int prime_numbers[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23};

// pair <candidate, number of divisors>
vector <pair <int,int> > candidates;

// all highly composite numbers not greater that n
vector <int> antiprime_numbers;


void find_candidates(int number, int exponent, int divisors, int iterator)
{
    candidates.push_back({number, divisors});
    int var = 1;
    for(int i=1; i<=exponent; i++)
    {
        int tmp = var * prime_numbers[iterator];
        if(__builtin_mul_overflow(var, prime_numbers[iterator], &tmp))
            break;
        else
            var = tmp;
        
        tmp = number * var;
        if(!(__builtin_mul_overflow(number, var, &tmp)) && tmp <= n)
            find_candidates(number * var, i, divisors * (i+1), iterator+1);
        else
            break;
    }
    return;
}

ostream& operator <<(ostream& os, pair<int,int> p)
{
    return os << p.first << " " << p.second << endl;
}

int main()
{
    cin >> n;
    find_candidates(1, 30, 1, 1);

    sort(candidates.begin(), candidates.end());

    int max_divisors = 0;
    for(auto v: candidates)
    {
        if(v.second > max_divisors)
        {
            antiprime_numbers.push_back(v.first);
            max_divisors = v.second;
        }
    }
    cout << antiprime_numbers.back();

    return 0;
}
