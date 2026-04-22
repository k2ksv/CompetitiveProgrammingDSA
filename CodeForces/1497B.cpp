#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> rm(m, 0);
       
        for(int i=0; i<n; i++){
            int v;
            cin >> v;
            int rem = v % m;
            rm[rem]++;
        }

        int groups =0;
        if (rm[0]>0){
            groups++;
        }

        for (int r = 1; r <= m/2; r++){
            if (m-r == r){
                if (rm[r]>0){
                    groups++;

                }

            }
            else {
                int c1 = rm[r];
                int c2 = rm[m-r];

                if (c1 == 0 && c2 == 0) continue;

                groups ++;
                int diff = abs(c1-c2);
                if (diff > 0){
                    groups += diff-1;

                }

                



            }

        }



        cout << groups <<"\n";









      
       
    }

    return 0;
}

