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
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    ll ones_B = 0, zeros_B = 0;
    ll ones_A = 0, zeros_A = 0;
    ll ones_C = 0, zeros_C = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') ones_A++; else zeros_A++;
        if (b[i] == '1') ones_B++; else zeros_B++;
        char c = (a[i] == b[i]) ? '0' : '1';
        if (c == '1') ones_C++; else zeros_C++;
    }
    ll score_A = ones_A * zeros_A;
    ll score_B = ones_B * zeros_B;
    ll score_C = ones_C * zeros_C;
    ll len = (1LL << k) + 1;
    ll c_C = len / 3;
    ll c_A = c_C;
    ll c_B = c_C;
    if (k % 2 == 0) {
        c_A++;
        c_B++;
    }
    ll ans = c_A * score_A + c_B * score_B + c_C * score_C;
    cout << ans << "\n";
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