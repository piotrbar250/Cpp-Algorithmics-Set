#include <bits/stdc++.h>
using namespace std;

const int M = 201;
int n;
int arr[M][M];
bool wrong[M][M];

void check(int i, int j, int k)
{   
    if(arr[i][j] + arr[i][k] == arr[j][k])
        wrong[j][k] = true;
    
    else if(arr[j][i] + arr[j][k] == arr[i][k])
        wrong[i][k] = true;

    else if(arr[k][i] + arr[k][j] == arr[i][j])
        wrong[i][j] = true;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];

    for(int i=1; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            for(int k=j+1; k<=n; k++)
                check(i, j, k);

    for(int i=1; i<n; i++)
        for(int j=i+1; j<=n; j++)
            if(!wrong[i][j])
                cout << i << " " << j << "\n";
                
    return 0;
}
