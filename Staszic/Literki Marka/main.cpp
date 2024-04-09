#include <iostream>
#define sp " "
using namespace std;
string m;
int n, d, rozne;
int ile[129];
int wynik = 9999999;
int np, nk;
bool ok(int k, int p)
{
    if (ile[m[k]] > 1 || m[k] == m[k + 1] || rozne - 1 == n)
        return true;
    return false;
}
int main()
{
    cin >> m >> n;
    m = " " + m;
    d = m.size() - 1;
    int k = 1;
    for (int p = 1; p <= d; p++)
    {
        if (ile[m[p]] == 0)
            rozne++;
        ile[m[p]]++;

        if (rozne >= n)
        {
            while (ok(k, p))
            {
                ile[m[k]]--;
                if (ile[m[k]] == 0)
                    rozne--;
                k++;
            }
            int pom = wynik;
            wynik = min(wynik, p - k + 1);
            if (pom != wynik)
            {
                np = p;
                nk = k;
            }
        }
    }
    if (!np)
        cout << "BRAK";
    else
        cout << nk << sp << np;

    return 0;
}
