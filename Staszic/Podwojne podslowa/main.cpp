// Piotr Baranowski - C++ Developer
// Task: Podwojne podslowa
// Algorithm: Hashing
// Complexity: O(n+m)

#include <bits/stdc++.h>
using namespace std;

const int M = 1000009;
int n,m;
long long base = 997, mod7 = 1000*1000*1000+7;
long long hash_arr[M];
long long power[M];

void init()
{
    power[0] = 1;
    for(int i=1; i<M; i++)
        power[i] = (power[i-1]*base)%mod7;
}

void word_hashing(string s)
{
    for(int i=1; i<=s.size()-1; i++)
        hash_arr[i] = (hash_arr[i-1]*base + int(s[i] - 97))%mod7;
}

long long find_hash(int b, int e)
{
    long long value = (mod7 + hash_arr[e] - (hash_arr[b-1]*power[e-b+1])%mod7)%mod7;
    return value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin>>n>>s>>m;
    s = " " + s;
    init();
    word_hashing(s);

    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        if(find_hash(a, a-1+(b-a+1)/2) == find_hash(a+(b-a+1)/2, b))
            cout<<"TAK"<<endl;
        else
            cout<<"NIE"<<endl;
    }
    return 0;
}
