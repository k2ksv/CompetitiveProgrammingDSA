#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

void Solve() {
    ll n;
    ll m; 
    cin >> n >> m;
    
    vector <ll> a(n);
    vector <ll> b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll kmax = min(n, m);
    kmax = min(kmax, (n + m) / 3);
    
    vector <ll> c, d; 
    for (ll i = 0; i < n - 1 - i; i++){
        c.push_back(a[n - 1 - i] - a[i]);
    }
    for (ll i = 0; i < m - 1 - i; i++){
        d.push_back(b[m - 1 - i] - b[i]);
    }
    multiset <ll> a1, a2;
    multiset <ll> b1, b2;
    for (auto x : c){
        a2.insert(x);
    }
    for (auto x : d){
        b2.insert(x);
    }
    
    cout << kmax << "\n";
    ll ans = 0;
    
    for (ll i = 1; i <= kmax; i++){
        ll ca = n - i;
        ll cb = m - i;
        
        if (a1.size() > ca){
            ll x = *a1.begin();
            a1.erase(a1.find(x));
            ans -= x;
            a2.insert(x);
        }
        if (b1.size() > cb){
            ll x = *b1.begin();
            b1.erase(b1.find(x));
            ans -= x;
            b2.insert(x);
        }
        ll should = i;
        while (a1.size() + b1.size() < should){
            ll va = 0, vb = 0;
            if (a1.size() < ca && a2.size() > 0){
                va = *(--a2.end());
            }
            if (b1.size() < cb && b2.size() > 0){
                vb = *(--b2.end());
            }
            if (va > vb){
                a2.erase(a2.find(va));
                ans += va;
                a1.insert(va);
            } else {
                b2.erase(b2.find(vb));
                ans += vb;
                b1.insert(vb);
            }
        }
        
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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