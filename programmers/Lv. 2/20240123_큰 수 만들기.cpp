#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    deque<char> dq;
    int cnt = 0;

    for (int i = 0; i < number.size(); i++) {
        while (!dq.empty() && dq.back() < number[i] && cnt != k) {
            cnt++;
            dq.pop_back();
        }
        dq.push_back(number[i]);
    }

    while(!dq.empty() && cnt != k){
        dq.pop_back();
        cnt++;
    }

    while (!dq.empty()) {
        answer.push_back(dq.front());
        dq.pop_front();
    }    
    return answer;
}