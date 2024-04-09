#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    if(n == 1)
    {
        cout<<"1 a";
        return 0;
    }
    if(n == 2)
    {
        cout<<"2 ab";
        return 0;
    }
    if(n == 3)
    {
        cout<<"2 aba";
        return 0;
    }
    cout<<"3"<<endl;
    string s1 = "a";
    string s2 = "b";
    string s3 = "ab";

    while(true)
    {
        string s4 = s3;
        for(int j=0; j<s4.size(); j++)
        {
            if(s4[j] == 'a')
                s4[j] = 'b';
            else
                s4[j] = 'a';
        }
        s3 = s3 + s4;
        if(s3.size() >= n)
            break;
    }
    
    for(int i=0; i<n; i++)
    {
        if(s3[i] == s3[i+1])
            cout<<"c";
        else
            cout<<s3[i];
    }
    cout<<endl;
    return 0;
}
