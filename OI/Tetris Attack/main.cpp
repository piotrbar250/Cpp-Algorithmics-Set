#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<bool> arr(n + 9, 0);
    vector<int> tmp, res;
    stack<int> main_stack;

    for (int i = 1; i <= 2 * n; i++)
    {
        int a;
        cin >> a;
        if (!arr[a])
        {
            main_stack.push(a);
            arr[a] = true;
        }
        else if (arr[a])
        {
            while (main_stack.top() != a)
            {
                tmp.push_back(main_stack.top());
                res.push_back(main_stack.size());
                main_stack.pop();
            }
            main_stack.pop();
            for (int t = tmp.size() - 1; t >= 0; t--)
                main_stack.push(tmp[t]);
            tmp.clear();
        }
    }

    cout << res.size() << endl;
    for (auto x : res)
        cout << x << ' ' << endl;
    return 0;
}
