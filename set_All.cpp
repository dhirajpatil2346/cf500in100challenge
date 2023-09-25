#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<set<int>> v(n);
    set<int> f;
    for (int i = 0; i < n; i++)
    {
        int sz;
        cin >> sz;
        while (sz--)
        {
            int x;
            cin >> x;
            v[i].insert(x);
            f.insert(x);
        }
    }
    // input done
    int ans = 0;
    for (auto &val : f)
    {
        // i have to exclude val
        set<int> curr;
        for (auto &st : v)
        {
            if (st.find(val) == st.end())
            {
                for (auto &child : st)
                    curr.insert(child);
            }
        }
        ans = max(ans, (int)curr.size());
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