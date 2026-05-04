#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int>& a) {
    vector<int> dp;
    for (int x : a) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    return dp.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> c = b;
        c.insert(c.end(), b.begin(), b.end()); 

        int ans = 0;

        for (int start = 0; start < n; start++) {
            vector<int> temp;
            for (int i = start; i < start + n; i++) {
                temp.push_back(c[i]);
            }
            ans = max(ans, LIS(temp));
        }

        cout << ans << '\n';
    }
}