#include <iostream>
#include <vector>

using namespace std;


int main() {

	int N, n, num = 1, a, b, k = 0, increase = 1;
	bool run = true;
	pair<int, int> pos;
	vector<int> y{ -1, 0, 1, 0 };
	vector<int> x{ 0, 1, 0, -1 };
	cin >> N >> n;

	vector<vector<int>> snail(N, vector<int>(N));

	a = N / 2, b = N / 2;

	while (run) {
		for (int i = 0; i < increase; i++) {
			if (num == n) {
				pos.first = a + 1;
				pos.second = b + 1;
			}
			if (num > N*N) {
				run = false;
				break;
			}
			snail[a][b] = num;
			num++;
			a += y[k], b += x[k];
		}
		k = (k + 1) % 4;
		if (k % 2 == 0) increase++;
		
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << snail[i][j] << " ";
		}
		cout << endl;
	}
	cout << pos.first << " " << pos.second;
}
