#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> is_palindrome(string& s) {
    int lo = 0, hi = s.size() - 1;
    vector<int> a;
    while (lo < hi) {
        if (s[lo] != s[hi]) {
            a.push_back(lo);
            a.push_back(hi);
        }
        lo++, hi--;
    }
    return a;
}

int main() {
    int T, ans;
    string s;
    vector<int> num;
    cin >> T;
    for (int i = 0; i < T; i++) {
        ans=0;
        cin >> s;
        num = is_palindrome(s);
        if (!num.empty()) {
            string s1 = s, s2 = s;
            ans = 2;
            s1.erase(num[0], 1);
            s2.erase(num[1], 1);
            if (is_palindrome(s1).empty() || is_palindrome(s2).empty()) ans = 1;
        }
        cout << ans << endl;
    }
}