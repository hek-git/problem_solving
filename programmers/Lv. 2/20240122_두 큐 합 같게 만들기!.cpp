#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    ll answer = 0, sum = 0, sum1 = 0, sum2 = 0;
    queue<int> q1, q2;
    for(int i = 0; i < queue1.size(); i++){
        sum1 += (ll)queue1[i];
        q1.push((ll)queue1[i]);

        sum2 += (ll)queue2[i];
        q2.push((ll)queue2[i]);
    }
    sum = sum1 + sum2;
    if(sum % 2) return -1;
    while((!q1.empty() && !q2.empty()) && answer <= (queue1.size() * 4)){
        if(sum1 == sum2) break;
        answer++;
        if(sum1 < sum2){
            q1.push(q2.front());
            sum2 -= (ll)q2.front();
            sum1 += (ll)q2.front();
            q2.pop();
        } else{
            q2.push(q1.front());
            sum1 -= (ll)q1.front();
            sum2 += (ll)q1.front();
            q1.pop();
        }
    }
    if(sum1 != sum2) return -1;
    return answer;

    // 투 포인터 풀이
    // int answer = 0, lo = 0, hi = queue1.size(), sum = 0, total_sum = 0;

    // for(int i = 0; i < queue2.size(); i++){
    //     queue1.push_back(queue2[i]);
    //     sum += queue1[i];
    //     total_sum += queue1[i] + queue2[i];
    // }
    // if(total_sum % 2) return -1;

    // while(hi < queue1.size() && lo < queue1.size()){
    //     if(sum == total_sum / 2) return answer;
    //     if(sum < (total_sum / 2) && hi < queue1.size()) sum += queue1[(hi++)];
    //     else sum -= queue1[(lo++)];
    //     answer++;
    // }
    // return -1;
}