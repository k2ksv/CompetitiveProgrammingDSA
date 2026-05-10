#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {

        ll n, m, h;
        cin >> n >> m >> h;
        vector<int> a(n);
        for(auto &x : a) {
            cin >> x;
        }

        vector<pair<int,int>> q(m);
        for(auto &[idx, add] : q) {
            cin >> idx >> add;
            idx--; 
        }
        int prv = 0;

        for(int qq = 0; qq < m; qq++) {
            auto [idx, add] = q[qq];
            a[idx] += add;

            if(a[idx] > h) {
                for(int q2 = qq; q2 >= prv; q2--) {
                    auto [i2, x2] = q[q2];
                    a[i2] -= x2;
                }
                prv = qq + 1;
            }
        }

        for(auto x : a) {
            cout << x << " ";
        }

        cout << '\n';
    }

    return 0;
}