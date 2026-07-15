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
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt3 = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') cnt1++;
            else if(s[i] == '2') cnt2++;
            else if(s[i] == '3') cnt3++;
        }
        int keep = max(cnt1 + cnt3, cnt2);
        cout << s.size() - keep << '\n';
    }

    return 0;
}