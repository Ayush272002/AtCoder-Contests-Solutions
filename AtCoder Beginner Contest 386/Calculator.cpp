#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0' && i + 1 < s.size() && s[i + 1] == '0')
            i++;

        count++;
    }

    cout << count << endl;
    return 0;
}