#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int u = 0;
    if (n == 1)
    {
        cout << "Bob " << (s[0] - 'a' + 1) << endl;
        return;
    }
    if (!(n & 1))
    {
        for (int i = 0; i < n; i++)
        {
            u += (s[i] - 'a' + 1);
        }
    }

    else
    {
        int u1 = 0, u2 = 0;
        for (int i = 0; i < n - 1; i++)
            u1 += (s[i] - 'a' + 1);
        u1 -= (s[n - 1] - 'a' + 1);
        for (int i = 1; i < n; i++)
            u2 += (s[i] - 'a' + 1);
        u2 -= (s[0] - 'a' + 1);
        u = max(u1, u2);
    }
    cout << "Alice " << u << endl;
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