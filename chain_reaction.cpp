#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

int f(int ind, vector<int> &pos, vector<int> &power, vector<int> &dp)
{
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int posi = pos[ind];
    int ret = 1;
    int newpos = lower_bound(pos.begin(), pos.end(), pos[ind] - power[ind]) - pos.begin() - 1;
    ret += f(newpos, pos, power, dp);
    return dp[ind] = ret;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> pos(n), power(n), dp(n, -1);
    vector<pair<int, int>> vp(n);
    for (auto &val : vp)
        cin >> val.first >> val.second;
    sort(vp.begin(), vp.end());
    for (int i = 0; i < n; i++)
        pos[i] = vp[i].first, power[i] = vp[i].second;
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, n - f(i, pos, power, dp));
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