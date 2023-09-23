#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    set<int> row, col;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            if (x)
                row.insert(i), col.insert(j);
        }
    int mn = min(n - (int)row.size(), m - (int)col.size());
    if (mn & 1)
        cout << "Ashish" << endl;
    else
        cout << "Vivek" << endl;
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