/// Piotr Baranowski
/// Task: Para naszyjnikow
/// Programming lanuguage: C++

#include <bits/stdc++.h>
using namespace std;

class Program
{
private:
    static const int M = 1e5 + 9;
    int t, n, m;
    int res;
    int arr1[M], arr2[M];
    int pref1[M], pref2[M];
    vector<int> answers;

public:
    void input()
    {
        cin >> t;
        while (t--)
        {
            res = 0;
            cin >> n >> m;

            for (int i = 1; i <= n; i++)
                arr1[i] = pref1[i] = 0;
            for (int i = 1; i <= m; i++)
                arr2[i] = pref2[i] = 0;

            if (n >= m)
            {
                for (int i = 1; i <= n; i++)
                    cin >> arr1[i];
                for (int i = 1; i <= m; i++)
                    cin >> arr2[i];
            }
            else
            {
                swap(n, m);
                for (int i = 1; i <= m; i++)
                    cin >> arr2[i];
                for (int i = 1; i <= n; i++)
                    cin >> arr1[i];
            }

            init();
            process();
        }
        return;
    }

    vector<int> solve()
    {
        return answers;
    }

private:
    void init()
    {
        for (int i = 1; i <= n; i++)
        {
            arr1[i] %= 2;
            pref1[i] = pref1[i - 1] + arr1[i];
        }

        for (int i = 1; i <= m; i++)
        {
            arr2[i] %= 2;
            pref2[i] = pref2[i - 1] + arr2[i];
        }
        return;
    }

    void process()
    {
        int mainarr1[n + 1], mainarr2[n + 1];

        for (int i = 1; i <= n - m + 1; i++)
            if ((pref1[i + m - 1] - pref1[i - 1]) % 2 == pref2[m] % 2)
                res = m;

        // 4 possible combinations

        // L - R
        // l - r
        for (int i = 1; i <= n; i++)
            mainarr1[i] = arr1[i];
        for (int i = 1; i <= m; i++)
            mainarr2[i] = arr2[i];
        find_result(mainarr1, mainarr2);

        // L - R
        // r - l
        for (int i = 1; i <= n; i++)
            mainarr1[i] = arr1[i];
        for (int i = 1; i <= m; i++)
            mainarr2[i] = arr2[m - i + 1];
        find_result(mainarr1, mainarr2);

        // R - L
        // l - r
        for (int i = 1; i <= n; i++)
            mainarr1[i] = arr1[n - i + 1];
        for (int i = 1; i <= m; i++)
            mainarr2[i] = arr2[i];
        find_result(mainarr1, mainarr2);

        // R - L
        // r - l
        for (int i = 1; i <= n; i++)
            mainarr1[i] = arr1[n - i + 1];
        for (int i = 1; i <= m; i++)
            mainarr2[i] = arr2[m - i + 1];
        find_result(mainarr1, mainarr2);

        answers.push_back(res);
        return;
    }

    void find_result(int *mainarr1, int *mainarr2)
    {
        int first0 = m + 1, first1 = m + 1;

        for (int i = 1; i <= m; i++)
            if (mainarr2[i] == 0)
                first0 = min(first0, i);
            else if (mainarr2[i] == 1)
                first1 = min(first1, i);

        int ln, rn, lm, rm;

        for (int i = 1; i <= n; i++)
        {
            int len1 = m - first1 + 1;
            int len2 = m - first0 + 1;
            if (mainarr1[i] == 0 and first1 != -1)
            {
                ln = i;
                rn = min(n, i + len1 - 1);
                lm = first1;
                rm = lm + rn - ln; // rm = lm + (rn - ln + 1) - 1
                int s1 = pref1[rn] - pref1[ln - 1];
                int s2 = pref2[rm] - pref2[lm - 1];
                if (s1 % 2 == s2 % 2)
                    res = max(res, rn - ln + 1);
                else
                    res = max(res, rn - ln);
            }
            if (mainarr1[i] == 1 and first0 != -1)
            {
                ln = i;
                rn = min(n, i + len2 - 1);
                lm = first0;
                rm = lm + rn - ln;
                int s1 = pref1[rn] - pref1[ln - 1];
                int s2 = pref2[rm] - pref2[lm - 1];
                if (s1 % 2 == s2 % 2)
                    res = max(res, rn - ln + 1);
                else
                    res = max(res, rn - ln);
            }
        }
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Program root;
    root.input();
    vector<int> answers = root.solve();

    for (auto x : answers)
        cout << x << endl;
    return 0;
}
