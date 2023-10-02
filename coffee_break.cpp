#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    map<int, int> mp;
    set<int> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
        v[i] = x;
    }
    int c = 0;
    while (s.size())
    {
        c++;
        int curr = *s.begin();
        mp[curr] = c;
        s.erase(s.begin());
        while (true)
        {
            curr += d;
            auto it = s.upper_bound(curr);
            if (it == s.end())
                break;
            curr = *it;
            s.erase(it);
            mp[curr] = c;
        }
    }
    cout << c << endl;
    for (auto &val : v)
        cout << mp[val] << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}