#include <iostream>

using namespace std;

void Solve() {
    long long n;
    cin >> n;

    long long expected_sum = n * (n + 1) / 2;
    long long actual_sum = 0;

    for (int i = 0; i < n - 1; i++) {
        long long current_number;
        cin >> current_number;
        actual_sum += current_number;
    }

    cout << expected_sum - actual_sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solve();

    return 0;
}