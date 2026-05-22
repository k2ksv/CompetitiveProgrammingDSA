#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e18;
const int MOD = 1e9 + 7;

void Solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a < b && b < c) {
        cout << "STAIR\n";
    }
    else if (a < b && b > c) {
        cout << "PEAK\n";
    }
    else {
        cout << "NONE\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
    #endif

    int t;
    cin >> t;

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
};

    while (t--) {
        
        int a, b, c;
        cin >> a >> b >> c;

        if(a<b && b < c){
            cout << "STAIR" << '\n';
        }else if(a<b && b>c){
            cout << "PEAK" << '\n';
        }else{
            cout << "NONE" << '\n';
        }
        
    }

    return 0;
}