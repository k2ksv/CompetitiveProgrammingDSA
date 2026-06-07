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
    vector<int> deg(n + 1, 0);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    
    string s;
    cin >> s;

    int L0 = 0, L1 = 0, L_q = 0, I_q = 0;
    bool is_root_unknown = (s[0] == '?');
    for(int i = 2; i <= n; i++) {
        if(deg[i] == 1) { 
            // It's a leaf
            if(s[i-1] == '0') L0++;
            else if(s[i-1] == '1') L1++;
            else L_q++;
        } else { 
            if(s[i-1] == '?') I_q++;
        }
    }
    int ans = 0;
    if (!is_root_unknown) {
        if (s[0] == '0') {
            ans = L1 + (L_q + 1) / 2;
        } else {
            ans = L0 + (L_q + 1) / 2;
        }
    } else {
        if (L0 == L1) {
            if (I_q % 2 == 1) {
                ans = L0 + (L_q + 1) / 2; 
            } else {
                ans = L0 + L_q / 2;     
            }
        } else {
            ans = max(L0, L1) + L_q / 2;
        }
    }

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