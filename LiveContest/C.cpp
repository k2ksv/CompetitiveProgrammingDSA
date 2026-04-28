#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        sort(a.begin(), a.end());

        int mex = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] >= mex) {
                mex++;
            }
        }

        cout << mex << "\n";
    }
}