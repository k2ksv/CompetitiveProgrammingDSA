
//TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {

        int n, m, k;
        cin >> n >> m >> k;
        vector<ll> robots(n);
        vector<ll> spikes(m);
        for(int i = 0; i < n; i++) {
            cin >> robots[i];
        }
        unordered_set<ll> spikeSet;
        for(int i = 0; i < m; i++) {
            cin >> spikes[i];
            spikeSet.insert(spikes[i]);
        }
        string s;
        cin >> s;
        unordered_set<ll> alive;
        for(int i = 0; i < n; i++) {
            alive.insert(robots[i]);
        }



        ll displacement = 0;

        for(int step = 0; step < k; step++) {

            if(s[step] == 'L') {
                displacement--;
            }
            else {
                displacement++;
            }
            vector<ll> dead;
            for(ll robot : alive) {
                ll currentPos = robot + displacement;
                if(spikeSet.count(currentPos)) {
                    dead.push_back(robot);
                }
            }

            for(int i = 0; i < dead.size(); i++) {
                alive.erase(dead[i]);
            }

            cout << alive.size() << " ";
        }

        cout << '\n';
    }

    return 0;
}