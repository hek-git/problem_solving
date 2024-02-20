#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[201][201];

void dfs(int n, int s, vector<vector<int>>& computers){
    for(int i = 0; i < n; i++){
        if(!visited[s][i] && computers[s][i]){
            visited[s][i] = 1;
            visited[i][s] = 1;
            dfs(n, i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < computers.size(); i++){
        for(int j = 0; j < computers[i].size(); j++){
            if(!visited[i][j] && computers[i][j]){
                answer++;
                dfs(n, i, computers);
            }
        }
    }

    return answer;
}