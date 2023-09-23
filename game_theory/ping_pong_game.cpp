#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int a, b;
    cin >> a >> b;
    int s1 = 0, s2 = 0;
    bool lastAlice = true;
    while (a || b)
    {
        // cout << a << " " << b << endl;
        bool alice = lastAlice;
        bool next = true;
        if (alice)
        {
            if (a == 0)
            {
                s2++;
                lastAlice = false;
                next = false;
            }
            else
                a--;
        }
        else
        {
            if (b == 0)
            {
                s1++;
                lastAlice = true;
                next = false;
            }
            else
                b--;
        }
        alice = !alice;
        if (!next)
            continue;
        while (next)
        {
            // i will move only if i'm bigger
            if (alice)
            {
                if (a == 0)
                {
                    lastAlice = false;
                    s2++;
                    next = false;
                }
                else if (b == 0)
                {
                    a--;
                }
                else
                {
                    next = false;
                    s2++;
                    lastAlice = false;
                }
            }
            else
            {
                if (b == 0)
                {
                    lastAlice = true;
                    s1++;
                    next = false;
                }
                else if (a == 0)
                {
                    b--;
                }
                else
                {
                    next = false;
                    s1++;
                    lastAlice = true;
                }
            }
            alice = !alice;
        }
    }
    cout << s1 << " " << s2 << endl;
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
        int a, b;
        cin >> a >> b;
        cout << a - 1 << " " << b << endl;
    }
    return 0;
}