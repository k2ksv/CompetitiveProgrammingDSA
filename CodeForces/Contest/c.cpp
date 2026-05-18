#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long S2 = 0, max_host = 0, singles = 0;
        int blocks_ge2 = 0;
        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;
            if(x >= 2){
                S2 += x;
                blocks_ge2++;
                max_host = max(max_host, x);
            } else {
                singles++;
            }
        }
        long long extra = 0;
        if(blocks_ge2 == 1){
            extra = min(max_host / 2, singles);
        } else if(blocks_ge2 >= 2){
            extra = min(max(0LL, max_host / 2 - 1), singles);
        }
        long long total = S2 + extra;
        cout << (total >= 3 ? total : 0LL) << "\n";
    }
    return 0;
}