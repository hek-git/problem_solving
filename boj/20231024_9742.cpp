#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s, tmp;
int n, cnt, flag, fact[11], check[11];

void solve(){
    if(tmp.size() == s.size() && ++cnt == n){
        cout << s << " " << n << " = " << tmp << endl;
        flag = 1;
        return;
    }
    for(int i = 0; i < s.size(); i++){
        if(!flag && !check[i]){
            check[i] = 1;
            tmp.push_back(s[i]);
            solve();
            tmp.pop_back();
            check[i] = 0;
        }
    }
}

int main() {
    fact[1] = 1;
    for(int i = 2; i < 11; i++){
        fact[i] = fact[i-1] * i;
    }

    while(cin >> s >> n){
        if(fact[s.size()] < n){
            cout << s << " " << n << " = " << "No permutation\n";
            continue;
        }
        solve();
        flag = cnt = 0;
    }
}