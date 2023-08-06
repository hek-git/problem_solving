#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int N, l;
int map[301][301], visited[301][301], dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
pair<int, int> s, d;

void initSetting() {
    for (int i = 0; i < l; i++) {
        memset(visited[i], 0, sizeof(visited[i]));
    }
}

void bfs(pair<int, int> dest) {
    queue<pair<int, int>> q;
    visited[dest.first][dest.second] = 1;
    q.push(dest);

    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        int x = tmp.second;
        int y = tmp.first;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (nextX < 0 || nextY < 0 || nextX >= l || nextY >= l) continue;
            if (!visited[nextY][nextX]) {
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = visited[y][x] + 1;
            }
        }
    }
}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> l;
        cin >> s.first >> s.second;
        cin >> d.first >> d.second;

        bfs(s);
        cout << visited[d.first][d.second] - 1 << endl;
        initSetting();
    }
}