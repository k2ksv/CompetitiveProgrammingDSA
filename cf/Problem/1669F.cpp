#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void Solve() {
    int n;
    cin >> n;
    
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    int left = 0;
    int right = n - 1;
    long long sum_alice = 0;
    long long sum_bob = 0;
    int max_candies = 0;
    while (left <= right) {
        if (sum_alice <= sum_bob) {
            sum_alice += w[left];
            left++;
        } else {
            sum_bob += w[right];
            right--;
        }
        if (sum_alice == sum_bob) {
            max_candies = max(max_candies, left + (n - 1 - right));
        }
    }
    cout << max_candies << "\n";
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
