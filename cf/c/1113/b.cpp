/**
 *    a LGM is just a NEWBIE who kept trying
 *                author: K2
 *        created: 01.08.2026 20:10:02
 **/

#include <bits/stdc++.h>
using namespace std;

//#define int long long
using ll  = long long;
#define f first
#define s second

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

template<class T> bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// Standard 4-directional movement (Up, Down, Left, Right)
// int dx[] = {-1, 1, 0, 0};
// int dy[] = {0, 0, -1, 1};

// 8-Directional movement (King's moves / surrounding cells)
// int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*
int x = INT_MIN    // Smallest 32-bit INTEGER (-2e9)
int x = INT_MAX    // Largest  32-bit INTEGER (2e9)
ll y = LLONG_MIN   // Smallest  64-bit LONG LONG (-9e18)
ll y = LLONG_MAX   // Largest  64-bit LONG LONG (9e18)
*/

/*
QUICK TRICKS:
- __lg(x) : Gets the highest set bit (floor(log2(x))) instantly in O(1).
- return void(cout << "NO\n"); : One-liner bail out for impossible cases.
- (1LL << i) : Calculates 2^i safely for long long (Bitmasking).
- (A + B - 1) / B : Math trick for Ceiling Division (ceil(A / B)) without floats!
*/

void Solve() {
    int n, m; cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];
    if(n < 2*m){
        cout << "NO\n"; return;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < m; i++) {
        if (a[i] > b[i] || a[n - m + i] < b[i]){
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";
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