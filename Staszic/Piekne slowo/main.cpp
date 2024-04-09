#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 9;
int n,k;
int kmp[M];

string p,s;

void find_pattern()
{
    int pointer = 0;
    for(int i=2; i<s.size(); i++)
    {
        while(pointer>0 && s[i] != s[pointer+1])
            pointer = kmp[pointer];

        if(s[i] == s[pointer+1])
            pointer++;

        kmp[i] = pointer;
    }
}

int main()
{
    cin>>n>>k;
    cin>>s;
    s = " " + s;
    find_pattern();

    for(auto i=1; i<=n; i++)
    {
        int x = i - kmp[i];
        x = i/x;
        if(x>=k)
            cout<<"1";
        else
            cout<<"0";
    }
}
