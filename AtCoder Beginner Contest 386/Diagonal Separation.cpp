#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int, int>;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<pii, char>> arr(m);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;

        arr[i] = {{x, y}, c};
    }

    sort(arr.begin(), arr.end());
    bool flag = true;
    set<int> st;

    for (int i = 0; i < m; i++)
    {
        if (arr[i].second == 'W')
            st.insert(arr[i].first.second);
        else
        {
            int idx = arr[i].first.second;

            if (st.empty())
                continue;

            auto it = st.upper_bound(idx);
            if (it != st.begin())
                flag = false;
        }
    }

    cout << (flag ? "Yes" : "No") << endl;

    return 0;
}