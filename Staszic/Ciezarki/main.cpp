#include <iostream>
#include <vector>
using namespace std;

const int M = 1000009;
int n,result;

class bar
{
public:

    int durability;
    int weight;
    int father;
};

bar arr[M];
bar vec[M];

bool ok(int x)
{
    for(int i=1; i<=x; i++)
    {
        vec[i].durability=arr[i].durability;
        vec[i].weight=arr[i].weight;
        vec[i].father=arr[i].father;
    }
    for(int i=x; i>=1; i--)
        vec[vec[i].father].weight+=vec[i].weight;

    for(int i=1; i<=x; i++)
        if(vec[i].weight>vec[i].durability)
            return false;
    return true;
}

void bin_search()
{
    int b=1,e=n,md;
    while(b<e)
    {
        md=(b+e)/2;
        if(ok(md))
            b=md+1;
        else
            e=md;
    }
    result=b;
}

int main()
{
   cin>>n;
   for(int i=1; i<=n; i++)
   {
       int a,b,c;
       cin>>a>>b>>c;
       arr[i].durability=a;
       arr[i].weight=b;
       arr[i].father=c;
   }
   if(ok(n))
   {
       cout<<"NIE"<<endl;
       return 0;
   }
   bin_search();
   cout<<result;
}
