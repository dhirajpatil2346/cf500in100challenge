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
    v[0]--;
    int bob = 1;
    for (int i = 2; i < n; i++)
        if (v[bob] >= v[i])
            bob = i;
    int alice = 0;
    for (int i = 1; i < n; i++)
        if (i != bob && v[alice] >= v[i])
            alice = i;
    bob = v[bob], alice = v[alice];
    if (bob <= alice)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
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