// Piotr Baranowski
// Task: Wielokaty II Olimpiada Informatyczna

#include <bits/stdc++.h>
using namespace std;

const int M = 5e3 + 9;
struct diagonal
{
    int a, b, id;
};

int n, k, res;
int closest_dis = 5008;
diagonal arr[M], closest;

void shift()
{
    int addend;
    if(closest.b - closest.a != closest_dis and closest.a != 1)
        return;

    addend = closest.a;
    for(int i=1; i<=k; i++)
    {
        arr[i].a = (arr[i].a - 1 - addend + n) % n + 1;
        arr[i].b = (arr[i].b - 1 - addend + n) % n + 1;
        if(arr[i].a > arr[i].b)
            swap(arr[i].a, arr[i].b);
    }
    return;
}

diagonal binary_search_diagonal(int firstid, int posA, int baseB)
{
    int l = firstid, r = k, md, res = -1;
    while (l <= r)
    {
        md = (l + r) / 2;
        if (arr[md].a >= posA)
        {
            r = md - 1;
            if (arr[md].b <= baseB)
                res = md;
        }
        else
            l = md + 1;
    }

    if (res != -1)
        return arr[res];
    return {0, 0, -1};
}

bool cmp(diagonal x, diagonal y)
{
    if (x.a != y.a)
        return x.a < y.a;
    return x.b > y.b;
}

void find_polygons(diagonal base)
{
    vector<int> neigh;
    int curr_res = 1;
    diagonal curr_diagonal = binary_search_diagonal(base.id + 1, base.a, base.b);
    if (curr_diagonal.id == -1)
    {
        res = max(res, base.b - base.a + 1);
        return;
    }

    curr_res += curr_diagonal.a - base.a + 1;
    while (true)
    {
        neigh.push_back(curr_diagonal.id);
        diagonal next_diagional = binary_search_diagonal(base.id + 1, curr_diagonal.b, base.b);
        if (next_diagional.id == -1)
        {
            curr_res += base.b - curr_diagonal.b;
            res = max(res, curr_res);
            break;
        }
        curr_res += next_diagional.a - curr_diagonal.b + 1;
        curr_diagonal = next_diagional;
    }

    for (int d : neigh)
        find_polygons(arr[d]);
    return;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a > b)
            swap(a,b);
        arr[i] = {a, b, 0};
        if (min(b-a, n-b+a) < closest_dis)
        {
            closest = arr[i];
            closest_dis = min(b-a, n-b+a); 
        }

    }
    shift();
    sort(arr + 1, arr + 1 + k, cmp);
    for (int i = 1; i <= k; i++)
        arr[i].id = i;

    res = n - arr[1].b + arr[1].a + 1;

    find_polygons(arr[1]);

    cout << res << endl;
    return 0;
}
