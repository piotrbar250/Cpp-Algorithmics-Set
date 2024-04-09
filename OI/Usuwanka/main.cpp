#include <bits/stdc++.h>
using namespace std;

const int M = 1000009;
int n, k, number;
long long sum;
string s;

vector <int> vec[M];
stack < pair <int,int> > S;
queue <int> Q;
stack <int> sqs;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    cin>>s;
    s = " " + s;

    for(int i=1; i<=n; i++)
    {
        int var;

        if(s[i] == 'b')
            var = 1;
        else
            var = k * (-1);

        S.push(make_pair(var,i));
        Q.push(var);
        sum += var;

        if(Q.size() > k+1)
        {
            sum -= Q.front();
            Q.pop();            
        }
        //cout<<"i "<<i<<" sum "<<sum<<endl;
        //cout<<"momentum "<<Q.size()<<endl;

        if(sum == 0)
        {
            //cout<<"hier"<<endl;
            while(!Q.empty())
                Q.pop();
            number++;
            for(int j=1; j<=k+1; j++)
            {   
                pair <int,int> x;
                x = S.top();
                S.pop();
                vec[number].push_back(x.second);
            }
            int s1 = S.size();
            int p = min(k+1, s1);
            vector < pair<int,int> > pom;
            pom.clear();
            while(p--)
            {
                pom.push_back(S.top());
                S.pop();
            }
            p = min(k+1, s1);
            for(int j=p-1; j>=0; j--)
            {
                S.push(pom[j]);
                pair <int,int> x;
                x = pom[j];
                Q.push(x.first);
                sum += x.first;
            }   
        }
    }
    for(int i=number; i>=1; i--)
    {
        for(int j=k; j>=0; j--)
            cout<<vec[i][j]<<" ";
        cout<<endl;
    }
}
