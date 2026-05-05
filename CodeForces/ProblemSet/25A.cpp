#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int even = 0, odd = 0;

  
    for(int i = 0; i < 3; i++) {
        if(a[i] % 2 == 0) even++;
        else odd++;
    }

    bool majority_even = (even > odd);

 
    for(int i = 0; i < n; i++) {
        if(majority_even && a[i] % 2 != 0) {
            cout << i + 1 << '\n';
            break;
        }
        if(!majority_even && a[i] % 2 == 0) {
            cout << i + 1 << '\n';
            break;
        }
    }

    return 0;
}