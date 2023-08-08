#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
vector<long long> v, candidate;
long long cm, ans, num, lo, hi;

int solution(int n) {
	int num = 0;
	for (auto a : v) {
		num = num + a / n;
	}
	return num;
}

int main() {

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> cm;
		v.push_back(cm);
		hi += cm;
	}

	ans = hi / N;
	hi = ans;
	lo = 1;

	while (ans >= lo) {
		
		num = solution(ans);
		if (num >= N) {
			candidate.push_back(ans);
			lo = ans + 1;
			ans = (hi + lo) / 2;
		}
		else {
			ans = (lo + ans - 1) / 2;
		}

	}

	cout << *max_element(candidate.begin(), candidate.end());
}