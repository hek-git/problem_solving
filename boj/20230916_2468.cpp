#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, ans, map[101][101], visited[101][101], dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

void bfs(pair<int, int> source, int rain) {
    queue<pair<int, int>> q;
    q.push(source);

    while (!q.empty()) {
        pair<int, int> s = q.front();
        q.pop();
        visited[s.first][s.second] = 1;

        for (int i = 0; i < 4; i++) {
            int nextX = s.second + dx[i];
            int nextY = s.first + dy[i];

            if (nextY >= N || nextY < 0 || nextX >= N || nextX < 0 || map[nextY][nextX] <= rain) continue;
            if (!visited[nextY][nextX]) {
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = 1;
            }
        }
    }
}

void initVisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for (int rain = 0; rain <= 100; rain++) {
        int tmp = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && map[i][j] > rain) {
                    bfs(make_pair(i, j), rain);
                    tmp++;
                }
            }
        }
        initVisited();
        //cout << rain << "ÀÏ ¶§ " << tmp << '\n';
        ans = max(ans, tmp);
    }
    cout << ans;
}