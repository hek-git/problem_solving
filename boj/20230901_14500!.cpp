#include <algorithm>
#include <iostream>

using namespace std;

int N, M, ans, map[501][501], visited[501][501], dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
pair<int, int> block[4][4] = {
    {{0, 0}, {0, 1}, {-1, 1}, {0, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}},
    {{0, 0}, {0, 1}, {1, 1}, {0, 2}},
    {{0, 0}, {0, 1}, {-1, 1}, {1, 1}}};

void dfs(int a, int b, int point, int len) {
    
    if (len == 3) {
        ans = max(ans, point);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nextX = b + dx[i];
        int nextY = a + dy[i];
        if (nextX < 1 || nextY < 1 || nextX > M || nextY > N) continue;
        if (!visited[nextY][nextX]) {
            // 백 트래킹으로 길이 1 일때 해당 위치에서 다시 bfs를 하여 ㅗ, ㅏ, ㅜ, ㅓ 블록 형태로 순회
            if(len == 1){
                visited[nextY][nextX] = 1;
                dfs(a, b, point + map[nextY][nextX], len + 1);
                visited[nextY][nextX] = 0;
            }
            visited[nextY][nextX] = 1;
            dfs(nextY, nextX, point + map[nextY][nextX], len + 1);
            visited[nextY][nextX] = 0;
        }
    }
    
}

void specialBlock(int a, int b) {
    for (int i = 0; i < 4; i++) {
        int point = 0;
        for (int j = 0; j < 4; j++) {
            pair<int, int> pos = make_pair(a + block[i][j].first, b + block[i][j].second);
            if(pos.first < 1 || pos.second < 1 || pos.first > N || pos.second > M) break;
            point += map[pos.first][pos.second];
        }
        ans = max(ans, point);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            visited[i][j] = 1;
            dfs(i, j, map[i][j], 0);
            // dfs로 ㅗ, ㅏ, ㅜ, ㅓ 블록을 제외한 모든 블록을 탐색한 후
            // Brute-force로 ㅗ, ㅏ, ㅜ, ㅓ 블록을 모두 탐색.
            //specialBlock(i, j);
            visited[i][j] = 0;
        }
    }

    cout << ans;
}