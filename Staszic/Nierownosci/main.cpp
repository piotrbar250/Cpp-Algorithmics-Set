#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int M = 500*1000+20;
vector<int> vec[M];
vector<int> vec2[M];
vector<int> vec3[M];
stack<int> sta;
bool vis1[M];
bool vis2[M];
int arr[M];
int SCC_counter;
void dfs(int v)
{
    vis1[v]=true;
    for(int i=0; i<vec[v].size(); i++)
    {
        if(!vis1[vec[v][i]])
            dfs(vec[v][i]);
    }
    sta.push(v);
    //return;
}
void SCC(int v)
{
    vis2[v]=true;
    arr[v]=SCC_counter;
    vec3[SCC_counter].push_back(v);
    for(int i=0; i<vec2[v].size(); i++)
    {
        if(!vis2[vec2[v][i]])
            SCC(vec2[v][i]);
    }
    //return;
}
int main()
{
      ios_base::sync_with_stdio(false); 
  cin.tie(0);
  cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        vec[b].push_back(a);
        vec2[a].push_back(b);
    }
    for(int i=1; i<=n; i++)
    {
        if(!vis1[i])
            dfs(i);
    }
    while(!sta.empty())
    {
        int v=sta.top();
        sta.pop();
        if(!vis2[v])
        {
            SCC_counter++;
            SCC(v);
        }
    }
    /*for(int i=1; i<=SCC_counter; i++)
    {
        cout<<"numer "<<i<<endl<<endl;
        for(int j=0; j<vec3[i].size(); j++)
            cout<<vec3[i][j]<<" ";
        cout<<endl<<endl;
    }*/
    int z;
    cin>>z;
    for(int i=1; i<=z; i++)
    {
        int a,b;
        cin>>a>>b;
        if(arr[a]==arr[b])
            cout<<"Tak"<<endl;
        else
            cout<<"Nie"<<endl;
    }
}
