#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int mn = a[i], mx = a[i], g = 0;

            for (int j = i; j < min(n, i + 100); j++) {
                mn = min(mn, a[j]);
                mx = max(mx, a[j]);
                g = gcd(g, a[j]);

                if (j > i && (mx - mn == g)) ans++;
            }
        }

        cout << ans << '\n';
    }
}