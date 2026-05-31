#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int min_calls = 1e9; 
    for (int i = 0; i < n; i++) {
        int target_X = a[i];
        int L = 0; 
        int R = 0; 
        for (int j = 0; j < n; j++) {
            if (a[j] < target_X) {
                L++;
            } else if (a[j] > target_X) {
                R++;
            }
        }
        int current_calls = max(L, R);
        min_calls = min(min_calls, current_calls);
    }
    cout << min_calls << "\n";
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