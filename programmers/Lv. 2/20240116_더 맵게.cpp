#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, f1, f2;
    priority_queue<int> pq;
    for(int i = 0; i < scoville.size(); i++) pq.push(-scoville[i]);
    while(!pq.empty()){
        if(-pq.top() >= K) break;
        else if(pq.size() == 1) return -1;
        f1 = -pq.top();
        pq.pop();
        f2 = -pq.top();
        pq.pop();
        f1 += f2 * 2;
        pq.push(-f1);
        answer++;
    }
    return answer;
}