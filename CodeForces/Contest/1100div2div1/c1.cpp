#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void Solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> ops;
    bool flipped = false;
    for (int i = n - 1; i >= 0; i--) {
        long long current_val = flipped ? -a[i] : a[i];
        if (current_val > 0) {
            ops.push_back(i + 1); 
            flipped = !flipped;  
        }
    }
    cout << ops.size() << "\n";
    for (int i = 0; i < ops.size(); i++) {
        cout << ops[i] << (i == ops.size() - 1 ? "" : " ");
    }
    cout << "\n";
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