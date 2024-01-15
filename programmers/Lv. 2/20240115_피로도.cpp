#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer, check[8], global_k;
vector<int> num;
vector<vector<int>> global_dungeons;

// num이 주어질 때 갈 수 있는 던전의 수 확인
int count_dungeons() {
    int cnt = 0, k = global_k;
    for (int i = 0; i < num.size(); i++) {
        if (k < global_dungeons[num[i]][0])
            break;
        else {
            k -= global_dungeons[num[i]][1];
            cnt++;
        }
    }
    return cnt;
}

// 백 트래킹을 이용한 모든 경우의 수 구하기
void solution() {
    if (num.size() == global_dungeons.size()) 
        answer = max(answer, count_dungeons());
    
    for (int i = 0; i < global_dungeons.size(); i++) {
        if (!check[i]) {
            check[i]++;
            num.push_back(i);
            solution();
            num.pop_back();
            check[i]--;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    global_k = k, global_dungeons = dungeons;
    solution();
    return answer;
}