/**
*    a LGM is just a NEWBIE who kept trying
*                author: K2
*        created: 07.07.2026 22:01:40
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
    int n; cin >> n;
    vector<int> p(n);
    for(auto& x : p) cin >> x;
    int left = 0;
    while (left < n - 2) {
        int mid = left + 1;
        while (mid < n - 1) {
            int right = mid + 1;
            while (right < n) {
                if (p[left] < p[mid] && p[mid] > p[right]) {
                    cout << "YES\n";
                    cout << left + 1 << " " << mid + 1 << " " << right + 1 << "\n";
                    return; 
                }
                right++;
            }
            mid++;
        }
        left++;
    }
    cout << "NO\n";
}
// void Solve() {
//     int n; cin >> n; 
//     vector<int> p(n);
//     for(auto& x : p) cin >> x;
//     int left = 0; int mid = 1; int right = 2;
//     while (right < n) {
//         if (p[left] < p[mid] && p[mid] > p[right]) {
//             cout << "YES\n";
//             cout << left + 1 << " " << mid + 1 << " " << right + 1 << "\n";
//             return; 
//         }
//         left++;
//         mid++;
//         right++;
//     }
//     cout << "NO\n";
// }

// void Solve() {
//     int n; cin >> n;
    
//     vector<int> p(n);
//     for(auto& x: p) cin >> x;
//     for (int i = 1; i < n - 1; i++) {
//         if (p[i - 1] < p[i] && p[i] > p[i + 1]) {
//             cout << "YES\n";
//             cout << i << " " << i + 1 << " " << i + 2 << "\n";
//             return; 
//         }
//     }
//     cout << "NO\n";
// }
// void Solve() {
//     int n; cin >> n;
//     vector<int> p(n);
//     for(auto& x: p) cin >> x;
//     for (int i = 0; i < n - 2; i++) {
//         for (int j = i + 1; j < n - 1; j++) {
//             for (int k = j + 1; k < n; k++) {
//                 if (p[i] < p[j] && p[j] > p[k]) {
//                     cout << "YES\n";
//                     cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
//                     return; 
//                 }
//             }
//         }
//     }
//     cout << "NO\n";
// }

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