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

        int a = n / 10;

        int b = n % 10;

        cout << a + b << '\n';
    }

    return 0;
}