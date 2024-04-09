#include <bits/stdc++.h>
    using namespace std;

    const int N = 1e3 + 9, M = 1e6 + 9, P = 1e5 + 9, inf = 1e9 + 10;
    int n, p;
    struct Item
    {
        int value;
        int a;
        int b;
    };

    struct Plan
    {
        int index;
        int value;
        int a;
        int b;
    };
    Item arr[N];
    Plan query[M];
    int dp[3][P], ans[M];

    bool cmp(const Item &a, const Item &b)
    {
        return a.a < b.a;
    }

    bool cmp2(const Plan &a, const Plan &b)
    {
        return a.a < b.a;
    }

    void count_dp()
    {
        dp[0][0] = dp[1][0] = inf;
        for(int i=0; i<=1; i++)
            for(int j=1; j<P; j++)
                dp[i][j] = 0;

        int pointer = 1; // wskaznik na piewszy ktory trzeba jeszcze odpowiedziec

        stack <Plan> sta;

        for(int i=p; i>=1; i--)
            sta.push(query[i]);

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<P; j++)
                dp[0][j] = dp[1][j];
            for(int j=1; j<P; j++)
                dp[1][j] = 0;

            for(int j=1; j<P; j++)
            {
                dp[1][j] = dp[0][j];
                if(arr[i].value <= j)
                {
                    if(dp[0][j-arr[i].value] >= arr[i].a)
                    {
                        dp[1][j] = max(dp[1][j], min(dp[0][j-arr[i].value], arr[i].b-1));
                    }
                }
            }

            while(!sta.empty() and arr[i].a > sta.top().a)
                sta.pop();

            while(i != n and !sta.empty() and sta.top().a < arr[i+1].a)
            {
                if(dp[1][sta.top().value] >= sta.top().b)
                {
                    // cout << "2:   " << i << " "  << sta.top().index << endl;
                    ans[sta.top().index] = true;
                }
                sta.pop();
            }
        }

        while(!sta.empty())
        {
            if(dp[1][sta.top().value] >= sta.top().b)
            {
                // cout << "3:   " << n << " "  << sta.top().index << endl;
                ans[sta.top().index] = true;
            }
            sta.pop();
        }
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        /// przypadek, ze mamy pte zapytanie w dp

        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> arr[i].value >> arr[i].a >> arr[i].b;

        sort(arr+1, arr+1+n, cmp);

        cin >> p;
        for(int i=1; i<=p; i++)
        {
            int m, k, s;
            cin >> m >> k >> s;
            query[i] = {i, k, m, m+s};
        }

        sort(query+1, query+1+p, cmp2);
        count_dp();

        // cout << n << " n" << endl;
        // for(int i=0;i<=n; i++)
        // {
        //     cout << i << ":  ";
        //     for(int j=0; j<=7; j++)
        //         cout << dp[i][j] << ' ';
        //     cout << endl;
        // }
        // cout << endl << endl;


        for(int i=1; i<=p; i++)
        {
            cout << ((ans[i]) ? "TAK" : "NIE");
            cout << endl;
        }
    }
