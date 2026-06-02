#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

void Solve() {
            ll n; cin >> n;
    
    vector<vector<ll>> adj(n + 1);
    for (ll i = 1; i < n; i++){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    
    vector <ll> f(n + 1, 0), sub(n + 1, 0);
    ll ans = 0;
    ll good = n * (n - 1) / 2;
    
    auto dfs = [&](auto self, ll u, ll d, ll par) -> void{
        f[d]++;
        sub[u] = 1;
        ll lca = 0;
        
        for (ll v : adj[u]) if (v != par){
            self(self, v, d + 1, u);
            lca += sub[v] * sub[u];
            sub[u] += sub[v]; 
        }
        
        ans -= 2 * lca * d;
        good -= sub[u] - 1; 
    };
    dfs(dfs, 1, 0, -1);
    
    vector <ll> g(n + 1, 0);
    for (ll i = n - 1; i >= 0; i--){
        g[i] = g[i + 1] + f[i];
    }
    
    
    for (ll i = 0; i < n; i++){
        ans += f[i] * g[i + 1] * i * 2;
        ans += (f[i] * (f[i] - 1) / 2) * i * 2;
    }
    ans -= good;
    
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef FILE_IO
(void)freopen("input.txt", "r", stdin);
(void)freopen("output.txt", "w", stdout);
#endif

    ll t;
    cin >> t;

    #ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
    #endif

    while (t--) {
        Solve();
    }

    #ifdef LOCAL
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    cerr << "Time: " << elapsed.count() << " ms\n";
    #endif

    return 0;
}