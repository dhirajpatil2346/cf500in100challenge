#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    priority_queue<LL> q;
    for (int i = 0; i < n; i++)
    {
        LL x;
        cin >> x;
        q.push(x);
    }
    bool alice = true;
    LL a = 0, b = 0;
    while (q.size())
    {
        LL t = q.top();
        q.pop();
        if (alice)
        {
            if (!(t & 1))
                a += t;
        }
        else
        {
            if (t & 1)
                b += t;
        }
        alice = !alice;
    }
    if (a == b)
    {
        cout << "Tie" << endl;
    }
    else if (a > b)
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