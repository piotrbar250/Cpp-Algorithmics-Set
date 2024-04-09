#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Polynomial
{
public:
    int n;
    vector<ll> coefficients;

    Polynomial(int n)
    {
        this->n = n;
        coefficients.resize(n + 1, 0);
        return;
    }

    ll calculate(int degree, int x)
    {
        if (degree == 0)
            return coefficients[n];
        return x * calculate(degree - 1, x) + coefficients[n - degree];
    }
};

int main()
{
    int n, x;
    cin >> n >> x;

    Polynomial p(n);
    for (int i = 0; i <= n; i++)
        cin >> p.coefficients[i];

    cout << p.calculate(n, x) << endl;
    return 0;
}
