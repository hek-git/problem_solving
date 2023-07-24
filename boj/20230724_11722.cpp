#include <iostream>
#include <algorithm>

using namespace std;

// num은 수열 정보를 담은 배열
// dp[i]는 i 번째 숫자까지 가장 긴 감소하는 수열
// cmp는 현재 숫자와 이전 숫자를 비교하여 감소하는 수열인지 확인하기 위함
int N, num[1001], dp[1001], cmp;

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	// dp[1]은 1 cmp는 첫 번째 숫자 부터 시작
	dp[1] = 1;
	cmp = num[1];

	// 2 번째 숫자부터 시작하며 첫 번째 숫자까지 순회하며 자기보다 큰 숫자이면서 감소하는 수열의 길이가 가장 긴 값 +1
	// i 번째 숫자까지 가장 긴 감소하는 수열의 길이는 dp[i]에 저장 되어있다.
	for (int i = 2; i <= N; i++) {
		int p = i - 1, m = 0;
		while (p) {
			if (num[i] < cmp && dp[m] < dp[p]) {
				m = p;
			}
			cmp = num[--p];
		}
		dp[i] = dp[m] + 1;
		//cmp는 다음 반복에 비교할 숫자의 바로 전 번째 숫자
		cmp = num[i];
	}

	//dp 중 최대 값 찾기(답)
	cout << *max_element(dp, dp + 1001);

	return 0;
}
