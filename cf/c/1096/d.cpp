#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(2*n);
        for (int i = 0; i < 2*n; i++) cin >> a[i];

        vector<vector<int>> pos(n);
        for (int i = 0; i < 2*n; i++) {
            pos[a[i]].push_back(i);
        }

        int L = 2*n, R = -1;
        int ans = 0;

        multiset<int> starts, ends;

        for (int x = 0; x < n; x++) {
            int l = pos[x][0];
            int r = pos[x][1];

            starts.insert(l);
            ends.insert(r);

            L = *starts.begin();
            R = *ends.rbegin();

            int length = R - L + 1;

            // Check if all pairs are inside
            if (length == 2 * (x + 1)) {
                ans = x + 1;
            }
        }

        cout << ans << '\n';
    }
}