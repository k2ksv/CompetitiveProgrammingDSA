#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x = 0;

    while(n--) {
        string s;
        cin >> s;

       // string::npos means "not found"
        if(s.find("++") != string::npos) 
            x++;   
        else
            x--;
    }

    cout << x << '\n';

    return 0;
}