#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if ((a == b) && (b == c))
        cout << "Yes\n";
    else if (a + b == c)
        cout << "Yes\n";
    else if (a + c == b)
        cout << "Yes\n";
    else if (b + c == a)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}