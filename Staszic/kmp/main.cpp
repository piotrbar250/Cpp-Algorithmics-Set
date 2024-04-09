// Piotr Baranowski - C++ Developer 

#include <bits/stdc++.h>
using namespace std;

const int M = 2000009;
int pointer = 1;
int pref[M];

bool kmp(string s, int d)
{
    int curr_pointer = 0;
    for(int i=2; i<=s.size()-1; i++)
    {
        while(curr_pointer>0 && s[i] != s[curr_pointer+1])
            curr_pointer = pref[curr_pointer];
        if(s[i] == s[curr_pointer+1])
            curr_pointer++;
        pref[i] = curr_pointer;

        if(pref[i] == d && i-2*d>=pointer)
        {
            pointer = i-d;
            return true;
        }
    }
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    for(int j=1; j<=n; j++)
    {
        pointer = 1;
        bool been = false, ok = true;
        string s,p=" ",o;
        cin>>o>>s;
        o = " " + o;
        for(int i=1; i<=o.size()-1; i++)
        {
            if(o[i] !='*')
                been = false;
            if(!been)
                p+=o[i];
            if(o[i] == '*')
                been = true;
        }
        if(p[p.size()-1] != '*')
            p+='*';

        string k = " ";
        for(int i=1; i<=p.size()-1; i++)
        {
            if(p[i] != '*')
                k+=p[i];
            if(p[i] == '*')
            {
                string k2 = k + '#' + s;
                if(!kmp(k2, k.size()-1))
                {
                    ok = false;
                    break;
                }
                k = " ";
            }
        }
        if(ok)
            cout<<"Jest."<<"\n";
        if(!ok)
            cout<<"Nie ma go."<<"\n";
    }
}
