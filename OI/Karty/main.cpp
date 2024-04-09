#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 9, M = 1 << 18, W = 1e7 + 1; ////////////////////////////////////////////
int n;
int arr[3][N];

pair <int,int> interval[2*M+10];
bool path[2*M+10][3][3];

void set_intervals(int L, int R, int id)
{
    interval[id] = {L,R};
    if(L == R)
        return;
    
    set_intervals(L, (L+R)/2, 2*id);
    set_intervals((L+R)/2+1, R, 2*id+1);
    return;
}

void prep(int a, int b)
{
    a = a + M - 1;
    b = b + M - 1;
    int x = a / 2;
    while(x >= 1)
    {
        for(int i=1; i<=2; i++)
            for(int j=1; j<=2; j++)
                path[x][i][j] = false;
        x /= 2;
    }
    x = b / 2;
    while(x >= 1)
    {
        for(int i=1; i<=2; i++)
            for(int j=1; j<=2; j++)
                path[x][i][j] = false;
        x /= 2;
    }
}

void set_paths()
{
    for(int i=M-1; i>=1; i--)
    {
        int left = (interval[i].first + interval[i].second) / 2;
        int right = left + 1;
        // cout << left << " halo  " << right << endl;
        for(int j=1; j<=2; j++)
            for(int k=1; k<=2; k++)
                for(int h=1; h<=2; h++)
                    for(int l=1; l<=2; l++)
                    {
                        if(path[2*i][j][k] && path[2*i+1][h][l])
                        { 
                            // cout << i << ' ' << j << ' ' << k <<" "  <<h <<" "<< l << endl;
                            // cout <<" arr " << arr[k][left] << " " << arr[h][right] << endl; 
                            if(arr[k][left] <= arr[h][right])
                            {
                                // cout <<" urban" << endl;
                                // cout <<" za urbana " << i << ' ' << j << " " << l << endl;
                                path[i][j][l] = true;
                            }
                        }
                    }
    }
}

void update(int a)
{
    int x = a + M - 1;
    x /= 2;
    while(x >= 1)
    {
        int left = (interval[x].first + interval[x].second) / 2;
        int right = left + 1;
        for(int i=1; i<=2; i++)
            for(int j=1; j<=2; j++)
                for(int k=1; k<=2; k++)
                    for(int h=1; h<=2; h++)
                        if(path[2*x][i][j] && path[2*x+1][k][h] && arr[j][left] <= arr[k][right])
                            path[x][i][h] = true;
        x /=2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie();

    set_intervals(1,M,1);
    cin >> n; 
    for(int i=1; i<=n; i++)
        cin >> arr[1][i] >> arr[2][i];

    for(int i=n+1; i<=M; i++)
        arr[1][i] = arr[2][i] = W;

    for(int i=1; i<=M; i++)
        path[i+M-1][1][1] = path[i+M-1][2][2] = true;

    set_paths();

    int q;
    cin >> q;
    while(q--)
    {
        bool exist = false;
        int a,b;
        cin >> a >> b;
        int tmp1 = arr[1][a];
        int tmp2 = arr[2][a];
        arr[1][a] = arr[1][b];
        arr[2][a] = arr[2][b];
        arr[1][b] = tmp1;
        arr[2][b] = tmp2;
        prep(a,b);
        update(a);
        update(b);
        for(int j=1; j<=2; j++)
            for(int k=1; k<=2; k++)
                if(path[1][j][k])
                    exist = true;
        if(exist)
            cout << "TAK" << "\n";
        else
            cout << "NIE" << "\n";
    }

}
