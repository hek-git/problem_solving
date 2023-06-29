#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	int R, C, rank = 1, flag = 0;
	vector<int> ans(10, 0);
	vector<string> map;

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		s = '0' + s;
		map.push_back(s);
	}

	for (int i = C - 1; i > 1; i--) {
		for (int j = 0; j < R; j++) {
			int ch = map[j][i] - '0';
			if ((ch > 0 && ch <= 9) && !ans[ch]) {
				ans[ch] = rank;
				flag = 1;
			}
		}
		if (flag) rank++;
		flag = 0;
	}

	for (int i = 1; i < 10; i++) {
		cout << ans[i] << endl;
	}

}