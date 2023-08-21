#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// M, N은 농장 크기, farm은 농장의 상태를 나타내는 배열, visited는 방문 여부를 나타내는 배열
// x_pos, y_pos는 다음 방문할 위치의 방향을 순서대로 선언한 배열로 위, 오른쪽, 아래, 왼쪽 순서
// bfs를 위한 queue 선언
int M, N, ans, farm[1002][1002], visited[1002][1002], x_pos[4] = { 0, 1, 0, -1 }, y_pos[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;

void bfs() {

	// q가 비어있지 않을 때 까지
	while (!q.empty()) {
		
		//queue의 가장 앞 원소 반환(기준점 설정)
		pair<int, int> p;
		p = q.front();
		q.pop();

		// 위, 오른쪽, 아래, 왼쪽 모든 방향을 순회하며 가지 않은 곳이면 방문하고
		// 방문했던 곳이라면 현재 익는 속도와 기존에 익는 속도 중 더 빠른 값을 취함
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

	// 초기 세팅을 모두 1로하고(테두리 부분을 1로 채워 bfs에서 방문을 안하기 위함)

	memset(farm, 1, sizeof(farm));
	cin >> M >> N;

	// 입력, 1인 위치에서 토마토가 익기 시작하므로 큐에 바로 삽입 및 방문 여부 최신화
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

	//농장 내에 가장 큰 값을 구하고 0이 하나라도 있으면 토마토가 모두 익지 않는 농장 구조이므로 -1 출력하고 종료
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