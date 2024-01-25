#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int answer = 1;
const int INF = 100000000;

int solution(int N, vector<vector<int>> road, int K) {    
    vector<vector<int>> graph(51, vector<int>(51, INF));

    // graph 초기화
    for (int i = 0; i < road.size(); i++) {
        int s = road[i][0], d = road[i][1];
        graph[s][d] = min(graph[s][d], road[i][2]);
        graph[d][s] = min(graph[d][s], road[i][2]);
    }
    
    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // K 이하로 갈 수 있는지 확인
    for (int i = 2; i <= N; i++) {
        if (graph[1][i] <= K) answer++;
    }
    
    return answer;
}