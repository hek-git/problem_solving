#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, u, v, tmp, visited[101], step[101][101];
vector<int> graph[101], ans;

void dfs(int n) {
    int number = 0;

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while (!q.empty()) {
        int source = q.front();
        q.pop();

        for (int i = 0; i < graph[source].size(); i++) {
            int next = graph[source][i];
            if (!visited[next]) {
                visited[next] = 1;
                q.push(next);
                step[n][next] = min(step[n][next], step[n][source] + 1);
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(i == j) step[i][j] = 0;
            else step[i][j] = 100;
        }
    }

    for (int i = 1; i <= N; i++) {
        dfs(i);
        memset(visited, 0, sizeof(visited));
    }
    
    for (int i = 1; i <= N; i++) {
        tmp = 0;
        for(int j = 1; j<=N; j++){
            tmp += step[i][j];
        }
        ans.push_back(tmp);
    }

    tmp = *min_element(ans.begin(), ans.end());
    for(int i = 0; i<ans.size(); i++){
        if(ans[i] == tmp){
            cout << i+1;
            break;
        }
    }

}