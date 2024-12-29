#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    map<int, int> mp;
    mp[a]++, mp[b]++, mp[c]++, mp[d]++;

    if (mp.size() == 2)
    {
        auto it = mp.begin();

        int card1 = it->second;
        int card2 = (++it)->second;

        if ((card1 == 3 && card2 == 1) || (card1 == 2 && card2 == 2) || (card1 == 1 && card2 == 3))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
        cout << "No\n";

    return 0;
}