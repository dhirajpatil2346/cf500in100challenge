#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    int ans = *max_element(v.begin(), v.end());
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> vn = v;
        int K = k;
        // start from i
        for (int j = i; j >= 0; j--)
        {
            if (vn[j] <= vn[j + 1])
            {
                // possible
                int possmoves = 0;
                possmoves = vn[j + 1] + 1 - v[j];
                possmoves = min(possmoves, K);
                K -= possmoves;
                vn[j] += possmoves;
            }
        }
        ans = max(ans, *(max_element(vn.begin(), vn.end())));
    }
    // 

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