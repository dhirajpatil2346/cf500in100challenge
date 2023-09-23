#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    multiset<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v1.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v2.insert(x);
    }
    bool f = true;
    while (v1.size() && v2.size())
    {
        if (f)
        {
            int a = *v1.begin(), b = *prev(v2.end());
            v1.erase(v1.begin()), v2.erase(prev(v2.end()));
            int A = a - b, B = b - a;
            if (A > 0)
                v1.insert(A);
            if (B > 0)
                v2.insert(B);
        }
        else
        {
            int a = *v2.begin(), b = *prev(v1.end());
            v2.erase(v2.begin()), v1.erase(prev(v1.end()));
            int A = a - b, B = b - a;
            if (A > 0)
                v2.insert(A);
            if (B > 0)
                v1.insert(B);
        }
        f = !f;
    }
    if (v1.size())
        cout << "Tsondu" << endl;
    else if (v2.size())
        cout << "Tenzing" << endl;
    else
        cout << "Draw" << endl;
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