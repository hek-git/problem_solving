#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int T, N, M, w, ans;


void rotateQueue(queue<pair<int, int>>& q) {
	q.push(q.front());
	q.pop();
}


int main(){

	cin >> T;

	for (int i = 0; i < T; i++) {
		queue<pair<int, int>> q;

		cin >> N >> M;

		for (int j = 0; j < N; j++) {
			cin >> w;
			q.push(make_pair(w, j));
		}
		
		int num = 0;

		while (!q.empty()) {
			//큐를 완벽히 돌리는 과정
			while (true) {
				queue<pair<int, int>> tmp = q;
				int cmp = q.front().first;
				int cnt = 0;

				while (!tmp.empty()) {
					if (cmp < tmp.front().first) {
						rotateQueue(q);
						break;
					}
					else cnt++;
					tmp.pop();
				}
				if (cnt == N) break;
			}

			num++;
			int cmp = q.front().second;
			if (cmp == M) {
				ans = num;
				break;
			}
			q.pop();
			N--;
		}

		cout << ans << endl;

	}
	
	
}