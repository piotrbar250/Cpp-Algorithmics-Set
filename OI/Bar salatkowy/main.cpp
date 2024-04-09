#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 9;
int n;
string s;
stack < pair<int,int> > peaks;
int res;
int pos[M];

int main()
{ 
    cin >> n >> s;
    s = " " + s;

    int down, sum = 0;
    if(s[1] == 'p')
        down = 1;
    else
        down = -1;

    for(int i=1; i<=n; i++)
    {
        if(s[i] == 'p')
            sum++;
        else
           sum--;

        pos[i] = sum;

        if(s[i-1] == 'j' and s[i] == 'p')
            down = i;
        if((s[i] == 'p' and s[i+1] == 'j') or (s[i] == 'p' and i == n))
        {
            pair <int,int> new_peak = {sum, down};
            while(!peaks.empty() and peaks.top().first <= new_peak.first)
            {
                if(pos[new_peak.second] >= pos[peaks.top().second])
                    new_peak = {sum, peaks.top().second};
                peaks.pop();
            }
            peaks.push(new_peak);
            res = max(res, i - new_peak.second + 1);
        }
    }
    cout << res << endl;
    return 0;
}
