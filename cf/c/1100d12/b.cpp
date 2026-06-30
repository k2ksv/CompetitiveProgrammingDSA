#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void Solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i< n;i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin>> b[i];
    long long sum_b = 0;
    long long max_a = 0;
    for (int i = 0; i< n; i++) {
        sum_b += max(a[i], b[i]);
        max_a = max(max_a, min(a[i], b[i]));
    }
    cout << sum_b+ max_a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    #ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
    #endif

    while (t--) {
        Solve();
    }

    #ifdef LOCAL
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    cerr << "Time: " << elapsed.count() << " ms\n";
    #endif

    return 0;
}