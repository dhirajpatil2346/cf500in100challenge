#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<LL> org_array(n);
    if (n > 1)
        org_array[1] = 1;
    LL f = 10;
    for (LL i = 2; i < n; i++)
    {
        org_array[i] = (i * f) % mod;
        f = (f * (10ll)) % mod;
    }
    for (int i = 1; i < n; i++)
        org_array[i] = (org_array[i] + org_array[i - 1]) % mod;
    reverse(org_array.begin(), org_array.end());
    LL sum = 0;
    for (int i = 0; i < n; i++)
    {
        LL c = s[i] - '0';
        c = (c * org_array[i]);
        sum = (sum + c) % mod;
    }
    vector<LL> pow_array(n, 1);
    f = 10;
    for (int i = 1; i < n; i++)
    {
        pow_array[i] = f;
        f = (f * 10ll) % mod;
    }
    reverse(pow_array.begin(), pow_array.end());
    for (int i = 0; i < n; i++)
    {
        LL c = s[i] - '0';
        c = (c * pow_array[i]) % mod;
        LL ele = i;
        ele = (ele * (ele + 1ll)) / 2ll;
        ele = (ele * c) % mod;
        sum = (sum + ele) % mod;
    }
    cout << sum << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
/*
10 10
rem -> 7 7

*/