#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool validate(queue<char> q){
    stack<char> s;
    while(!q.empty()){
        if(q.front() == '[' || q.front() == '{' || q.front() == '('){
            s.push(q.front());
        } else if(q.front() == ']'){
            if(s.empty() || s.top() != '[') return false;
            else s.pop();
        } else if(q.front() == '}'){
            if(s.empty() || s.top() != '{') return false;
            else s.pop();
        } else if(q.front() == ')'){
            if(s.empty() || s.top() != '(') return false;
            else s.pop();
        }
        q.pop();
    }
    return s.empty();
}

int solution(string s) {
    int answer = 0;
    queue<char> q;
    for(int i = 0; i < s.size(); i++) q.push(s[i]);
    for(int i = 0; i < s.size(); i++){
        if(validate(q)) answer++;
        q.push(q.front());
        q.pop();
    }
    return answer;
}