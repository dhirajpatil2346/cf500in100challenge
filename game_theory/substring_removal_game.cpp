#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    string s;
    cin >> s;
    vector<int> v;
    int i = 0, n = s.length();
    while (i < s.length())
    {
        while (i < n && s[i] == '0')
            i++;
        int c = 0;
        while (i < n && s[i] == '1')
            i++, c++;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    int A = 0;
    for(int i = v.size()-1 ; i >=0 ; i-=2)
        A+=v[i];
        cout<<A<<endl;
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