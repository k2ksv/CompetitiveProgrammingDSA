#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int l, a, b;
    cin >> l >> a >> b;

    int g = __gcd(l, b);

    int ans = l - 1 - ((l - 1 - a) % g);

    cout << ans << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}