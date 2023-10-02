#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
string ArrayChallenge(string strArr[], int arrLength)
{
    string main = strArr[0];
    string dict = strArr[1];
    map<string, int> m;
    int i = 0;
    int n = dict.length();
    while (i < n)
    {
        string curr = "";
        while (i < n && dict[i] != ',')
        {
            curr += dict[i];
            i++;
        }
        i++;
        m[curr]++;
    }
    i = 0;
    string z = "";
    for (i = 0; i < main.length() - 1; i++)
    {
        z += main[i];
        if (m.find(z) == m.end())
            continue;
        string nxt = "";
        for (int k = i + 1; k < main.length(); k++)
            nxt += main[k];
        if(m.find(nxt)==m.end()) continue;
        if (z == nxt)
        {
            if (m[z] >= 2)
            {
                string ans = z;
                ans += ",";
                ans += nxt;
                return ans;
            }
        }
        else
        {
            string ans = z;
            ans += ",";
            ans += nxt;
            return ans;
        }
    }
    return strArr[0];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string word;
    cin >> word;
    string dict;
    cin >> dict;
    string strArr[] = {word, dict};
    cout << ArrayChallenge(strArr, 2) << endl;
    return 0;
}