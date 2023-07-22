#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

// T는 테스트 케이스 횟수, M은 농장 가로의 길이, N은 농장 세로의 길이, num은 배추의 개수, m은 입력 받는 x 축 좌표, n은 입력 받는 y 축 좌표
// map은 배추밭의 형태, visited는 방문 여부, x_pos y_pos는 위쪽 오른쪽 아래쪽 왼쪽을 순서대로 순회하기 위해 선언
int T, M, N, num, m, n, ans;
int map[52][52], visited[52][52], x_pos[4] = { 0, 1, 0, -1 }, y_pos[4] = { -1, 0, 1, 0 };

void bfs(int a, int b) {

	// q에 push 및 시작 지점 방문 표시
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	visited[a][b] = 1;

	while (!q.empty()) {

		// 탐색할 좌표(큐 가장 앞에 있는 좌표)를 pop하고
		pair<int, int> p = q.front();
		q.pop();

		// 위, 오른쪽, 아래, 왼쪽을 순서대로 탐색할 수 있는 구간인지 살펴본 다음 가능하면 큐에 push, 가능하지 않으면 push 하지 않음
		for (int i = 0; i < 4; i++) {
			if (map[p.first + y_pos[i]][p.second + x_pos[i]] && !visited[p.first + y_pos[i]][p.second + x_pos[i]]) {
				q.push(make_pair(p.first + y_pos[i], p.second + x_pos[i]));
				visited[p.first + y_pos[i]][p.second + x_pos[i]] = 1;
			}

		}
	}

}

int main() {
	
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> num;

		// 입력 편의를 위해 +1 씩하여 좌표를 그대로 인덱스로 사용
		for (int j = 0; j < num; j++) {
			cin >> m >> n;
			map[n + 1][m + 1] = 1;
		}		

		// 방문하지 않았고 1인 경우 지렁이를 심을 수 있는 곳이므로 bfs 실행 
		// 이 bfs가 실행된 횟수가 지렁이를 놓을 수 있는 최소 수이다
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (map[j][k] && !visited[j][k]) {
					bfs(j, k);
					ans++;
				}
			}
		}

		// 답을 출력한 뒤 map과 visited, ans를 초기화 후 다시 입력 받아 시작
		cout << ans << endl;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		ans = 0;
	}

	return 0;
}
