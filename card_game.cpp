#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

LL f(LL ind, vector<LL> &v, int even, vector<vector<LL>> &dp_front)
{
    if (ind >= v.size())
        return 0;
    if (dp_front[ind][even] != -1)
        return dp_front[ind][even];
    // don't choose
    LL ret = 0;
    ret = max(ret, f(ind + 1, v, abs(even - 1), dp_front));
    // choose
    if (even == 0)
    {
        // it is even
        ret = max(ret, f(ind + 1, v, even, dp_front));
    }
    else
    {
        // it is odd
        ret = max(ret, v[ind] + f(ind + 1, v, even, dp_front));
    }
    // cout << ind << " " << even << " " << ret << endl;
    return dp_front[ind][even] = ret;
}
LL F(LL ind, vector<LL> &v, vector<LL> &dp_back)
{
    if (ind < 0)
        return 0;
    // don't choose
    if (dp_back[ind] != -1)
        return dp_back[ind];
    LL ret = F(ind - 1, v, dp_back);
    bool even = ind & 1;
    // if(ind is even ) means its odd
    // choose
    if (even)
    {
        // it is even
        ret = max(ret, F(ind - 1, v, dp_back));
    }
    else
    {
        // it is odd
        ret = max(ret, v[ind] + F(ind - 1, v, dp_back));
    }
    // cout << ind << " " << even << " " << ret << endl;
    return dp_back[ind] = ret;
}

void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    vector<vector<LL>> dp_front(n, vector<LL>(2, -1));
    f(0, v, 1, dp_front);
    vector<LL> odd(n);
    if (v[0])
        odd[0] = v[0];
    for (int i = 1; i < n; i++)
        if (i & 1)
            odd[i] = odd[i - 1];
        else
        {
            if (v[i])
                odd[i] = odd[i - 1] + v[i];
            else
                odd[i] = odd[i - 1];
        }
    LL ans = dp_front[0][1];
    // for (auto &val : odd)
    //     cout << val << " ";
    // cout << endl;
    for (int i = 0; i < n; i++)
    {
        LL curr = odd[i];
        if (i < (n - 1))
        {
            if (i % 2 == 0)
                // i is odd so next will be even
                curr += dp_front[i + 1][0];
            else
                curr += dp_front[i + 1][1];
        }
        ans = max(ans, curr);
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