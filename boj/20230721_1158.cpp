#include <iostream>
#include <queue>

using namespace std;

int N, K, cnt;
queue<int> q;

int main() {
	
	cin >> N >> K;
	
	//1 부터 N까지 모든 숫자 q에 push
	for (int i = 1; i <= N; i++) q.push(i);

	cout << "<";
	// K번째 숫자마다 출력해야하므로 K번째 숫자가 아닐땐 q에 그 숫자를 다시 push
	// K번째 숫자일 땐 출력 형식에 맞게 출력한 후 q에 push 하지 않는다.
	// q의 크기가 1 일땐 마지막 숫자이므로 ', ' 없이 출력
	while (!q.empty()) {
		cnt++;
		if (cnt == K) {
			cnt = 0;
			if (q.size() == 1) {
				cout << q.front();
			}
			else cout << q.front() << ", ";
			
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
	}
	cout << ">";
	return 0;
}
