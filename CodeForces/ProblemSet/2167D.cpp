#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(ll x = 2; ; x++) {
            bool ok = false;
            for(int i = 0; i < n; i++) {

                if(gcd(a[i], x) == 1) {

                    ok = true;
                    break;
                }
            }
            if(ok) {

                cout << x << '\n';
                break;
            }
        }
    }
    return 0;
}