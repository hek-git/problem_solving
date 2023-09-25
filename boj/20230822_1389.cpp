// #include <cstring>
// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// bfs를 이용한 풀이
// int N, M, u, v, ans, maxW = 10000, visited[101], step[101][101];
// vector<int> graph[101];

// void bfs(int n) {
//     queue<int> q;
//     q.push(n);
//     visited[n] = 1;

//     while (!q.empty()) {
//         int source = q.front();
//         q.pop();

//         for (int i = 0; i < graph[source].size(); i++) {
//             int next = graph[source][i];
//             if (!visited[next]) {
//                 visited[next] = 1;
//                 q.push(next);
//                 step[n][next] = min(step[n][next], step[n][source] + 1);
//             }
//         }
//     }
// }

// void initVisited() { memset(visited, 0, sizeof(visited)); }

// int main() {
//     cin >> N >> M;

//     for (int i = 0; i < M; i++) {
//         cin >> u >> v;
//         graph[u].push_back(v);
//         graph[v].push_back(u);
//     }

//     for (int i = 1; i <= N; i++) {
//         for (int j = 1; j <= N; j++) {
//             if (i == j)
//                 step[i][j] = 0;
//             else
//                 step[i][j] = 100;
//         }
//     }

//     for (int i = 1; i <= N; i++){
//         bfs(i);
//         initVisited();
//     }

//     for (int i = 1; i <= N; i++) {
//         int tmp = 0;
//         for(int j = 1; j<=N; j++){
//             tmp += step[i][j];
//         }
//         if(tmp < maxW){
//             maxW = tmp;
//             ans = i;
//         }
//     }
//     cout << ans;
// }

// 플로이드 워셜 알고리즘을 이용한 풀이
#include <algorithm>
#include <iostream>

int N, M, u, v, map[101][101], maxW = 10000, ans;
const int INF = 10000;

using namespace std;

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] = INF;
        }
    }

    for (int i = 1; i <= M; i++) {
        cin >> u >> v;
        map[u][v] = 1;
        map[v][u] = 1;
    }

    // k는 라운드 (1~N번 노드 까지 반복)
    for (int k = 1; k <= N; k++) {
        // i는 시작 지점
        for (int i = 1; i <= N; i++) {
            // k는 도착 지점
            for (int j = 1; j <= N; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= N; i++) {
        int tmp = 0;
        for (int j = 1; j <= N; j++) {
            tmp += map[i][j];
        }
        if (tmp < maxW) {
            ans = i;
            maxW = tmp;
        }
    }

    cout << ans;
}