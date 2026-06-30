#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_map<string, int> c;

    while(n--) {
        string s;
        cin >> s;

        if(c[s] == 0) {
            cout << "OK\n";
            c[s] = 1;
        } else {
            string new_name = s + to_string(c[s]);
            cout << new_name << '\n';
            c[s]++;
            c[new_name] = 1;
        }
    }

    return 0;
}