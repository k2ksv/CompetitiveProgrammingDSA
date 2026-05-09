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
        vector<int> array(n);

        for (int i =0; i < n; i++){
            cin >> array[i];
        }

        sort(array.begin(), array.end());

        int sum = array[n-1]*n;

        cout << sum << '\n';

    }

    return 0;
}