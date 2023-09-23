#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    string s;
    cin >> s;
    bool alice = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (alice)
        {
            if (s[i] == 'a')
                s[i] = 'b';
            else
                s[i] = 'a';
        }
        else
        {
            if (s[i] == 'z')
                s[i] = 'y';
            else
                s[i] = 'z';
        }
        alice = !alice;
    }
    cout << s << endl;
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