#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M, ans, dir, flag, dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
int map[50][50], visited[50][50];
pair<int, int> src;

void bfs(pair<int, int> s, int dir) {
    queue<pair<int, int>> q;
    q.push(s);

    while (!q.empty()) {
        pair<int, int> src = q.front();
        q.pop();
        flag = 0;

        // 해당 위치를 이전에 방문하지 않았다면 visited 최신화 및 ans 증가
        if (!visited[src.first][src.second]) {
            visited[src.first][src.second] = ans + 1;
            ans++;
        }

        // 반시계 방향으로 90도씩 회전하며 장애물이 아니면서 청소할 수 있는 위치라면
        // queue에 push하고 flag bit 설정하여 이후 코드 실행 x
        for (int i = 0; i < 4; i++) {
            dir = (dir + 3) % 4;
            int destX = src.second + dx[dir];
            int destY = src.first + dy[dir];

            // 범위 유효성 검사
            if (destX < 0 || destY < 0 || destX >= M || destY >= N) continue;
            if (!map[destY][destX] && !visited[destY][destX]) {
                q.push(make_pair(destY, destX));
                flag = 1;
                break;
            }
        }

        // 이전 코드에서 flag bit 설정되지 않았다면 주변에 청소할 구역이 없는 것이므로
        // 현재 방향 기준으로 뒤로 이동 가능한지 검사
        if (!flag) {
            int backX = src.second + dx[(dir + 2) % 4];
            int backY = src.first + dy[(dir + 2) % 4];

            // 범위 유효성 검사
            if (backX < 0 || backY < 0 || backX >= M || backY >= N);
            else if (!map[backY][backX]) {
                q.push(make_pair(backY, backX));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> src.first >> src.second >> dir;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    // 시작 좌표와 시작 방향을 매개변수로 넘기고 bfs 시작
    bfs(src, dir);

    // visited 출력
    // cout << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans;
}