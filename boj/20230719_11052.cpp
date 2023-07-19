#include <iostream>

using namespace std;

// N은 구입할 카드 개수, card[i]는 i개 짜리 카드팩 구입 비용
// dp[i]는 i개 짜리 카드팩 까지 구입할 수 있을 때 카드 i개를 가장 비싸게 사는 값이 저장
int N, card[1001], dp[1001];

int main() {

	cin >> N;
	
	// 입력, dp[i]에 일단 i개의 카드를 사는데 드는 최대 비용은 i개 짜리 카드팩을 사는 비용으로 입력
	// 정답이라는 보장은 없지만 나중에 비교를 위함
	for (int i = 1; i <= N; i++) {
		cin >> card[i];
		dp[i] = card[i];
	}

	// 2개짜리 카드팩 부터 시작하여 N개 짜리 카드팩 까지 반복
	// dp[i]는 두 수를 더하여 i를 만들 수 있는 모든 경우의 dp를 돌며
	// 더했을 때 가장 큰 수를 저장
	for (int i = 2; i <= N; i++) {
		int m = 0;
		for (int j = 0; j <= i/2; j++) {
			m = max(m, dp[j] + dp[i-j]);
		}
		// 가장 비용이 많이 드는 경우의 수의 비용을 dp[i]에 대입
		dp[i] = m;
	}

	// N개의 카드를 사는데 드는 최대 비용 출력
	cout << dp[N];

}
