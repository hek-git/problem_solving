#include <iostream>
#include <algorithm>

using namespace std;

// num은 수열 정보를 담은 배열
// dp[i]는 i 번째 숫자까지 가장 큰 증가하는 수열의 합
// cmp는 현재 숫자와 이전 숫자를 비교하여 증가하는 수열인지 확인하기 위함
int N, num[1001], dp[1001];

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	// dp[1]은 자기 자신의 합이므로 num[1]
	dp[1] = num[1];

	// i 번째 숫자부터 시작하며 각 반복 당 i-1 번째 숫자까지 순회하며 나보다 작은 숫자가 있다면
	// 이전까지의 가장 큰 증가하는 부분 수열의 합과 비교하여 더 크다면 dp[i]에 그 값을 저장  
	// i 번째 숫자까지 가장 큰 증가하는 부분 수열의 값이 들어 있다
	for (int i = 2; i <= N; i++) {
		int sum = num[i];
		for (int j = 1; j <= i; j++) {
			if (num[i] > num[j] && sum < num[i] + dp[j]) {
				sum = num[i] + dp[j];
			}
		}
		dp[i] = sum;
	}

	//dp 중 최대 값 찾기(답)
	cout << *max_element(dp, dp + 1001);

	return 0;
}
