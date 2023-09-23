#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> evenRaze, oddRaze, evenBreach, oddBreach;
    //  If the single last digit is odd, then Raze wins, else Breach wins.
    for (int i = 1; i <= n; i++)
    {
        int dig = s[i - 1] - '0';
        // Raze can select on odd
        if (i & 1)
        {
            if (dig & 1)
                oddRaze.push_back(dig);
            else
                evenRaze.push_back(dig);
        }
        // Breach can select on even
        else
        {
            if (dig & 1)
                oddBreach.push_back(dig);
            else
                evenBreach.push_back(dig);
        }
    }
    bool rz = true;
    for (int i = 0; i < n - 1; i++, rz = !rz)
    {
        // raze try to save odd and Breach save even
        if (rz)
            if (evenRaze.size())
                evenRaze.pop_back();
            else
                oddRaze.pop_back();
        else
        {
            if (oddBreach.size())
                oddBreach.pop_back();
            else
                evenBreach.pop_back();
        }
    }
    int left = 0;
    for (auto val : evenRaze)
        left = val;
    for (auto val : evenBreach)
        left = val;
    for (auto val : oddBreach)
        left = val;
    for (auto val : oddRaze)
        left = val;
    if (left & 1)
        cout << 1 << endl;
    else
        cout << 2 << endl;
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