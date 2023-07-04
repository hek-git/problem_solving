#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, K, num, ans=0, i=0;
	vector<int> list;
	vector<int> dist;

	cin >> N >>  K;
	for (int i = 0; i < N; i++) {
		cin >> num;
		list.push_back(num);
	}
	sort(list.begin(), list.end());

	for (int i = 0; i < N - 1; i++) {
		dist.push_back(list[i + 1] - list[i]);
	}
	sort(dist.begin(), dist.end());

	if (N <= K) cout << 0;
	else {
		while (N != K) {
			ans += dist[i];
			i++;
			N--;
		}
		cout << ans;
	}
}