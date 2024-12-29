#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
bool solve(string s, string t, int k, int i, int j, vector<vector<vector<int>>> &dp)
{
    if (k < 0)
        return false;

    if (i == s.size() && j == t.size() && k >= 0)
        return true;

    if (i == s.size())
        return k >= (t.size() - j);

    if (j == t.size())
        return k >= (s.size() - i);

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    if (s[i] == t[j])
        return dp[i][j][k] = solve(s, t, k, i + 1, j + 1, dp);

    return dp[i][j][k] = solve(s, t, k - 1, i, j + 1, dp) ||
                         solve(s, t, k - 1, i + 1, j, dp) ||
                         solve(s, t, k - 1, i + 1, j + 1, dp);
}
*/

bool solve(string s, string t, int k)
{
    int n = s.size(), m = t.size();

    if (abs(n - m) > k)
        return false;

    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 1e9));
    dp[0][k] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 2 * k; j++)
        {
            int idxOfT = j + i - k;
            if (idxOfT < 0)
                continue;

            if (idxOfT > m)
                break;

            // delete from s
            if (i > 0 && j < 2 * k)
                dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + 1);

            // insert into s
            if (idxOfT > 0 && j > 0)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);

            // replace
            if (i > 0 && idxOfT > 0)
            {
                int add = (s[i - 1] == t[idxOfT - 1]) ? 0 : 1;
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + add);
            }
        }
    }

    return dp[n][k + m - n] <= k;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    string s, t;

    cin >> k >> s >> t;
    // vector<vector<vector<int>>> dp(s.size() + 1, vector<vector<int>>(t.size() + 1, vector<int>(k + 1, -1)));

    bool ans = solve(s, t, k);
    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}