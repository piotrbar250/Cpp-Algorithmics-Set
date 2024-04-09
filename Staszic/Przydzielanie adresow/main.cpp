// Piotr Baranowski - C++ Developer

#include <bits/stdc++.h>
using namespace std;

const long long M = 100009, base=997;
const long long mod7 = 1000000007;
const long long mod9 = 1000000009;

long long hash_table[M], hash_table2[M];
long long power[M], power2[M];

unordered_set<long long> mset;
unordered_set<long long> mset2;

void init()
{
    power[0]=1;
    for(int i=1; i<M-1; i++)
        power[i] = (power[i-1]*base)%mod7;
}

void init2()
{
    power2[0]=1;
    for(int i=1; i<M-1; i++)
        power2[i] = (power2[i-1]*base)%mod9;
}

void hashing(int d, string s)
{
    for(int i=1; i<=d; i++)
        hash_table[i] = (hash_table[i-1]*base + int(s[i]))%mod7;
}

void hashing2(int d, string s)
{
    for(int i=1; i<=d; i++)
        hash_table2[i] = (hash_table2[i-1]*base + int(s[i]))%mod9;
}

long long single_hashing(int d, string s)
{
    long long a=0, b=0;
    for(int i=1; i<=d; i++)
    {
        a = (b*base + int(s[i]))%mod7;
        b=a;
    }
    return a;
}

long long single_hashing2(int d, string s)
{
    long long a=0, b=0;
    for(int i=1; i<=d; i++)
    {
        a = (b*base + int(s[i]))%mod9;
        b=a;
    }
    return a;
}

void part_hashing(int d, int k, string s)
{
    for(int i=k; i<=d; i++)
    {
        long long value = (mod7 + hash_table[i] - (hash_table[i-k]*power[k])%mod7)%mod7;
        mset.insert(value);
    }
}

void part_hashing2(int d, int k, string s)
{
    for(int i=k; i<=d; i++)
    {
        long long value = (mod9 + hash_table2[i] - (hash_table2[i-k]*power2[k])%mod9)%mod9;
        mset2.insert(value);
    }
}

int main()
{
    init();
    init2();

    string word;
    cin>>word;
    word = " " + word;
    hashing(word.size()-1, word);
    hashing2(word.size()-1, word);

    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int m,d;
        cin>>m;

        string s;
        cin>>s;
        s = " " + s;
        part_hashing(word.size()-1, s.size()-1, word);
        part_hashing2(word.size()-1, s.size()-1, word);

        long long key = single_hashing(s.size()-1, s);
        long long key2 = single_hashing2(s.size()-1, s);
        if(mset.find(key) != mset.end() && mset2.find(key2) != mset2.end())
            cout<<"OK"<<endl;
        else
            cout<<"NIE"<<endl;

        for(int j=2; j<=m; j++)
        {
            cin>>s;
            s = " " + s;
            long long key = single_hashing(s.size()-1, s);
            long long key2 = single_hashing2(s.size()-1, s);
            if(mset.find(key) != mset.end()&& mset2.find(key2) != mset2.end())
                cout<<"OK"<<endl;
            else
                cout<<"NIE"<<endl;
        }

        mset.clear();
        mset2.clear();
    }
}
