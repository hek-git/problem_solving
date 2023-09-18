#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t, n;
string s;
vector<string> number;

bool cmp(string& a, string& b){
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) return false; 
    }
    return true;
}

void solve(vector<string>& number) {
    for (int i = 0; i < number.size() - 1; i++) {
        if(number[i].size() <= number[i+1].size() && cmp(number[i], number[i+1])){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        number.clear();
        for (int j = 0; j < n; j++) {
            cin >> s;
            number.push_back(s);
        }
        sort(number.begin(), number.end());
        solve(number);
    }
}