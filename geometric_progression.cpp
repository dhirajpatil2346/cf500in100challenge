#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, k;
    cin >> n >> k;
    vector<LL> v(n), two(n), three(n);
    for (auto &val : v)
        cin >> val;
    map<LL, LL> m;
    // for two
    for (int i = 0; i < n; i++)
    {
        if (v[i] % k == 0)
        {
            if (m.find(v[i] / k) != m.end())
                two[i] = m[v[i] / k];
        }
        m[v[i]]++;
    }

    // for three
    m.clear();
    for (int i = 0; i < n; i++)
    {
        if (v[i] % k == 0)
        {
            if (m.find(v[i] / k) != m.end())
                three[i] = m[v[i] / k];
        }
        m[v[i]] += two[i];
    }
    cout << accumulate(three.begin(), three.end(), 0ll) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}