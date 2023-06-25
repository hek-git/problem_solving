#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;
int main() {
	map<int, int> m;
	vector<int> n;
	int num, ans=0, cnt=0;

	for (int i = 1; i <= 8; i++) {
		scanf("%d", &num);
		m.insert({ num, i });
	}

	for (auto iter = m.begin(); iter != m.end(); iter++, cnt++) {
		if (cnt < 3) continue;
		ans += iter->first;
		n.push_back(iter->second);
	}

	sort(n.begin(), n.end());

	cout << ans << endl;
	for (auto a : n) {
		cout << a << " ";
	}
}