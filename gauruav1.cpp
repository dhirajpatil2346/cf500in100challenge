#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
vector<int> possiblePathSum(int n, int m, vector<vector<int>> &grid, vector<int> &queries)
{
    int k = abs(grid[0][0]);

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (auto &val : v)
        for (auto &vali : val)
            cin >> vali;
    int q;
    cin >> q;
    vector<int> queries(q);
    for (auto &val : queries)
        cin >> val;
    return 0;
}