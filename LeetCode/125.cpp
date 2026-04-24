#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }
};

int main() {
    string s;
    getline(cin, s);   // important: takes full line (with spaces)

    Solution obj;
    if (obj.isPalindrome(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}