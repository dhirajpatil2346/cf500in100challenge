#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    vector<int> ans;
    LL bc = 0;
    for (int i = 0; i < n; i++)
    {
        LL curr = bc + 1;
        if (curr != v[i])
        {
            ans.push_back(curr);
        }
        else
        {
            curr++;
            ans.push_back(curr);
        }
        bc = ans.back();
    }
    cout << ans.back() << endl;
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