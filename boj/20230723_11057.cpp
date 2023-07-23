#include <iostream>

using namespace std;

// dp[i][j]는 i 길이의 숫자 중 마지막 자리의 숫자가 j일때 오르막 수의 개수
// 마지막 숫자라는 것은 예를들어 두자리일 때 1x 라는 숫자라면 1이 마지막 숫자라는 뜻임
long long N, dp[1001][10], ans, mod = 10007;

int main() {
	
	cin >> N;

	// 길이가 1일때 모든 숫자의 오르막수는 1개이므로 dp[1][i] 업데이트
	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	
	// 1부터 시작하여 길이가 i+1이고 마지막 수가 j인 수의 오르막 수 개수는
	// 길이가 i이고 마지막 수가 j부터 9 까지인 오르막 수의 개수를 더한 것임
	// j 숫자보다 같거나 큰 숫자가 뒤에 올 수 있기 때문에 오르막 수이기 때문
	for (int i = 1; i < 1000; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++ ) {
				dp[i + 1][j] += dp[i][k] % mod;
			}
		}
	}
	
	// 길이가 N이고 0부터 9로 끝나는 오르막 수의 개수를 모두 더해주면
	// 길이가 N인 오르막 수의 개수를 구할 수 있다
	for (int i = 0; i < 10; i++) {
		ans = ans % mod + dp[N][i] % mod;
	}
	cout << ans;

}
