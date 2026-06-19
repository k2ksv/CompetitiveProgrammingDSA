#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        
        vector<int> a(7);
        for ( int i = 0; i < 7; i++) cin >> a[i];
        sort(a.begin(), a.end());
        for (int i =0; i < 6; i++){
            a[i] = -a[i];
        }
        int sum = 0;
        for (int i =0; i < 7; i++) {
            sum = sum + a[i];
        }
        cout << sum << '\n';
        
    }
    

    return 0;
}