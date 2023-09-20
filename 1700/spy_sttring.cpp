#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

string ans = "-1";
bool fault = false;
bool check(string &curr, vector<string> &v)
{
    for (auto &val : v)
    {
        int c = 0;
        for (int i = 0; i < val.length(); i++)
            c += (val[i] != curr[i]);
        if (c > 1)
            return false;
    }
    return true;
}

void f(int ind, vector<string> &v, string curr, int &m)
{
    if (fault)
        return;
    if (ind == m)
    {
        if (check(curr, v))
            ans = curr;
        return;
    }
    set<char> s;
    for (auto &val : v)
        s.insert(val[ind]);
    for (auto &val : s)
    {
        string cz = curr;
        cz.push_back(val);
        f(ind + 1, v, cz, m);
    }
}

void solve()
{
    ans = "-1";
    fault = false;
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &val : v)
        cin >> val;
    f(0, v, "", m);
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
        cout << ans << endl;
    }
    return 0;
}