#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    string s;
    cin >> s;
    if (s.length() == 2)
    {
        cout << s[1] << endl;
        return;
    }
    vector<char> v;
    for (auto &val : s)
        v.push_back(val);
    sort(v.begin(), v.end());
    cout << v[0] << endl;
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