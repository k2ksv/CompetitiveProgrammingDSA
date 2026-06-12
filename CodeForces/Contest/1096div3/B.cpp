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

        string s;
        cin >> s;

        int first = 0, second = 0;

        for (char c : s) {
            if (c == '(') first++;
            else second++;
        }

        if (first == second)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';


    }
}