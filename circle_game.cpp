#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    if (n & 1)
    {
        cout << "Mike" << endl;
    }
    else
    {
        int mn1 = 1e9, mn2 = 1e9;
        for (int i = 0; i < n; i += 2)
            mn1 = min(mn1, v[i]);
        for (int i = 1; i < n; i += 2)
            mn2 = min(mn2, v[i]);
        if (mn1 <= mn2)
            cout << "Joe" << endl;
        else
            cout << "Mike" << endl;
    }
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