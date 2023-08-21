#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// M, N�� ���� ũ��, farm�� ������ ���¸� ��Ÿ���� �迭, visited�� �湮 ���θ� ��Ÿ���� �迭
// x_pos, y_pos�� ���� �湮�� ��ġ�� ������ ������� ������ �迭�� ��, ������, �Ʒ�, ���� ����
// bfs�� ���� queue ����
int M, N, ans, farm[1002][1002], visited[1002][1002], x_pos[4] = { 0, 1, 0, -1 }, y_pos[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;

void bfs() {

	// q�� ������� ���� �� ����
	while (!q.empty()) {
		
		//queue�� ���� �� ���� ��ȯ(������ ����)
		pair<int, int> p;
		p = q.front();
		q.pop();

		// ��, ������, �Ʒ�, ���� ��� ������ ��ȸ�ϸ� ���� ���� ���̸� �湮�ϰ�
		// �湮�ߴ� ���̶�� ���� �ʹ� �ӵ��� ������ �ʹ� �ӵ� �� �� ���� ���� ����
		for (int i = 0; i < 4; i++) {

			int next_y = p.first + y_pos[i];
			int next_x = p.second + x_pos[i];

			if (!farm[next_y][next_x]) {
				q.push(make_pair(next_y, next_x));
				visited[next_y][next_x] = 1;
				farm[next_y][next_x] = farm[p.first][p.second] + 1;
			}
			else if (visited[next_y][next_x]) {
				farm[next_y][next_x] = min(farm[next_y][next_x], farm[p.first][p.second] + 1);
			}
		}		
	}
}


int main() {

	// �ʱ� ������ ��� 1���ϰ�(�׵θ� �κ��� 1�� ä�� bfs���� �湮�� ���ϱ� ����)

	memset(farm, 1, sizeof(farm));
	cin >> M >> N;

	// �Է�, 1�� ��ġ���� �丶�䰡 �ͱ� �����ϹǷ� ť�� �ٷ� ���� �� �湮 ���� �ֽ�ȭ
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> farm[i][j];
			if (farm[i][j] == 1) {
				q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
		}
	}

	bfs();

	//���� ���� ���� ū ���� ���ϰ� 0�� �ϳ��� ������ �丶�䰡 ��� ���� �ʴ� ���� �����̹Ƿ� -1 ����ϰ� ����
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (ans < farm[i][j]) ans = farm[i][j];

			else if (farm[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << ans - 1;

}