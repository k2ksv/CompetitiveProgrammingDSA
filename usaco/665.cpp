#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k;
    if (!(cin >> m >> n >> k)) return 0;

    for (int i = 0; i < m; i++) {
        string original_row;
        cin >> original_row;
        
        string magnified_row = "";
        for (char c : original_row) {
            for (int j = 0; j < k; j++) {
                magnified_row += c;
            }
        }
        for (int j = 0; j < k; j++) {
            cout << magnified_row << "\n";
        }
    }

    return 0;
}