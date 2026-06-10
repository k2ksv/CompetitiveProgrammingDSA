#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void Solve(){
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    int max_val =0;
    
    for (int i=0; i < n; i++){
        cin >>a[i];
        max_val=max(max_val, a[i]);
    }
    for(int i=0; i < n; i++){
        cin >> b[i];
        max_val = max(max_val, b[i]);
    }
    int low =1,high = max_val;
    int ans =1;
    auto check = [&](int x){
        int c2=0; 
        int c0=0; 
        bool last_was_0= false;
        for (int i = 0; i < n; i++) {
            int count_ones = (a[i] >= x) + (b[i] >= x);
            if (count_ones == 2) {
                c2++;
                last_was_0 =false; 
            } 
            else if(count_ones == 0){
                if (!last_was_0) {
                    c0++;
                    last_was_0 =true;
                }
            }
        }
        return c2 > c0;
    };
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)){
            ans = mid;       
            low = mid + 1;
        } else{
            high = mid - 1;  
        }
    }
    cout << ans << "\n";
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