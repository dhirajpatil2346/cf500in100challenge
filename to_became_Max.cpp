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
    vector<int> pref = v, suff = v, suffSum = v;
    for (int i = 1; i < n; i++)
        pref[i] = max(pref[i], pref[i - 1]);
    for (int i = n - 2; i >= 0; i--)
        suff[i] = max(suff[i], suff[i + 1]);
    for (int i = n - 2; i >= 0; i--)
        suffSum[i] += suffSum[i + 1];
    vector<int> right(n);
    int ind = n - 1;
    for (int i = n - 1; i > 0; i--)
    {
        if (v[i] >= v[ind])
            ind = i;
        right[i - 1] = ind;
    }
    int ans = *max_element(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++)
    {
        //  we want this I to be maximum
        int K = k;
        int eleright = right[i] - i + 1;
        LL rightsum = suff[i];
        if (right[i] != (n - 1))
            rightsum -= suff[right[i] + 1];
        int norm = eleright * suff[i] - rightsum;
        K -= norm;
        if (K <= 0)
            continue;
        ans = max(ans, suff[i] + K / eleright, max(0, K % eleright));
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