#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    long long max_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            long long current_sum = a[i][j];
            int r = i - 1;
            int c = j - 1;
            while (r >= 0 && c >= 0) {
                current_sum += a[r][c];
                r--; c--; 
            }
            r = i - 1;
            c = j + 1;
            while (r >= 0 && c < m) {
                current_sum += a[r][c];
                r--; c++;
            }
            r = i + 1;
            c = j - 1;
            while (r < n && c >= 0) {
                current_sum += a[r][c];
                r++; c--;
            }
            r = i + 1;
            c = j + 1;
            while (r < n && c < m) {
                current_sum += a[r][c];
                r++; c++;
            }
            max_sum = max(max_sum, current_sum);
        }
    }
    cout << max_sum << "\n";

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