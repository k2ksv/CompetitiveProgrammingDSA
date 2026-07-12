/**
*    a LGM is just a NEWBIE who kept trying
*                author: K2
*        created: 12.07.2026 20:13:11
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

ll pwr(ll base, ll exp){
    ll res = 1;
    base %= MOD;
    while (exp > 0){
        if (exp%2 == 1) res = (res*base) % MOD;
        base = (base*base) % MOD;
        exp /= 2;
    }return res;
}
void Solve() {
    int n; cin >> n;
    int c = 0; 
    vector<pair<int, int>> pn;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == -1){
            c++;
        }else{
            if(pn.empty() || pn.back().first != x){
                pn.push_back({x, 1});
            }else{
                pn.back().second++;
            }
        }
    }
    ll bw = 1; ll adj = 0;
    for(int i = 0; i < pn.size(); i++){
        bw = (bw * pwr(2, pn[i].second - 1))%MOD;
        if (i + 1 < pn.size() && pn[i+1].first == pn[i].first+1){
            adj++;
        }
    }
    ll x1 = (c>0)?pwr(2, c-1):1;
    ll x2 = (c>0)?pwr(2, c-1):0;
    ll ans = (adj * x2)%MOD;
    ans=(ans+x1)%MOD;
    ans=(ans*bw)%MOD;
    cout << ans << '\n';
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