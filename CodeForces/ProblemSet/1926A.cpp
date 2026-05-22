#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e18;
const int MOD = 1e9 + 7;

void Solve() {
    string s;
    cin >> s;
    int count1 = 0;
    int count2 = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A'){
            count1++;
        }else{
            count2++;
        }
    }
    if(count1 > count2){
        cout << "A" << '\n';

    }else{
        cout << "B" << '\n';
    }
}

int32_t main() {
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