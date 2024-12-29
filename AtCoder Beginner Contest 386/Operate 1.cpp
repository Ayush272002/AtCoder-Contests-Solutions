#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve(string &s, string &t, int k)
{
    int n = s.size(), m = t.size();

    if (abs(n - m) <= 1)
    {
        if (n == m)
        {
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] != t[i])
                    count++;
            }

            if (count <= 1)
                return true;
            else
                return false;
        }
        else if (m == n + 1)
        {
            int i = 0, j = 0, count = 0;

            while (i < n && j < m)
            {
                if (s[i] != t[j])
                {
                    count++;
                    if (count > k)
                        return false;

                    j++;
                }
                else
                {
                    i++;
                    j++;
                }
            }

            return count + (m - j) <= k;
        }
        else if (n == m + 1)
        {
            int i = 0, j = 0, count = 0;

            while (i < n && j < m)
            {
                if (s[i] != t[j])
                {
                    count++;
                    if (count > k)
                        return false;

                    i++;
                }
                else
                {
                    i++;
                    j++;
                }
            }

            return count + (n - i) <= k;
        }
    }
    else
        return false;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    string s, t;

    cin >> k >> s >> t;

    bool ans = solve(s, t, k);

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}