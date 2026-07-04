#include <iostream>

using namespace std;

void Solve() {
    long long n; 
    cin >> n;
    
    cout << n; 
    
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
        cout << " " << n; 
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solve();

    return 0;
}