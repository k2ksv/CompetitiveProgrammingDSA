#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long S = 0;       
    long long M = 0;      
    long long sum_M = 0;   
    long long K = 0;       
    long long max_C = 0;  
    for (int i = 0; i <n; ++i) {
        long long c;
        cin >> c;
        if (c == 1){
            S++;
        } else{
            M++;
            sum_M+= c;
            K += (c- 2) / 2;
            if (c > max_C) {
                max_C = c;
            }
        }
    }
    long long ans= 0;
    if (M == 0){
        ans =0;
    } else if(M == 1) {
        long long hosted = min(S, max_C / 2);
        ans = sum_M + hosted;
        if (ans < 3) {
            ans = 0;
        }
    } else {
        long long hosted = min(S, K);
        ans = sum_M + hosted;
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}