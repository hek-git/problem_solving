#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    queue<int> q;

    for(int i = 1; i <= order.size(); i++) q.push(i);
    for(int i = 0; i < order.size(); i++){
        while(!q.empty() && order[i] >= q.front()){
            s.push(q.front());
            q.pop();
        }
        if(!s.empty() && s.top() == order[i]){
                answer++;
                s.pop();
            } else break;
    }


    // // 번호 순서대로 큐에 push
    // for (int i = 1; i <= order.size(); i++) q.push(i);
    // // 배달해야하는 택배가 오기까지 스택에 삽입
    // for (int i = 0; i < order.size(); i++) {
    //     while (!q.empty() && order[i] > q.front()) {
    //         s.push(q.front());
    //         q.pop();
    //     }

    //     // 큐가 비어있으면 스택만 검사
    //     if (q.empty()) {
    //         if (s.empty())
    //             break;
    //         else if (s.top() == order[i]) {
    //             s.pop();
    //             answer++;
    //         } else break;
    //     } else { // 큐가 비어있지 않으면 스택, 큐 검사
    //         if (q.front() == order[i]) {
    //             answer++;
    //             q.pop();
    //         } else if (!s.empty() && s.top() == order[i]) {
    //             answer++;
    //             s.pop();
    //         } else
    //             break;
    //     }
    // }
    return answer;
}