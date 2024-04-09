#include <bits/stdc++.h>
#include "arc.h"
using namespace std;

int main()
{
    vector<int> sta;
    queue<int> Q;
    int k = inicjuj();

    while (true)
    {
        int x = wczytaj();
        if (x == 0)
        {
            vector<int> rear;
            rear.push_back(0);
            while (!Q.empty())
            {
                rear.push_back(Q.front());
                Q.pop();
            }
            for (int i = 1; i < rear.size(); i++)
            {
                while (sta.size() >= i + 1 and sta.back() < rear[i])
                    sta.pop_back();
                sta.push_back(rear[i]);
            }
            for (int i = 1; i <= k; i++)
                wypisz(sta[i - 1]);
            break;
        }
        Q.push(x);
        if (Q.size() == k)
        {
            int v = Q.front();
            while (sta.size() > 0 and sta.back() < v)
                sta.pop_back();
            sta.push_back(v);
            Q.pop();
        }
    }
    return 0;
}