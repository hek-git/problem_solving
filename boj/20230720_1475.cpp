#include <iostream>
#include <algorithm>

using namespace std;

int N, ans, num[10];

// 각 세트에는 숫자가 하나씩 밖에 없으므로(6, 9 제외) 동일한 숫자가 나오는 만큼 세트가 필요하다
int main() {

	cin >> N;

	// 입력 받은 수가 0이 될 때 까지 각 자리수의 숫자 개수를 증가
	while (N > 0) {
		num[N % 10]++;
		N /= 10;
	}

	// 6과 9 같은 경우 서로 대체 가능하므로 동일한 숫자에 대해선 한 세트로 2개 까지 사용가능하므로(나누기 2)
	num[6] = num[9] = (num[6] + num[9] + 1) / 2;

	// 최대값을 구하면 그게 필요한 세트 수
	ans = *max_element(num, num + 10);

	cout << ans;
}
