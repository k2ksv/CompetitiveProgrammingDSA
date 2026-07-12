/**
*    a LGM is just a NEWBIE who kept trying
*                author: K2
*        created: 06.07.2026 20:00:22
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
    string a, b; cin >> a >> b;
    int n = a.length(), m = b.length();

    vector<int> p(n + 1, 0), q(m + 1, 0);
    for (int i = 0; i < n; i++) p[i+1] = (p[i] + a[i] - '0') % 10;
    for (int i = 0; i < m; i++) q[i+1] = (q[i] + b[i] - '0') % 10;

    if (p[n] != q[m]) return void(cout << "-1\n");

    vector<int> dp(m, 0);
    for (int i = 1; i < n; i++) {
        int prev = 0;
        for (int j = 1; j < m; j++) {
            int temp = dp[j];
            dp[j] = (p[i] == q[j]) ? prev+1 : max(dp[j], dp[j-1]);
            prev = temp;
        }
    }
    cout << dp[m-1] + 1 << "\n";
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