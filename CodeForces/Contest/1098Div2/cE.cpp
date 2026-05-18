#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll a;
ll ans;
int d1, d2;
void dfs(ll cur, int len, int target) {
    if(len == target) {
        ans = min(ans, abs(a - cur));
        return;
    }
    if(!(len == 0 && d1 == 0)) {
        dfs(cur * 10 + d1, len + 1, target);
    }
    if(d1 != d2) {
        if(!(len == 0 && d2 == 0)) {
            dfs(cur * 10 + d2, len + 1, target);
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> a >> n;
        cin >> d1 >> d2;
        ans = 1e18;
        int L = to_string(a).size();
        for(int len = max(1, L - 1); len <= L + 1; len++) {
            dfs(0, 0, len);
        }
        if(d1 == 0 || d2 == 0) {
            ans = min(ans, a);
        }
        cout << ans << '\n';
    }
    return 0;
}