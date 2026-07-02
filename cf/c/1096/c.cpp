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

        vector<int> both, only2, only3, none;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x % 6 == 0)      both.push_back(x);
            else if (x % 2 == 0) only2.push_back(x);
            else if (x % 3 == 0) only3.push_back(x);
            else                 none.push_back(x);
        }

        for (int x : both)    cout << x << ' ';
        for (int x : only2) cout << x << ' ';
        for (int x : none)  cout << x << ' ';
        for (int x : only3) cout << x << ' ';

        cout << '\n';
    }

    return 0;
}