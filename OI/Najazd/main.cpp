#include <bits/stdc++.h>
using namespace std;

const int N = 609, M = 10009;
int n, m;
int sum = 0;
int res = (-1) * 1e9;

class Point 
{
public:
    int x, y, w;
    Point() {}

    Point(int x, int y, int w)
    {
        this -> x = x;
        this -> y = y;
        this -> w = w;
    }
    
    Point operator +(Point p)
    {
        return {x + p.x, y + p.y, w + p.w};
    }       

    Point operator -(Point p)
    {
        return {x - p.x, y - p.y, w};
    }

    Point operator *(int k)
    {
        return {x * k, y * k, w};
    }
};

Point polygon[N], arr[M];
pair <int,int> section[N][N];

// sorting
int cross_product(Point v, Point w)
{
    return v.x * w.y - w.x * v.y;
}

int orient(Point a, Point b, Point c)
{
    if(cross_product(b-a, c-a) > 0)
        return 1;
    if(cross_product(b-a, c-a) == 0)
        return 0;
    if(cross_product(b-a, c-a) < 0)
        return -1;
}

bool cmp(Point a, Point b)
{
    if(a.x == 0 && a.y == 0) 
        return true;
    if(b.x == 0 && b.y == 0)
        return false;
    
    if(cross_product(a,b) < 0)
        return true;
    return false;
}

int mod(int x)
{
    return ((x-1) + n) % n + 1;
}

void translate(Point w)
{
    for(int i=1; i<=n; i++)
        polygon[i] = polygon[i] + w;
    
    for(int i=1; i<=m; i++)
        arr[i] = arr[i] + w;
}

bool check(int i, int j, int k)
{
    if(orient(polygon[i], polygon[j], arr[k]) == orient(polygon[i], polygon[j], polygon[mod(i+1)]))
    {
        if(orient(polygon[i], polygon[j], arr[k]) != 0)
            return true;
    }
    return false;
}

ostream& operator <<(ostream& os, Point p)
{
    return os << p.x << " " << p.y << " " << p.w << endl;
}

void find_res(int i, int j, int k)
{
    int tmp = sum - section[i][j].first - section[j][k].first - section[k][i].first;
    res = max(res, tmp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int x, y;
        cin >> polygon[i].x >> polygon[i].y;
        polygon[i].w = 0;
    }

    cin >> m;
    for(int i=1; i<=m; i++)
    {
        int x, y, w;
        cin >> arr[i].x >> arr[i].y >> arr[i].w;
        sum += arr[i].w;
    }

    for(int i=1; i<=n; i++)
    {
        Point base = polygon[i];
        translate(base * (-1));
        sort(arr+1, arr+1+m, cmp);
        
        int j = mod(i+1);
        int k = 1;
        int cnt = 0;
        while(arr[k].x == 0 and arr[k].y == 0)
            k++;
        k--;
        while(j != i)
        {
            while(k+1 <= m && check(i, j, k+1))
            {
                k++;
                cnt += arr[k].w;
            }
            section[i][j].first = cnt;
            section[i][j].second = sum - cnt;
            j = mod(j+1);
        }
        translate(base);
    }

    for(int i=1; i<=n-2; i++)
        for(int j=i+1; j<=n-1; j++)
            for(int k=j+1; k<=n; k++)
                find_res(i, j, k);
    
    cout << res << endl;
    return 0;
}
