#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void Solve() {
    int n, m;
    cin >> n >> m;
    
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int min_diff = 1e9; 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            
            int current_diff = 0;
            int len = s[i].length();
            for (int k = 0; k < len; k++) {
                current_diff += abs(s[i][k] - s[j][k]);
            }
            
            min_diff = min(min_diff, current_diff);
        }
    }

    cout << min_diff << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
(void)freopen("input.txt", "r", stdin);
(void)freopen("output.txt", "w", stdout);
#endif

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