#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t, n;
string s;

int main() {
    cin >> t;
    for(int i = 0; i <t; i++){
        cin >> n >> s;
        string ans;
        n-=1;
        for(int j = 0; j<s.size(); j++){
            if(j == n) continue;
            else ans += s[j];
        }
        cout << ans << endl;
    }
}