#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(vector<ll> &arr, ll k, ll curr, ll idx)
{
    if (k == 0)
        return curr;

    if (idx >= arr.size() || arr.size() - idx < k)
        return LLONG_MIN;

    // take
    ll take = solve(arr, k - 1, curr ^ arr[idx], idx + 1);

    // skip
    ll skip = solve(arr, k, curr, idx + 1);

    return max(take, skip);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    ll all_xor = 0;

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        all_xor ^= arr[i];
    }

    if (k > n / 2)
        cout << solve(arr, n - k, all_xor, 0) << endl;
    else
        cout << solve(arr, k, 0, 0) << endl;

    return 0;
}