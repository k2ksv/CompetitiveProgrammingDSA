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
    int n = 10;
    
    long long ans = 0;
    
    auto getScore = [&](int row, int col) {
        int up = row + 1;
        int down = 10 - row;
        
        int left = col + 1;
        int right = 10 - col;
        
        return min({left, right, up, down});
    };
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            
            if(ch == 'X') {
                int pt = getScore(i, j);
                ans += pt;
            }
        }
    }
    
    cout << ans << endl;
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