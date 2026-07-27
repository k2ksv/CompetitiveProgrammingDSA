#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; 
    if(!(cin >> s)) return 0;
    sort(s.begin(), s.end());

    vector<string> per;

    do{
        per.push_back(s);
    }while(next_permutation(s.begin(), s.end()));

    cout << per.size() << "\n";

    for(auto &x: per) cout << x << "\n";

    return 0;
}