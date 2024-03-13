#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int check[100001];

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    priority_queue<int> pq;
    sort(A.begin(), A.end());
    for(int i = 0; i < B.size(); i++)
        pq.push(-B[i]);
    
    for (int i = 0; i < A.size(); i++) {
        while(!pq.empty() && A[i] >= -pq.top()) pq.pop();
        if(pq.empty()) break;
        answer++;
        pq.pop();
    }
    return answer;
}
