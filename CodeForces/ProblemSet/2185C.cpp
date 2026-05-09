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

        vector<int> a(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int best = 1;
        int cur = 1;

        for(int i = 1; i < n; i++) {

            if(a[i] == a[i-1]) continue;

            if(a[i] == a[i-1] + 1) {
                cur++;
            }

            else {
                cur = 1;
            }

            best = max(best, cur);
        }

        cout << best << '\n';
    }

    return 0;
}