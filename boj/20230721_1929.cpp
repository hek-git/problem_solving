#include <iostream>
#include <cstring>

using namespace std;

// i가 소수라면 prime[i]=1, 아니라면 0을 나타내는 배열 prime[i]
int M, N, prime[1000001];

int main() {

	// prime 배열의 모든 수를 1로 초기화
	memset(prime, 1, sizeof(prime));
	
	cin >> M >> N;
	
	// 0과 1은 소수가 아니므로 0으로 따로 초기화
	prime[0] = 0;
	prime[1] = 0;

	// 2부터 시작하여 1,000,000 까지 각 숫자들의 배수는 소수가 아니므로 0으로 값 설정
	for (int i = 2; i <= N; i++) {
		// 시간을 조금 줄이기 위해 이미 소수가 아닌 숫자는 그 숫자의 배수도 소수가 아니므로 다음 숫자로 건너뛴다
		if (!prime[i]) continue;
		for (int j = 2; i * j <= N; j++) {
			prime[i * j] = 0;
		}
	}

	for (int i = M; i <= N; i++) {
		if (prime[i]) printf("%d\n", i);
	}
}
