#include <iostream>

using namespace std;

// dp[i]는 숫자 i를 제곱 수들의 합으로 표현할 때 항의 최소개수 => i 일때 답
int N, dp[100001], small;

int main() {

	cin >> N;

	dp[1] = 1;
	
	// i 보다 작은 제곱 수들을 모두 빼보면서
	// i - (제곱 수) 중에 (제곱 수)를 나타내는 항의 개수가 가장 적은 수에 1을 더하는 방법으로
	// 숫자 i의 항의 최소 개수를 구한다
	for (int i = 2; i <= 100000; i++) {
		small = 100;
		for (int j = 1; j * j <= i; j++) {
			if (dp[i - (j * j)] + 1 < small) small = dp[i - (j * j)] + 1;
		}
		dp[i] = small;
	}

	cout << dp[N];
}