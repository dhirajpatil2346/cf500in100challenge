#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
map<pair<char, char>, int> m;
void sieve()
{
    for (int i = 0; i < 26; i++)
        for (int j = i; j < 26; j++)
        {
            // go from i to j // forw
            // abs diff
            // go from i to j back
            // i to move upto 0 + now 26 - j
            int curr = abs(i - j);
            curr = min(curr, i + 26 - j);
            m[{'a' + i, 'a' + j}] = curr;
            m[{'a' + j, 'a' + i}] = curr;
        }
}

void solve()
{
    sieve();
    string s;
    int n, c;
    cin >> n >> c >> s;
    c--;
    int ans = 1e9;
    // traverse to right and make circle
    {
        int curr = 0;
        string z = s;
        int posmoves = 0;
        int charmoves = 0;
        int zc = c;
        while (posmoves < s.length())
        {
            bool change = false;
            // n - i - 1
            cout << z[zc] << " " << z[n - zc - 1] << endl;
            if (z[zc] != z[n - zc - 1])
            {
                charmoves += m[{z[zc], z[n - zc - 1]}];
                z[zc] = z[n - zc - 1];
                change = true;
            }
            if (change)
            {
                curr = posmoves + charmoves;
            }
            posmoves++;
            zc++;
            zc %= s.length();
        }
        cout << curr << endl;
        ans = min(curr, ans);
    }

    // traverse from left and make circle
    {
        int curr = 0;
        string z = s;
        int posmoves = 0;
        int charmoves = 0;
        int zc = c;
        while (posmoves < s.length())
        {
            bool change = false;
            // n - i - 1
            if (z[zc] != z[n - zc - 1])
            {
                charmoves += m[{z[zc], z[n - zc - 1]}];
                z[zc] = z[n - zc - 1];
                change = true;
            }
            if (change)
            {
                curr = posmoves + charmoves;
            }
            posmoves++;
            zc--;
            zc += s.length();
            zc %= s.length();
        }
        ans = min(curr, ans);
        cout << curr << endl;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}