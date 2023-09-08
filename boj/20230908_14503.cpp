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

        // �ش� ��ġ�� ������ �湮���� �ʾҴٸ� visited �ֽ�ȭ �� ans ����
        if (!visited[src.first][src.second]) {
            visited[src.first][src.second] = ans + 1;
            ans++;
        }

        // �ݽð� �������� 90���� ȸ���ϸ� ��ֹ��� �ƴϸ鼭 û���� �� �ִ� ��ġ���
        // queue�� push�ϰ� flag bit �����Ͽ� ���� �ڵ� ���� x
        for (int i = 0; i < 4; i++) {
            dir = (dir + 3) % 4;
            int destX = src.second + dx[dir];
            int destY = src.first + dy[dir];

            // ���� ��ȿ�� �˻�
            if (destX < 0 || destY < 0 || destX >= M || destY >= N) continue;
            if (!map[destY][destX] && !visited[destY][destX]) {
                q.push(make_pair(destY, destX));
                flag = 1;
                break;
            }
        }

        // ���� �ڵ忡�� flag bit �������� �ʾҴٸ� �ֺ��� û���� ������ ���� ���̹Ƿ�
        // ���� ���� �������� �ڷ� �̵� �������� �˻�
        if (!flag) {
            int backX = src.second + dx[(dir + 2) % 4];
            int backY = src.first + dy[(dir + 2) % 4];

            // ���� ��ȿ�� �˻�
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
    // ���� ��ǥ�� ���� ������ �Ű������� �ѱ�� bfs ����
    bfs(src, dir);

    // visited ���
    // cout << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans;
}