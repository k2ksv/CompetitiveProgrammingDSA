#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void Solve() {
    int n, s, x;
    cin >> n >> s >> x;
    
    int current_sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        current_sum += a; 
    }
    if (s >= current_sum && (s - current_sum) % x == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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