#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int main() {
	int N, n, ans=0;
	vector<int> num(1001);
	num[0] = 1, num[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		for (int j = 2; i*j <= 1000; j++) {
			if (num[i] == 1) break;
			num[i * j] = 1;
		}
	}

	for (int i = 2; i < 1001; i++) {
		if (!num[i]) cout << i << "  ";
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		if (num[n]==0) ans++;
	}
	cout << ans;
}