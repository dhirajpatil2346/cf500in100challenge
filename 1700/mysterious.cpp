#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

// int f(int ind, vector<pair<int, int>> &vp, vector<int> &dp)
// {
//     if (ind == vp.size())
//         return 0;
//     // don't take
//     int ret = f(ind + 1, vp, dp);
//     ret = max(ret, 1 + f(upper_bound(vp.begin(), vp.end(), vp[ind].second) - vp.begin(), vp, dp));
//     return ret;
// }

void solve()
{
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> vp(n + 1);
    int x, y;
    cin >> x >> y;
    vp[0].first.first = 0, vp[0].first.second = 0, vp[0].second = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> vp[i].first.first >> vp[i].first.second;
        vp[i].second = i;
    }
    sort(vp.begin(), vp.end());
    // for (auto &val : vp)
    //     cout << val.first.first << " " << val.first.second << endl;
    vp[0].first.first = x, vp[0].first.second = y;
    vector<int> dp(n + 1, -1);
    vector<int> par(n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
        if (dp[i] != -1)
            for (int j = 1; j <= n; j++)
            {
                // can you go from i to j
                if (vp[j].first.first > vp[i].first.first && vp[j].first.second > vp[i].first.second)
                {
                    if (dp[j] < (1 + dp[i]))
                    {
                        par[j] = i;
                        dp[j] = 1 + dp[i];
                    }
                }
            }
    // for (auto &val : dp)
    //     cout << val << " ";
    // cout << endl;
    int ind = 0;
    for (int i = 1; i <= n; i++)
        if (dp[i] >= dp[ind])
            ind = i;
    vector<int> ans;
    while (ind > 0)
    {
        ans.push_back(vp[ind].second);
        ind = par[ind];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto &val : ans)
        cout << val << " ";
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