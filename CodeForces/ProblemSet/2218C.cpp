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

    int big = 3 * n;

    for(int i = 1; i <= n; i++) {

        // small element
        cout << i << " ";

        // median element
        cout << big - 1 << " ";

        // large element
        cout << big << " ";

        // move to next largest pair
        big -= 2; //big = big - 2
    }

    cout << '\n';
}

return 0;
}