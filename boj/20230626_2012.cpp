#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int n, num;
	long long ans = 0;
	vector<int> v;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) ans += (long long)v[i - 1] > i ? v[i - 1] - i : i - v[i - 1];
	cout << ans;
}