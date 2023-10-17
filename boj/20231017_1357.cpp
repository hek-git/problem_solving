#include <iostream>
#include <string>

using namespace std;

string X, Y;
int ans;

string reverseNumber(string s){
    for(int i = 0; i < s.size()/2; i++){
        char tmp = s[i];
        s[i] = s[s.size() - i - 1];
        s[s.size() - i -1] = tmp;
    }
    return s;
}

int main() {
    cin >> X >> Y;
    cout << stoi(reverseNumber(to_string(stoi(reverseNumber(X)) + stoi(reverseNumber(Y)))));
}