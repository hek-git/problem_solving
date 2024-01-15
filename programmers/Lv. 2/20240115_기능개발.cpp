#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> function;
    queue<int> function_time;

    // 각 기능과 시간 큐로 옮기기
    for (int i = 0; i < progresses.size(); i++) {
        function.push(progresses[i]);
        function_time.push(speeds[i]);
    }

    while (!function.empty()) {
        int cnt = 0;
        // 각 기능의 진도 업데이트
        for (int i = 0; i < function.size(); i++) {
            function.front() += function_time.front();

            function.push(function.front());
            function.pop();

            function_time.push(function_time.front());
            function_time.pop();
        }
        // 가장 앞에 있는 기능의 진도 현황 확인 후 불가능 할 때까지 배포 진행
        while (!function.empty() && function.front() >= 100) {
            function.pop();
            function_time.pop();
            cnt++;
        }
        // 작업된 개수가 1개 이상 있다면 추가
        if (cnt) answer.push_back(cnt);
    }
    return answer;
}