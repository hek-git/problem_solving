#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

ll solution(int n, vector<int> works) {
    ll answer = 0;
    priority_queue<ll> pq;
    for(int i = 0; i< works.size(); i++){
        pq.push((ll)works[i]);
        answer += works[i];
    }
    if(answer <= n) return 0;
    answer = 0;
    for(int i = 0; i < n; i++){
        ll tmp = pq.top() - 1;
        pq.pop();
        pq.push(tmp);
    }
    while(!pq.empty()){
        answer += pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}