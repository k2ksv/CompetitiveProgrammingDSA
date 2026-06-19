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

struct ArrayBlock {
    ll sum;
    int id;
    bool operator<(const ArrayBlock& other) const {
        return sum > other.sum;
    }
};

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<ArrayBlock> blocks(n);
    
    for (int i = 0; i < n; i++) {
        ll current_sum = 0;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            current_sum += a[i][j];
        }
        blocks[i] = {current_sum, i};
    }
    sort(blocks.begin(), blocks.end());
    ll total_score = 0;
    ll current_prefix_sum = 0;
    for (int i = 0; i < n; i++) {
        int original_idx = blocks[i].id;
        for (int j = 0; j < m; j++) {
            current_prefix_sum += a[original_idx][j];
            total_score += current_prefix_sum;
        }
    }
    cout << total_score << "\n";
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