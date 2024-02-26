#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

void bfs(int start, vector<int> graph[], vector<int>& visited){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int i = 0; i < graph[s].size(); i++){
            int next = graph[s][i];
            if(visited[next] == -1){
                visited[next] = visited[s] + 1;
                q.push(next);
            }
        }
    }

}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, m = 0;
    vector<int> graph[20001], visited(20001, -1);
    visited[0] = 1;
    for(int i = 0; i < edge.size(); i++){
        graph[edge[i][0] - 1].push_back(edge[i][1] - 1);
        graph[edge[i][1] - 1].push_back(edge[i][0] - 1);
    }
    bfs(0, graph, visited);
    m = *max_element(visited.begin(), visited.end());

    for(int i = 0; i < n; i++){
        if(visited[i] == m) answer++;
        // cout << visited[i] << " ";
    }

    return answer;
}