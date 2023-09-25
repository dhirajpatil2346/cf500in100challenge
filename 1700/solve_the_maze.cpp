#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
vector<pair<int, int>> vp = {
    {0, -1}, // left
    {0, 1},  // right
    {-1, 0}, // up
    {1, 0}   // down
};

bool isValid(int sr, int sc, vector<vector<bool>> &vis, vector<vector<char>> &v)
{
    int n = v.size(), m = v[0].size();
    if (sr < 0 || sc < 0 || sr >= n || sc >= m || vis[sr][sc] || v[sr][sc] == '#')
        return false;
    return true;
}
bool bad(int sr, int sc, vector<vector<bool>> &vis, vector<vector<char>> &v)
{
    if (v[sr][sc] == 'B')
        return false;
    if (vis[sr][sc])
        return true;
    vis[sr][sc] = true;
    for (auto &val : vp)
        if (isValid(sr + val.first, sc + val.second, vis, v))
        {
            bool g = bad(sr + val.first, sc + val.second, vis, v);
            if (!g)
            {
                if (v[sr][sc] == '.')
                {
                    v[sr][sc] = '#';
                    return true;
                }
            }
        }
    return true;
}

bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (auto &val : v)
        for (auto &valu : val)
            cin >> valu;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    if (!bad(n - 1, m - 1, vis, v))
        v.back().back() = '#';
    // for (auto val : vis)
    // {
    //     for (auto valu : val)
    //         cout << valu;
    //     cout << endl;
    // }
    // cout << endl;
    // for (auto &val : v)
    // {
    //     for (auto &valu : val)
    //         cout << valu;
    //     cout << endl;
    // }
    // cout << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vis[i][j] = false;
    if (v[n - 1][m - 1] != '#')
    {
        vis[n - 1][m - 1] = true;
    }
    queue<pair<int, int>> q;
    if (vis[n - 1][m - 1])
        q.push({n - 1, m - 1});
    while (q.size())
    {
        auto f = q.front();
        int sr = f.first, sc = f.second;
        q.pop();
        for (auto &val : vp)
        {
            if (isValid(sr + val.first, sc + val.second, vis, v))
            {
                vis[sr + val.first][sc + val.second] = true;
                q.push({sr + val.first, sc + val.second});
            }
        }
    }
    // for (auto val : vis)
    // {
    //     for (auto valu : val)
    //         cout << valu;
    //     cout << endl;
    // }
    // cout << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'G' && !vis[i][j])
                return false;
            if (v[i][j] == 'B' && vis[i][j])
                return false;
        }
    return true;
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
        if (solve())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        // cout << endl;
    }
    return 0;
}