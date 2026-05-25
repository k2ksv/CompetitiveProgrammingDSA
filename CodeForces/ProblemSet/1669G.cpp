#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for (int c = 0; c < m; c++) {
        int lowest_empty = n - 1;
        for (int r = n - 1; r >= 0; r--) {
            if (grid[r][c] == 'o') {
                lowest_empty = r - 1;
            } 
            else if (grid[r][c] == '*') {
                swap(grid[r][c], grid[lowest_empty][c]);
                lowest_empty--; 
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << grid[i] << "\n";
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