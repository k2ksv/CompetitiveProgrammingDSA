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

bool check(string s, string t){
    int n = s.length();
    int m = t.length();
    
    for (int i = 0; i < n; i++){
        if (i + m > n) break;
        
        bool good = true;
        for (int j = 0; j < m; j++){
            if (t[j] != s[i + j]) good = false;
        }
        
        if (good) return true;
    }
    return false;
}
 
void Solve() 
{
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    for (int i = 0; i <= 5; i++){
        if (check(s, t)){
            cout << i << "\n";
            return;
        }
        s = s + s;
    }
    cout << -1 << "\n";
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