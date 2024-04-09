// Piotr Baranowski
// Zadanie: Tablica binarna XXVIII Olimpiada Informatyczna

#include <bits/stdc++.h>
using namespace std;

const int M = 1009;
int n, m, q, res;
int arr[M][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    while (q--)
    {
        int x1, y1, x2, y2, x, y;
        cin >> x1 >> y1 >> x2 >> y2;
        int dx[] = {0, x2, x1 - 1, x2, x1 - 1};
        int dy[] = {0, y2, y2, y1 - 1, y1 - 1};

        for (int i = 1; i <= 4; i++)
        {
            x = dx[i];
            y = dy[i];
            if (x == 0 || y == 0)
                continue;
            if (!arr[x][y])
                arr[x][y] = true, res++;
            else
                arr[x][y] = false, res--;
        }
        cout << res << "\n";
    }
    return 0;
}