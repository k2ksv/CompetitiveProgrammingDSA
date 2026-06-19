#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void Solve() {
    int n; int k;
    cin >> n >> k;

    if (k%2==0 && n%2==1){
        cout<<"NO\n";return;
    }
    if (k%2 != n%2){
        if (n < 2* k)
        cout<<"NOn";
        else {
            cout<<"YES\n";
            for (int i=1; i<k; i++){
            cout<<2<<" ";
            n-=2;
            }
            cout<<n<<"\n";
        }
    }
    else {
        if (n<k)
        cout<<"NO\n";
        else {
            cout<<"YES\n";
            for (int i=1; i<k; i++){
                cout<<1<<" ";
                n--;
            }
            
            cout<<n<<"\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
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