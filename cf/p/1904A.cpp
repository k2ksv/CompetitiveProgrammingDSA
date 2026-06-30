/**
*    a LGM is just a NEWBIE who kept trying
*                author: K2
*        created: 19.06.2026 12:25:14
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
int x = INT_MAX    //Largest Possible INTEGER
*/

void Solve() {
    int a, b;
    cin >> a >> b;
    int xK, yK, xQ, yQ;
    cin >> xK >> yK >> xQ >> yQ;
    int dx[] = {a, a, -a, -a, b, b, -b, -b};
    int dy[] = {b, -b, b, -b, a, -a, a, -a};
    set<pair<int, int>> KA;
    set<pair<int, int>> QA;
    for (int i = 0; i < 8; i++) {
        KA.insert({xK + dx[i], yK + dy[i]});
        QA.insert({xQ + dx[i], yQ + dy[i]});
    }
    int forks = 0;
    for (auto cell : KA) {
        if (QA.count(cell)) {
            forks++;
        }
    }
    cout << forks << "\n";
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