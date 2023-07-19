#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//p는 p[i]번째 사람이 돈을 인출하는데 걸리는 시간
int N, num, ans;
vector<int> p;

int main() {

	cin >> N;

	p.push_back(0);

	for (int i = 0; i < N; i++) {
		cin >> num;
		p.push_back(num);
	}
	
	// 돈을 인출하는데 걸리는 시간이 짧은 사람이 먼저 인출하는 것이 무조건 좋으므로
	// 오름차순으로 정렬하고 각 사람이 기다리는 시간의 합을 모두 더한다.
	sort(p.begin(), p.end());

	for (int i = 1;  i <= N; i++) {
		p[i] += p[i - 1];
		ans += p[i];
	}

	cout << ans;
}
