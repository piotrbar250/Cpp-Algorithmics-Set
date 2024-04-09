#include <bits/stdc++.h>
#include "ckollib.h"
using namespace std;
typedef unsigned int uint;

int main(void)
{
    uint *arr = new uint[3], *cnt = new uint[3];
    uint *bits = new uint[33];

    while (true)
    {
        uint k;
        k = karta();
        if (k == 0)
            break;

        if (arr[1] == 0)
            arr[1] = k, cnt[1] = 1;
        else if (arr[2] == 0 and k != arr[1])
            arr[2] = k, cnt[2] = 1;
        else
        {
            if (arr[1] == k)
                cnt[1]++;
            if (arr[2] == k)
                cnt[2]++;
        }

        uint p = k;
        uint bits_num = 0;
        while (p > 0)
        {
            if (p % 2 == 1)
                bits[bits_num]++;

            p /= 2;
            bits_num++;
        }
    }
    if(arr[2] == 0)
        odpowiedz(arr[1]);

    uint diff_cnt = max(cnt[1], cnt[2]);
    uint res = 0, power2 = 1;

    for (uint i = 0; i <= 30; i++)
    {
        if (bits[i] % diff_cnt != 0)
            res += power2;

        power2 *= 2;
    }

    odpowiedz(res);
}
