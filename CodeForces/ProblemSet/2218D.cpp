#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        vector<long long> b(n + 1);

        // odd numbers: 1,3,5,7,...
        for(int i = 0; i <= n; i++) {
            b[i] = 2LL * i + 1;
        }

        // a[i] = b[i] * b[i+1]
        for(int i = 0; i < n; i++) {
            cout << b[i] * b[i + 1] << " ";
        }

        cout << '\n';
    }

    return 0;
}