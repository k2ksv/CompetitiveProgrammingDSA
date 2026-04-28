#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 676767677;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> dp(n, LLONG_MAX);

        for (int i = 0; i < n; i++) {
            int prod = 1;

            for (int j = i; j >= 0; j--) {
                
                if (j < i && a[j] > a[j + 1]) break;

                prod = (prod * a[j]) % MOD;

                if (j == 0)
                    dp[i] = min(dp[i], prod);
                else
                    dp[i] = min(dp[i], (dp[j - 1] + prod) % MOD);
            }
        }

        cout << dp[n - 1] % MOD << "\n";
    }
}