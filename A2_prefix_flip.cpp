#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    string a, b;
    cin >> n >> a >> b;
    vector<int> ans;
    bool correct = true;
    // i for the straight and j for reversed
    // reversed means his bits also changed
    int l = 0, r = n - 1;
    for (int i = n - 1, j = 0; i >= 0; i--, j++)
    {
        bool change = false;
        if (correct)
        {
            // every bit is correct
            if (a[r] == b[i])
            {
                // no need to change
            }
            else
            {
                // now it's time to change
                // check if l'th bit is same to it or not
                // if it's same then first change that and then do it for currect
                if (a[l] == b[i])
                {
                    ans.push_back(1);
                    if (i != 0)
                        ans.push_back(i + 1);
                }
                else
                {
                    // not same so reversing can solve our problem
                    ans.push_back(i + 1);
                }
                change = true;
                correct = !correct;
            }
        }
        else
        {
            // now bits are swapped
            // every bit is reverse of it
            if (a[r] != b[i])
            {
                // no need to change
            }
            else
            {
                // now it's time to change
                // check if l'th bit is same to it or not
                // if it's same then first change that and then do it for currect
                if (a[l] != b[i])
                {
                    ans.push_back(1);
                    if (i != 0)
                        ans.push_back(i + 1);
                }
                else
                {
                    // not same so reversing can solve our problem
                    ans.push_back(i + 1);
                }
                change = true;
                correct = !correct;
            }
        }
        if (change)
        {
            // 0 4
            // by change i have used 0th
            // new range will be l+1,r but reverse

            // 4 0
            // now l--
            // swap
            if (l <= r)
                l++;
            else
                l--;
            swap(l, r);
        }
        else
        {
            // 0 4
            // r--
            // 4 0
            // r++
            if (l <= r)
                r--;
            else
                r++;
        }
        // cout << l << " " << r << " " << correct << endl;
    }
    cout << ans.size() << " ";
    for (auto &val : ans)
        cout << val << " ";
    cout << endl;
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
/*
5
01011
11100

1 -> 11011 -> 11011
5 -> 00100 -> 00100

2 -> 11100

01
10

1 -> 11 -> 11
2 -> 00 -> 00
1 -> 10 -> 10

10
0110011011
1000110100

1 -> 1110011011 -> 1110011011
10-> 0001100100 -> 0010011000
8 -> 1101100100 -> 1001101100
7 -> 0110010100 -> 0100110100
1 -> 1100110100 -> 1100110100
2 -> 0000110100 -> 0000110100
1-> 1000110100
*/