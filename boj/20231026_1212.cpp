#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

string s, tmp;
vector<string> word;
int flag;
int o[6] = {1, 1, 1, 1, 1, 1};
int ans;

string f(char n) {
    n = n - '0';
    string tmp;
    while(n){
        tmp.push_back((n%2)+'0');
        n/=2;
    }
    while(tmp.size() != 3){
        tmp.push_back('0');
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

int main() {
    cin >> s;
    if(s.size() == 1 && s[0]-'0' == 0) cout << 0;
    else for(int i = 0 ; i < s.size(); i++){
        string tmp = f(s[i]);
        if(i == 0) cout << to_string(stoi(tmp));
        else cout << tmp;
    }
    
}