#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

int f(int ind, vector<int> &a, int &l, int &r, int &h, int c, vector<vector<int>> &dp)
{
    if (ind == a.size())
        return 0;
    if (dp[ind][c] != -1)
        return dp[ind][c];
    int ret = 0;
    int next = c + a[ind] - 1;
    next %= h;
    ret = ((next >= l && next <= r) + f(ind + 1, a, l, r, h, next, dp));
    next++;
    next %= h;
    ret = max(ret, ((next >= l && next <= r) + f(ind + 1, a, l, r, h, next, dp)));
    return dp[ind][c] = ret;
}

void solve()
{
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n);
    for (auto &val : a)
        cin >> val;
    vector<vector<int>> dp(n, vector<int>(h, -1));
    cout << f(0, a, l, r, h, 0, dp) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}