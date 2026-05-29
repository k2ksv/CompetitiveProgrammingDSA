#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD = 1e9 + 7;
    
void Solve() {
    int n, q; cin >> n >> q;
    
    vector <int> a(n), b(n), c(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    c = a;
    
    for (int i = n - 1; i >= 0; i--){
        c[i] = max(c[i], b[i]);
        if (i < n - 1){
            c[i] = max(c[i], c[i + 1]);
        }
    }
                 
    vector <int> ps(n + 1);
    for (int i = 1; i <= n; i++){
        ps[i] = ps[i - 1] + c[i - 1];
    }
    
    while (q--){
        int l, r; cin >> l >> r;
        
        cout << (ps[r] - ps[l - 1]) << " \n"[q == 0];
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