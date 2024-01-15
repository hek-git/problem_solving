#include <string>
#include <vector>
#include <queue>

using namespace std;

// 우선순위 현황을 나타내는 배열
int priority[10];

int solution(vector<int> priorities, int location) {
    int answer = 0, flag = 0;
    queue<pair<int, int>> q;
    // 큐에 우선순위 추가 및 우선순위 현황 배열에 저장
    for(int i = 0; i < priorities.size(); i++) q.push(make_pair(priorities[i], i));
    for(int i = 0; i < priorities.size(); i++) priority[priorities[i]]++;
    
    while(true){
        pair<int, int> p = q.front();
        q.pop();
        // 더 높은 우선순위가 있는지 확인
        for(int i = p.first + 1; i < 10; i++){
            if(priority[i]) flag = 1;
        }

        // 더 높은 우선순위가 없다면 해당 우선 순위 삭제 및 순서 확인
        if(!flag){
            priority[p.first]--;
            answer++;
            if(p.second == location) return answer;
        } else q.push(p); // 더 높은 우선순위가 있다면 큐 뒤에 추가
        flag = 0;
    }

    return answer;
}