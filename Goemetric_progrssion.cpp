#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, k;
    cin >> n >> k;
    LL ans = 0;
    map<LL, LL> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    for (auto &val : m)
    {
        LL curr = val.first;
        LL cans = val.second;
        if (curr % k == 0 && m.find(curr / k) != m.end())
        {
            cans *= m[curr / k];
            curr /= k;
        }
        else
        {
            continue;
        }
        if (curr % k == 0 && m.find(curr / k) != m.end())
        {
            cans *= m[curr / k];
            curr /= k;
        }
        else
        {
            continue;
        }
        ans += cans;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}