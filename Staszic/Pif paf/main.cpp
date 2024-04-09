// Piotr Baranowski - C++ Developer
// Task: Pif paf
// Complexity: O(nlog(logn))

#include <bits/stdc++.h>
using namespace std;

const int M = 1000009;
const int N = M + 100;
const long long base = 997, mod7 = 1000*1000*1000+7;

int n,p;
long long a,b;
string s;
bool ok;

long long hash_arr[N], power[N];
int bin_numbers[N];
vector<int> vec;

void init()
{
    power[0] = 1;
    for(int i=1; i<M; i++)
        power[i] = (power[i-1] * base)%mod7;
}

void init2()
{
    int f = 1, j = 0;
    while(j<M)
    {
        int k = f;
        while(k)
        {
            vec.push_back(k%2);
            k/=2;
        }
        for(int i=vec.size()-1; i>=0; i--)
        {
            if(j<M)
            {
                j++;
                bin_numbers[j] = vec[i];
            }
        }
        vec.clear();
        f++;
    }
}

void word_hashing()
{
    for(int i=1; i<=s.size()-1; i++)
        hash_arr[i] = (hash_arr[i-1] * base + int(s[i]) - 97)%mod7;
}

bool part_hashing(int d)
{
    p = 1;
    for(int i=3*d; i<=s.size()-1; i+=d)
    {
        p++;
        long long value = (mod7 + hash_arr[i] - (hash_arr[i-d]*power[d])%mod7)%mod7;
        if((bin_numbers[p] == 0 && value != a) || (bin_numbers[p] == 1 && value != b))
            return false;
    }
    return true;
}

long long count_hash(int b, int e)
{
    long long value = (mod7 + hash_arr[e] - (hash_arr[b-1]*power[e-b+1])%mod7)%mod7;
    return value;
}

int main()
{
    init();
    init2();
    cin>>n>>s;
    s = " " + s;
    word_hashing();

    for(int i=1; i<=(s.size()-1)/2; i++)
    {
        a = hash_arr[i];
        b = (mod7 + hash_arr[2*i] - (hash_arr[i] * power[i])%mod7)%mod7;
        if(part_hashing(i))
        {
            int buffer = (s.size()-1) / i;
            if(buffer * i == s.size()-1)
            {
                cout<<buffer<<endl;
                ok = true;
                break;
            }
            else
            {
                int buffer2 = s.size()-1 - buffer*i;
                long long buffer2_val = count_hash(buffer*i+1, s.size()-1);
                long long test1 = count_hash(1,buffer2);
                long long test2 = count_hash(i+1, i+buffer2);

                if((bin_numbers[p+1] == 0 && buffer2_val == test1) || (bin_numbers[p+1] == 1 && buffer2_val == test2))
                {
                    cout<<buffer+1<<endl;
                    ok = true;
                    break;
                }
            }
        }
    }
    if(!ok)
        cout<<"1"<<endl;
    return 0;
}
