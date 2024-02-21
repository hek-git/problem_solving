#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

// 두개의 pq를 이용한 풀이
vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0), tmp;
    priority_queue<int> min_pq, max_pq;
    int cnt = 0;
    set<int> s;
    for (int i = 0; i < operations.size(); i++) {
        string num_s;
        int num;
        for (int j = 2; j <= operations[i].size(); j++) num_s.push_back(operations[i][j]);
        num = stoi(num_s);
        if (operations[i][0] == 'I') {
            cnt++;
            min_pq.push(-1 * num);
            max_pq.push(num);
        } else if (operations[i][0] == 'D') {
            if (cnt == 0) {
                while (!max_pq.empty()) max_pq.pop();
                while (!min_pq.empty()) min_pq.pop();
            } else {
                cnt--;
                if (operations[i][2] == '-')
                    min_pq.pop();
                else
                    max_pq.pop();
            }
        }
    }
    while (!min_pq.empty()) {
        s.insert(-1 * min_pq.top());
        min_pq.pop();
    }
    while(!max_pq.empty()){
        if(s.find(max_pq.top()) != s.end()) tmp.push_back(max_pq.top());
        s.erase(max_pq.top());
        max_pq.pop();
    }
    sort(tmp.begin(), tmp.end());
    if(tmp.empty()) return answer;
    else{
        answer[0] = tmp.back();
        answer[1] = tmp[0];
    }
    return answer;
}