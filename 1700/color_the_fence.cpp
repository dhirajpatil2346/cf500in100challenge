#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL k;
    cin >> k;
    map<char, LL> m;
    for (char i = '1'; i <= '9'; i++)
    {
        LL x;
        cin >> x;
        m[i] = x;
    }
    m['0'] = INT_MAX;
    LL mc = '0';
    for (auto &val : m)
        if (m[mc] >= val.second)
            mc = val.first;
    int freq = k / m[mc];
    if (freq == 0)
    {
        cout << -1 << endl;
        return;
    }
    vector<char> v(freq, mc);
    k %= m[mc];
    for (auto &val : v)
    {
        k += m[val];
        char c = val;
        for (char z = c; z <= '9'; z++)
            if (m[z] <= k)
                c = z;
        val = c;
        k -= m[c];
    }
    for (auto &val : v)
        cout << val;
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}