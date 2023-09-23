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
    vector<bool> first(n, false), second(n, false);
    first.back() = true, second.back() = true;
    for (int i = n - 2; i >= 0; i--)
    {
        /*
            for x person
            if v[i] = 1
                make reverse of another's next
            else
              now i have choice
              make or of self next and reverse of another's next
        */
        if (v[i] == 1)
            first[i] = !second[i + 1], second[i] = !first[i + 1];
        else
            first[i] = first[i + 1] | (!second[i + 1]), second[i] = second[i + 1] | (!first[i + 1]);
    }
    if (first[0])
        cout << "First" << endl;
    else
        cout << "Second" << endl;
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