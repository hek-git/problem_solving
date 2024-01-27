#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// 이분 탐색 풀이
// bool validation(int n, int& k, int& idx, vector<int>& enemy) {
//     if (k > idx) return true;
//     priority_queue<int> pq;
//     for (int i = 0; i <= idx; i++) pq.push(enemy[i]);
//     for (int i = 0; i < k; i++) pq.pop();
//     while (!pq.empty()) {
//         n -= pq.top();
//         if (n < 0) return false;
//         pq.pop();
//     }
//     return true;
// }

// int solution(int n, int k, vector<int> enemy) {
//     int answer = 0, lo = 0, hi = enemy.size() - 1, mid;
//     if (k >= enemy.size()) return enemy.size();
//     while (lo <= hi) {
//         mid = (lo + hi) / 2;
//         if (validation(n, k, mid, enemy)) {
//             lo = mid + 1;
//             answer = mid;
//         } else
//             hi = mid - 1;
//     }
//     return answer + 1;
// }

// greedy 풀이
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    if(k >= enemy.size()) return enemy.size();
    for(int i = 0; i < k; i++) pq.push(-enemy[i]);
    for(int i = k; i < enemy.size(); i++){
        if((-pq.top()) <= enemy[i]){
            if(pq.size() == k){
                n += pq.top();
                pq.pop();
            }
            pq.push(-enemy[i]);
        } else n -= enemy[i];
        if(n < 0) return i;
    }
    return enemy.size();
}