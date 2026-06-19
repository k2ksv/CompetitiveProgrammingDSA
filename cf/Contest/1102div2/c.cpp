#include <bits/stdc++.h>
using namespace std;

using ll  = long long;

/* debug */
#ifdef LOCAL
  #define dbg(x) cerr << #x << " = " << (x) << '\n'
  #define dbg2(x,y) cerr << #x << "=" << (x) << " " << #y << "=" << (y) << '\n'
#else
  #define dbg(x)
  #define dbg2(x,y)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto randint(ll l, ll r) { return uniform_int_distribution<ll>(l,r)(rng); }

const ll  INF = 2e18;
const int MOD = 1e9 + 7;

void Solve() {
    int n;
    cin >> n;
    
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<long long> ans(n);
    for (int empty_idx = 0; empty_idx < n; empty_idx++) {
        vector<long long> H(n);
        for (int j = 0; j < n; j++) {
            H[j] = h[(empty_idx + j) % n];
        }
        vector<long long> L(n, 0);
        long long max_left = 0;
        for (int i = 1; i < n; i++) {
            max_left = max(max_left, H[i - 1]);
            L[i] = max_left;
        }
        vector<long long> R(n, 0);
        long long max_right = 0;
        for (int i = n - 1; i >= 1; i--) {
            max_right = max(max_right, H[i]);
            R[i] = max_right;
        }
        long long total_volume = 0;
        for (int i = 1; i < n; i++) {
            total_volume += min(L[i], R[i]);
        }
        
        ans[empty_idx] = total_volume;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    (void)freopen("input.txt",  "r", stdin);
    (void)freopen("output.txt", "w", stdout);
#endif

#ifdef LOCAL
    auto _t0 = chrono::high_resolution_clock::now();
#endif

    int t = 1;
    cin >> t;
    while (t--) { 
        Solve();
    }

#ifdef LOCAL
    auto _t1 = chrono::high_resolution_clock::now();
    cerr << "\n[time] "
         << chrono::duration_cast<chrono::milliseconds>(_t1-_t0).count()
         << " ms\n";
#endif

    return 0;
}

/*
THINK DIFFERENTLY
*/