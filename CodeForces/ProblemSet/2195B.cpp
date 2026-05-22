#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x : a) {
        cin >> x;
    }
    for(ll i = 1; i <= n; i++) {
        ll posOdd = i / (i & -i);
        ll valOdd = a[i - 1] / (a[i - 1] & -a[i - 1]);
        if(posOdd != valOdd) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}