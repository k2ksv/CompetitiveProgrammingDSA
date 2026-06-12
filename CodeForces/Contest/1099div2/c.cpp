#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> paths;
    paths.reserve(n * 65);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        int dist = 0;
        while (val > 2) {
            paths.push_back({val, dist});
            dist++;
            val = (val % 2 == 0) ? (val / 2) : (val + 1);
        }
        paths.push_back({val, dist});
        dist++;
        val = (val == 1) ? 2 : 1; 
        paths.push_back({val, dist});
    }
    sort(paths.begin(), paths.end());
    long long min_ops = 1e18; 
    int i = 0;
    int m = paths.size();
    while (i < m) {
        int current_val = paths[i].first;
        int count = 0;
        long long current_sum_dist = 0;
        while (i < m && paths[i].first == current_val) {
            count++;
            current_sum_dist += paths[i].second;
            i++;
        }
        if (count == n) {
            if (current_sum_dist < min_ops) {
                min_ops = current_sum_dist;
            }
        }
    }
    cout << min_ops << "\n";
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