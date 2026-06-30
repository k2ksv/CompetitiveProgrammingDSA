#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int N, X;
        cin >> N >> X;

        int k = (N + 5) / 6;   // ceil(N/6)
        cout << k * X << '\n';
    }

    return 0;
}