#include <bits/stdc++.h>
using namespace std;


pair<int, int> getMinMaxDigit(long long number) {
    int smallestDigit = 9;
    int largestDigit = 0;

    while (number > 0) {
        int digit = number % 10;

        if (digit < smallestDigit) {
            smallestDigit = digit;
        }

        if (digit > largestDigit) {
            largestDigit = digit;
        }

        number = number / 10;
    }

    return {smallestDigit, largestDigit};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long number, steps;
        cin >> number >> steps;

        for (int i = 1; i < steps; i++) {

         
            pair<int, int> result = getMinMaxDigit(number);

            int smallestDigit = result.first;
            int largestDigit = result.second;

            if (smallestDigit == 0) {
                break;
            }

            number = number + (long long)smallestDigit * largestDigit;
        }

        cout << number << "\n";
    }

    return 0;
}