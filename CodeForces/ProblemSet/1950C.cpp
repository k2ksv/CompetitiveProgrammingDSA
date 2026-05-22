#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        
        string s;
        cin >> s;

        int hh = (s[0] - '0') * 10 + (s[1] - '0');
        string mm = s.substr(3, 2);

        string period;

        if(hh < 12){
            period = "AM";

            if (hh == 0){
                hh = 12;

            }

        }
        else {
            period = "PM";

            if (hh != 12){
                hh -= 12;
            }
        }
        if (hh<10){
            cout << '0';

        }
        cout << hh << ":" << mm << " " << period << '\n';

        
    }

    return 0;
}