#include <iostream>

using namespace std;

// dp[i][j]는 i, j 위치에서 얻을 수 있는 사탕의 최대값
int N, M, map[1002][1002], dp[1002][1002];

int main() {
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	
	// 1, 1 위치에서 시작하므로 1, 1 위치에서 얻을 수 있는 사탕의 최대 개수는
	// 1, 1 위치에 있는 사탕의 개수
	dp[1][1] = map[1][1];

	// i, j는 1부터 시작하며 i, j 위치에서 부터 오른쪽, 오른쪽 아래 대각선, 아래쪽 방향에서의 최대 사탕 개수는
	// 기존에 해당 위치 까지 갔을 때 얻을 수 있는 사탕의 개수와,
	// 현재 위치까지 얻을 수 있는 사탕 개수 + 해당 위치에 있는 사탕의 개수 중 최대값이다.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], map[i + 1][j] + dp[i][j]);
			dp[i][j + 1] = max(dp[i][j + 1], map[i][j + 1] + dp[i][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], map[i + 1][j + 1] + dp[i][j]);
		}
	}

	// N, M 위치에서 얻을 수 있는 최대 사탕의 개수 출력
	cout << dp[N][M];
}
