/**
*    a LGM is just a NEWBIE who kept trying
*                author: K2
*        created: 28.06.2026 20:28:42
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
    int n;
    long long c;
    cin >> n >> c;

    vector<int> a(n);
    long long sum_a = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum_a += a[i];
    }
    vector<int> b(n);
    long long sum_b = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum_b += b[i];
    }
    bool org = true;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            org = false;
            break;
        }
    }
    if (org) {
        cout << sum_a - sum_b << "\n";
        return;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    bool srt = true;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            srt = false;
            break;
        }
    }
    if (srt) {
        cout << sum_a - sum_b + c << "\n";
    } else {
        cout << -1 << "\n";
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