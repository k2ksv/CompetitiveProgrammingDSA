/**
*    a LGM is just a NEWBIE who kept trying
*                author: K2
*        created: 30.06.2026 21:08:39
**/

#include <bits/stdc++.h>
using namespace std;

//#define int long long
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

// Standard 4-directional movement (Up, Down, Left, Right)
// int dx[] = {-1, 1, 0, 0};
// int dy[] = {0, 0, -1, 1};

// 8-Directional movement (King's moves / surrounding cells)
// int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*
int x = INT_MIN    //Smallest Possible INTEGER
int x = INT_MAX    //Largest Possible INTEGER
*/

void Solve() {
    int n; cin >> n;
    vector<ll> a(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<ll> b(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    ll dd = 0;
    ll nn = 0;
    bool can = true;
    for (int i = 1; i <= n; i++) {
        ll Ai = a[i] + a[i-1];
        ll Bi = b[i] + b[i-1];
        ll Di = Bi - Ai;
        if (i % 2 != 0) {
            dd += Di;
            if (dd < 0) {
                can = false;
                break;
            }
        } else {
            nn += Di;
            if (nn < 0) {
                can = false;
                break;
            }
        }
    }
    if (can) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    } 
}

//int32_t main() {
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
ALWAYS TRY TO FIND MATHEMATICAL EQUATIONS
THINK DIFFERENTLY
DON'T GET STUCK ON SINGLE APPROACH
*/