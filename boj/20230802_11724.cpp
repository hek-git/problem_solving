#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, u, v, visited[1001], ans;
vector<int> graph[1001];

void dfs(int start) {

    visited[start] = 1;
    
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if(!visited[next]) dfs(next);
    }
}

int main() {

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            //cout << i <<" 일 때 실행" << endl;
            dfs(i);
            ans++;
        }
    }
    cout << ans;
}
