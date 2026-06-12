#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {

        string s;
        cin >> s;
        int n = s.size();
        vector<int> pref2(n + 1, 0);
        vector<int> suff13(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pref2[i + 1] = pref2[i];
            if(s[i] == '2') {
                pref2[i + 1]++;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            suff13[i] = suff13[i + 1];
            if(s[i] == '1' || s[i] == '3') {
                suff13[i]++;
            }
        }
        int keep = 0;
        for(int i = 0; i <= n; i++) {
            keep = max(keep, pref2[i] + suff13[i]);
        }
        cout << n - keep << '\n';
    }

    return 0;
}