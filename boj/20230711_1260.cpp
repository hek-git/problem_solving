#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, V, a, b;
vector<int> Edge[1001];
bool visited[1001];

void DFS(int v) {
    cout << v << " ";
    visited[v] = true;
    for (int i = 0; i < Edge[v].size(); i++) {
        if (!visited[Edge[v][i]]) DFS(Edge[v][i]);
    }
}

void BFS(int v) {
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {

        int next = q.front();
        cout << next << " ";

        for (int i = 0; i < Edge[next].size(); i++) {
            if(!visited[Edge[next][i]]) {
                visited[Edge[next][i]] = true;
                q.push(Edge[next][i]);
            }
        }
        q.pop();
    }
}

int main() {
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        Edge[a].push_back(b);
        Edge[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
        sort(Edge[i].begin(), Edge[i].end());

    DFS(V);
    cout << endl;
    BFS(V);
}
