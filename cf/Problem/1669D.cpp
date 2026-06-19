#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void Solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    bool has_R = false;
    bool has_B = false;
    bool has_segment = false;
    
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == 'W') {
            if (has_segment) {
                if (!has_R || !has_B) {
                    cout << "NO\n";
                    return; 
                }
            }
            has_R = false;
            has_B = false;
            has_segment = false;
        } else {
            has_segment = true;
            if (s[i] == 'R') has_R = true;
            if (s[i] == 'B') has_B = true;
        }
    }
    cout << "YES\n";
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