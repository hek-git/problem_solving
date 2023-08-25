#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int N, M, dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}, visited[601][601], ans;
vector<string> map;

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    visited[a][b] = 1;

    while (!q.empty()) {
        pair<int, int> source = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = source.second + dx[i];
            int nextY = source.first + dy[i];

            if (nextX >= M || nextX < 0 || nextY >= N || nextY < 0) continue;
            if (!visited[nextY][nextX] && map[nextY][nextX] != 'X') {
                if (map[nextY][nextX] == 'P') ans++;
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = 1;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'I') bfs(i, j);
        }
    }

    if (ans)
        cout << ans;
    else
        cout << "TT";
}