#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fast ios::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(int i=a;i<b;i++)

// ==================== CONSTANTS ====================
const ll INF = 1e18;
const int MOD = 1e9 + 7;

// ==================== ORDERED SET ====================
template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

// ==================== DEBUG ====================
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif

// ==================== MATH ====================
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll mod_add(ll a, ll b) { return (a + b) % MOD; }
ll mod_sub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return (a * b) % MOD; }

ll mod_pow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = mod_mul(res, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return res;
}

ll mod_inv(ll a) { return mod_pow(a, MOD - 2); }

// ==================== COMBINATORICS ====================
const int MAXN = 2e5+5;
ll fact[MAXN], invfact[MAXN];

void init_fact(int n = MAXN) {
    fact[0] = 1;
    for(int i=1;i<n;i++) fact[i] = mod_mul(fact[i-1], i);
    invfact[n-1] = mod_inv(fact[n-1]);
    for(int i=n-2;i>=0;i--) invfact[i] = mod_mul(invfact[i+1], i+1);
}

ll nCr(ll n, ll r) {
    if(r<0 || r>n) return 0;
    return mod_mul(fact[n], mod_mul(invfact[r], invfact[n-r]));
}

// ==================== SIEVE ====================
vector<int> sieve(int n) {
    vector<bool> prime(n+1, true);
    vector<int> res;
    prime[0]=prime[1]=false;
    for(int i=2;i<=n;i++){
        if(prime[i]){
            res.pb(i);
            for(int j=i*2;j<=n;j+=i)
                prime[j]=false;
        }
    }
    return res;
}

// ==================== DSU ====================
struct DSU {
    vector<int> p, sz;
    DSU(int n){
        p.resize(n); sz.assign(n,1);
        iota(all(p),0);
    }
    int find(int x){
        return p[x]==x?x:p[x]=find(p[x]);
    }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a!=b){
            if(sz[a]<sz[b]) swap(a,b);
            p[b]=a;
            sz[a]+=sz[b];
        }
    }
};

// ==================== BIT ====================
struct BIT {
    int n;
    vector<ll> bit;
    BIT(int n):n(n),bit(n+1,0){}
    void update(int i,ll val){
        for(;i<=n;i+=i&-i) bit[i]+=val;
    }
    ll query(int i){
        ll sum=0;
        for(;i>0;i-=i&-i) sum+=bit[i];
        return sum;
    }
};

// ==================== SEGMENT TREE ====================
struct SegTree {
    int n;
    vector<ll> t;
    SegTree(int n):n(n),t(4*n,0){}
    void update(int v,int tl,int tr,int pos,ll val){
        if(tl==tr){ t[v]=val; return;}
        int tm=(tl+tr)/2;
        if(pos<=tm) update(v*2,tl,tm,pos,val);
        else update(v*2+1,tm+1,tr,pos,val);
        t[v]=t[v*2]+t[v*2+1];
    }
    ll query(int v,int tl,int tr,int l,int r){
        if(l>r) return 0;
        if(l==tl && r==tr) return t[v];
        int tm=(tl+tr)/2;
        return query(v*2,tl,tm,l,min(r,tm)) +
               query(v*2+1,tm+1,tr,max(l,tm+1),r);
    }
};

// ==================== GRID ====================
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// ==================== SOLVE ====================
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans++;
        if(s[i] == 'L') break;

        
    }
    cout << ans << "\n";
    
}

// ==================== MAIN ====================
int main(){
    fast;
    int t=1;
    cin>>t;
    auto start = high_resolution_clock::now();
    while(t--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
#ifndef ONLINE_JUDGE
    cerr << "\nTime: " << duration.count() << " ms\n";
#endif
    return 0;
}