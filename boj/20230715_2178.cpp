#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

//map�� �̷� ����, visited[i][j]�� �湮�ߴ��� ����, solution[i][j]�� i, j ��ġ���� ���µ� �ɸ��� �ִ� �Ÿ�
int N, M, map[102][102], visited[102][102], solution[102][102];
//��, ������, �Ʒ�, ���� ���� ������� ���캸�� ���� ���� �迭
int dir_y[4] = {-1, 0, 1, 0}, dir_x[4] = {0, 1, 0, -1};

//1,1 ���� bfs(�ʺ� �켱 Ž��)�Ͽ� ���� ã�� �Լ�
void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    solution[1][1] = 1;

    while (!q.empty()) {
        //i�� j�� ���� N, M�� ��� �������̹Ƿ� ����
        if (i == N && j == M) break;
        
        //ť�� ���� �� ���Ҹ� ������(dfs�ϱ� ����)
        i = q.front().first, j = q.front().second;
        q.pop();

        //�̹� �湮�ߴٸ� �ƹ� �͵� ���� ����
        if (visited[i][j]) continue;

        //�湮 ������ ǥ��
        visited[i][j] = 1;

        // ����, ������, �Ʒ���, ������ �����ϸ� �湮 �������� Ȯ��(0�� �ƴϰ� visited ���� �ʾҴ��� Ȯ��)
        // �湮 �����ϸ� solution(����)�� ä��� �ش� ������ ť�� ����
        for (int d = 0; d < 4; d++) {
            if (map[i + dir_y[d]][j + dir_x[d]] && !visited[i + dir_y[d]][j + dir_x[d]]) {
                solution[i + dir_y[d]][j + dir_x[d]] = solution[i][j] + 1;
                q.push(make_pair(i + dir_y[d], j + dir_x[d]));
            }
        }
    }
}

int main() {
    cin >> N >> M;
    
    //�Է�
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    //1,1 ��ǥ���� ���� bfs ����
    bfs(1, 1);
    cout << solution[N][M];
}

