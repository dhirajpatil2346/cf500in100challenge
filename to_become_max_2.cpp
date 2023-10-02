#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

bool f(int ind, int need, vector<int> &v, int K)
{
    if (K < 0)
        return false;
    if (ind >= v.size())
        return false;
    if (v[ind] >= need)
        return true;
    // next must be need-1
    int act = need - v[ind];
    return f(ind + 1, need - 1, v, K - act);
    // 
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    int ans = v.back();
    for (int i = 0; i < n - 1; i++)
    {
        int l = v[i], r = v[i] + k;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (f(i, m, v, k))
            {
                ans = max(ans, m);
                l = m + 1;
            }
            else
                r = m - 1;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}