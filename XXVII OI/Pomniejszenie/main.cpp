#include <bits/stdc++.h>
using namespace std;

int q,k;
bool found;
pair <int,int> id;
string a,b,c;

void f9(int j, int changes)
{
    for(int i=j; i<a.size(); i++)
    {
        int to_end = a.size()-1 - i + 1;
        if(changes == 0)
        {
            c[i] = a[i];
        }
        else if(changes == to_end and a[i] =='9')
        {
            c[i] = '8';
            changes--;
        }
        else if(a[i] != '9')
        {
            c[i] = '9';
            changes--;
        }
        else if(a[i] == '9')
        {
            c[i] = '9';
        }
    }
}

void go_back()
{
    int j = id.first;
    int changes = id.second;
    int to_end = a.size()-1 - j + 1;
    if(j == -1)
    {
        cout<<"-1";
        found = false;
        return;
    }
    if(changes == to_end)
    {
        c[j] = b[j] - 1;
        if(c[j] == a[j])
        {
            c[j]--;
        }
        changes--;
        j++;
    }
    else if(changes != to_end)
    {
        c[j] = b[j] - 1;
        if(c[j] != a[j])
            changes--;
        j++;
    }
    f9(j,changes);
}

void first()
{
    int s = a.size()-1, left = k, to_end;
    id.first = -1;
    id.second = -1;
    for(int i=0; i<=s; i++)
    {
        if(left == 0)
        {
            c[i] = a[i];
            continue;
        }
        to_end = s - i + 1;
        if(to_end != left)
        {
            if(a[i] == b[i])
            {
                if(b[i] != '0')
                {
                    id = make_pair(i,left);
                }
                continue;
            }
            else
            {
                if(left == 1)
                {
                    bool bigger = true;
                    for(int j=i+1; j<=s; j++)
                    {
                        if(a[j] != b[j]) 
                        {
                            if(a[j] > b[j])
                            {
                                bigger = true;
                                break;
                            }
                            else if(a[j] < b[j])
                            {
                                bigger = false;
                                break;
                            }
                        }
                    }
                    if(bigger)
                    {
                        if(b[i] < '1')
                        {
                            go_back();
                            return;
                        }
                        else
                        {
                            c[i] = b[i] - 1;
                            if(c[i] == a[i])
                            {
                                f9(i+1,1);
                                return;
                            }
                            left--;
                        }
                        
                    }
                    if(!bigger)
                    {
                        c[i] = b[i];
                        left--;
                    }
                }
                else if(left != 1)
                {
                    c[i] = b[i];
                    if(b[i] != '0')
                    {
                        id = make_pair(i,left);
                    }
                    left--;
                }
                
            }
            
        }

        if(to_end == left)
        {
            if(left == 1)
            {
                if(b[i] < '1')
                {
                    go_back();
                    return;
                }
                else if(a[i] == b[i])
                {
                    c[i] = b[i] - 1;
                    left--;
                }
                else if(a[i] != b[i])
                {
                    c[i] = b[i] - 1;
                    if(c[i] == a[i])
                    {
                        if(c[i] < '1')
                        {
                            go_back();
                            return;
                        }
                        else
                        {
                            c[i]--;
                        }
                    }
                    left--;
                }
                
            }
            else if(left != 1)
            {
                if(a[i] == b[i])
                {
                    if(b[i] < '1')
                    {
                        go_back();
                        return;
                    }
                    else
                    {
                        c[i] = b[i] - 1;
                        f9(i+1,left-1);
                        return;
                        if(b[i] != 0 && !(a[i] == 0 and b[i] == 1))
                                id = make_pair(i,k-left);
                        left--;
                    }
                }
                else if(a[i] != b[i])
                {
                    c[i] = b[i];
                    if(b[i] != '0' && !(a[i] == '0' && b[i] == '1'))
                    {
                        id = make_pair(i,left);
                    }
                    left--;
                }
                
            }
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        found = true;
        c = "";
        cin>>a>>b>>k;
        c = b;
        first();
        if(found)
            for(int j=0; j<c.size(); j++)
                cout<<c[j];
        cout<<"\n";
    }
}