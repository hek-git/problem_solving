#include <iostream>
#include <string>

using namespace std;

int ans = 10;
string s;
char prev;

int main() {
    cin >> s;
    for(int i = 1; i<s.size(); i++){
        if(s[i] == s[i-1]) ans += 5;
        else ans+=10;
    }
    cout << ans;
}
