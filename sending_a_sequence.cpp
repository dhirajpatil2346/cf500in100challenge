#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    // dp represents the whether seq ends at that index or not
    for (int i = 1; i <= n; i++)
    {
        // can I make this as start
        // can I make this as end

        // now make this as end
        int ele = v[i] + 1;
        int ind = i - ele;
        if (ind >= 0)
            dp[i] = (dp[i] | dp[ind]);

        // now make it start
        // you can it if your previous was end

        //
        //
        if (dp[i - 1])
        {
            int next = i + ele - 1;
            // cout << i << " " << next << endl;
            if (next <= n)
            {
                dp[next] = true;
            }
        }
    }
    // 
    if (dp.back())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
//