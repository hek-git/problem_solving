#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int weight[241], boat, num, cnt;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> dq;
    sort(people.begin(), people.end());
    for(auto p : people) dq.push_front(p);
    while(!dq.empty()){
        boat = limit;
        boat -= dq.front();
        dq.pop_front();
        if(!dq.empty() && dq.back() <= boat){
            dq.pop_back();
        }
        answer++;
    }

    return answer;
}