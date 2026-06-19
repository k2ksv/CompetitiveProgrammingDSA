/**
*    a LGM is just a NEWBIE who kept trying
*                author: K2
*        created: 19.06.2026 11:47:10
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
    int n, a, b;
    cin>>n>>a>>b;
    if (a+b<n-1)
    {
        cout<<"Yes\n";
    }
    else if (a==n && b==n)
    {
        cout<<"Yes\n";
    }
    else cout<<"No\n";
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