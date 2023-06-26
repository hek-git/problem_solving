#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int T, N;
	long long ans = 0, max, num;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {

		vector<int> stock;

		scanf("%d", &N);

		//ют╥б
		for (int j = 0; j < N; j++) {
			scanf("%d", &num);
			stock.push_back(num);
		}

		max = stock[stock.size() - 1];

		for (int j = stock.size() - 1; j >= 0; j--) {
			if (max <= stock[j]) {
				max = stock[j];
			}
			else ans = ans + (max - stock[j]);
		}
		cout << ans << endl;
		ans = 0;
	}
}