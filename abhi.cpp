#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
string strArr(vector<int> &a, vector<int> &b)
{
    multiset<int> s;
    for (int i = 0; i < b.size(); i++)
        s.insert(b[i]);
    string ans = "";
    for (auto &val : a)
    {
        if (s.find(val) == s.end())
            continue;
        string h = to_string(val);
        ans += h;
        ans += ",";
        s.erase(s.find(val));
    }
    if (ans.size())
        ans.pop_back();
    if (ans.size())
        return ans;
    return "false";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> a(n1), b(n2);
    for (auto &val : a)
        cin >> val;
    for (auto &val : b)
        cin >> val;
    cout << strArr(a, b) << endl;
    return 0;
}