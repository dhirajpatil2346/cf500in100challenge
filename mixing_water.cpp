#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ld long double
#define endl "\n"

const ld one = 1, two = 2;
ld value(LL step, ld &h, ld &c)
{
    ld fact = step;
    return ((fact * h) + ((fact - one) * c)) / (fact + fact - one);
}

LL solve()
{
    ld h, c, t, two = 2, one = 1;
    cin >> h >> c >> t;
    ld thresh1 = value(2ll, h, c), thresh2 = (h + c) / two;
    // cout << fixed << thresh1 << " " << thresh2 << endl;
    // it decrease from thresh1 to thresh2
    vector<pair<LL, ld>> vp;
    vp.push_back({1, h});
    vp.push_back({2, thresh2});
    vp.push_back({3, thresh1});
    if (t > thresh2 && t < thresh1)
    {

        // step 1 : find greatest index such that it's greater than target
        LL l = 2, r = 1e9;
        LL s1 = -1, s2 = -1;
        // cout << "test for 7 through 4 " << value(4ll, h, c) << endl;
        while (l <= r)
        {
            LL mid = (l + r) / 2ll;
            ld curr = value(mid, h, c);
            // cout << mid << " " << curr << endl;
            if (curr > t)
            {
                s1 = mid;
                l = mid + 1ll;
            }
            else
                r = mid - 1ll;
        }
        if (s1 != 1)
        {
            vp.push_back({s1 * 2ll - 1ll, value(s1, h, c)});
            vp.push_back({(s1 - 1ll) * 2ll - 1ll, value(s1 - 1ll, h, c)});
            vp.push_back({(s1 + 1ll) * 2ll - 1ll, value(s1 + 1ll, h, c)});
        }
        // step 2 : find lowest index such that it's such lower than target
        l = 2, r = 1e9;
        while (l <= r)
        {
            LL mid = (l + r) / 2ll;
            ld curr = value(mid, h, c);
            if (curr < t)
            {
                s2 = mid;
                r = mid - 1ll;
            }
            else
                l = mid + 1ll;
        }
        if (s2 != -1)
        {
            vp.push_back({s2 * 2ll - 1ll, value(s2, h, c)});
            vp.push_back({(s2 - 1ll) * 2ll - 1ll, value(s2 - 1ll, h, c)});
            vp.push_back({(s2 + 1ll) * 2ll - 1ll, value(s2 + 1ll, h, c)});
        }
        // cout << "S1s2 " << s1 << " " << s2 << endl;
    }
    vector<pair<ld, LL>> fin;
    for (auto val : vp)
        fin.push_back({abs(t - val.second), val.first});
    // for (auto &val : vp)
    //     cout << fixed << val.first << " " << val.second << endl;
    sort(fin.begin(), fin.end());
    return fin[0].second;
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
        cout << solve() << endl;
    }
    return 0;
}