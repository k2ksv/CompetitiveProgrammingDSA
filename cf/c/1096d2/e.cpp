#include <bits/stdc++.h>
using namespace std;

long long calc(vector<int>& a) {
    int n = a.size();
    long long stay = 0, total = 0;

    int mx = 0;

    for(int i = n-1; i >= 0; i--) {
        if(a[i] > mx) {
            stay += a[i] - mx;
        }
        mx = max(mx, a[i]);
        total += a[i];
    }

    return total - stay;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        long long ans = calc(a);

        // try removing 1 cube from each position
        for(int i = 0; i < n; i++) {
            if(a[i] > 0) {
                a[i]--;
                ans = max(ans, calc(a));
                a[i]++;
            }
        }

        cout << ans << '\n';
    }
}