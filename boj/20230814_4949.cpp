#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s;

bool balanced(string& sentence){

    stack<char> s;
    char tmp;

    for(auto c : sentence){
        if(c == '(' || c == '[') s.push(c);
        if(c == ')'){
            if(!s.size() || s.top() != '(') return false;
            else s.pop();
        }
        if(c == ']'){
            if(!s.size() || s.top() != '[') return false;
            else s.pop();
        }
    }
    if(s.size()) return false;
    
    return true;
}

int main() {
    
    while(true){
        getline(cin, s);
        if(s.size() == 1 && s[0] == '.') break;
        
        if(balanced(s)) cout << "yes\n";
        else cout << "no\n";
    }
}