#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;

// 소수인지 판별하는 함수(소수이면 true 아니라면 false)
bool IsPrime(int N) {

	// 1은 소수가 아니므로 false
	if (N == 1) return false;

	// 2부터 시작하여 N의 제곱근(N의 약수가 될 수 있는 최대 값)까지 반복하고
	// 제곱근까지의 숫자 중 하나라도 나누어 떨어지는 수가 있다면 소수가 아니므로 즉시 false 반환
	// 하나도 나누어 떨어지지 않으면 소수이므로 true 반환
	for (int i = 2; i <= (int)sqrt(N); i++) {
		if (N % i == 0) {
			return false;
		}
	}
	return true;
}

// 회문인지 판별하는 함수 투 포인터를 이용한다. (맞다면 true, 아니라면 false)
bool IsPalindrome(int N) {
	
	// lo는 문자열로 변환한 숫자의 가장 처음을 가리키고 hi는 마지막을 가리킴
	// to_string 함수를 이용해 숫자를 문자열로 바꾼다(itos)
	int hi, lo;
	string s = to_string(N);
	lo = 0; hi = s.size() - 1;
	
	// lo가 hi 보다 같거나 크면 종료
	// lo와 hi가 가리키는 문자가 다르면 회문이 아니므로 그 즉시 false 반환
	// 모두 다르지 않으면 회문이므로 true 반환
	while (lo < hi) {
		if (s[lo] != s[hi]) return false;
		lo++, hi--;
	}
	return true;
}


int main() {

	cin >> N;
	
	while (true) {
		// N부터 시작하고 소수이면서 회문이라면 정답의 조건 중 가장 작은 수이므로 반복문 탈출
		// 둘 중 하나라도 아니라면 N을 증가하고 다시 실행
		// 실행 시간이 조금 더 짧은 IsPalindrome 함수를 먼저 실행
		// IsPalindrome 시간 복잡도 : O(len(N)), IsPrime 시간 복잡도 : O(root(N))
		if (IsPalindrome(N) && IsPrime(N)) break;
		N++;
	}
	cout << N;
}