/**
*    a LGM is just a NEWBIE who kept trying
*                author: K2
*        created: 14.06.2026 20:21:55
**/

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

// 4-Directional movement (Up, Right, Down, Left)
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

// 8-Directional movement (Including diagonals)
const int ddx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int ddy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*
int x = INT_MIN    //Smallest Possible INTEGER
*/

void Solve() {
    int n; cin >> n;
    vector <int> a(n);
    for (auto &x : a) cin >> x;
    vector <int> b;
    b.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i - 1] != 1)
        b.push_back(1);
        b.push_back(a[i]);
    }
    cout << b.size() << "\n";
    for (auto x : b) cout << x << " ";
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
DON'T GET STUCK ON SINGLE APPROACH
JSUT TRY
*/