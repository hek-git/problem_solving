#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 문자열 -> 시간형식으로 변환
pair<int, int> time_manipulate(vector<string>& time) {
    vector<int> time1, time2;
    time1.push_back(stoi(time[0].substr(0, 2)));
    time1.push_back(stoi(time[0].substr(3, 2)));
    time2.push_back(stoi(time[1].substr(0, 2)));
    time2.push_back(stoi(time[1].substr(3, 2)) + 10);

    time2[0] = time2[0] + time2[1] / 60;
    time2[1] %= 60;

    return make_pair(time1[0] * 100 + time1[1], time2[0] * 100 + time2[1]);
}

// 라인 스위핑 풀이
// int solution(vector<vector<string>> book_time) {
//     int answer = 0, line = 0;
//     vector<pair<int, int>> time, p;
//     for (int i = 0; i < book_time.size(); i++) {
//         time.push_back(time_manipulate(book_time[i]));
//     }
//     for (int i = 0; i < time.size(); i++) {
//         p.push_back(make_pair(time[i].first, 1));
//         p.push_back(make_pair(time[i].second, -1));
//     }

//     sort(p.begin(), p.end());

//     for (int i = 0; i < p.size(); i++) {
//         line += p[i].second;
//         answer = (answer <= line) ? line : answer;
//     }

//     return answer;
// }

// 큐를 이용한 풀이
int solution(vector<vector<string>> book_time) {
    int answer = 0, line = 0;
    vector<pair<int, int>> time, p;
    queue<int> q;

    for (int i = 0; i < book_time.size(); i++) {
        time.push_back(time_manipulate(book_time[i]));
    }
    
    for (int i = 0; i < time.size(); i++) {
        p.push_back(make_pair(time[i].first, 1));
        p.push_back(make_pair(time[i].second, -1));
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < p.size(); i++) {
        if(p[i].second == 1){
            if(!q.empty() && q.front() <= p[i].first){
                q.pop();
            } else answer++;
        } else q.push(p[i].first);
    }
    return answer;
}