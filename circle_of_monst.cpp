#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

void solve()
{
    LL n;
    cin >> n;
    vector<pair<LL, LL>> vp(n);
    for (auto &val : vp)
        cin >> val.first >> val.second;
    int mI = 0;
    for (int i = 1; i < n; i++)
    {
        if (vp[mI].first != vp[i].first)
        {
            if (vp[i].first < vp[mI].first)
                mI = i;
        }
        else
        {
            if (vp[i].second > vp[mI].second)
                mI = i;
        }
    }
    int start = mI;
    LL ans = vp[start].first;
    vp[start].first = 0;
    LL dmg = vp[start].second;
    int i = mI;
    i++;
    i %= n;
    // cout << "mI : " << mI << endl;
    while (i != mI)
    {
        if (dmg == 0)
        {
            ans += vp[i].first;
            dmg = vp[i].second;
            i++;
            i %= n;
        }
        cout << "main " << i << " " << dmg << endl;
        while (i != mI)
        {
            bool stop = false;
            cout << dmg << " " << vp[i].first << " --> ";
            vp[i].first -= dmg;
            cout << "sub " << i << " " << vp[i].first << endl;
            if (vp[i].first <= 0)
            {
                dmg = vp[i].second;
                i++;
                i %= n;
            }
            else
            {
                dmg = 0;
                break;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}