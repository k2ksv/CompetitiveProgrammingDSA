#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long max_val = 0;
    long long D = 0;
    for (int i = 0; i < n; i++) {
        max_val = max(max_val, a[i]);
        D = max(D, max_val - a[i]);
    }
    if (D == 0) {
        cout << "Yes\n";
        return;
    }
    long long prev = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] >= prev) {
            prev = a[i];
        } else if (a[i] + D >= prev) {
            prev = a[i] + D;
        } else {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}