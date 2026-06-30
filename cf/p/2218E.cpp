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

        int xr = 0;   // XOR of all elements
        int mx = 0;   // maximum element

        for(int i = 0; i < n; i++) {

            int x;
            cin >> x;

            // build total XOR
            xr ^= x;

            // track maximum element
            mx = max(mx, x);
        }

        // EVEN length:
        // answer = XOR of all elements
        if(n % 2 == 0) {
            cout << xr << '\n';
        }

        // ODD length:
        // answer = maximum element
        else {
            cout << mx << '\n';
        }
    }

    return 0;
}