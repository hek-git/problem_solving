#include <iostream>
#include <vector>

using namespace std;

int bingo[6][6], num[6][6];

int check_bingo(int bingo[][6]) {

}

int main() {
	int n, ans = 0, bingo_cnt = 0, cnt=1;
	pair<int, int> pos[26];

	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			cin >> n;
			bingo[i][j]=n;
			pos[n].first = i;
			pos[n].second = j;
		}
	}

	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			cin >> n;
			num[i][j] = n;
		}
	}

	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			int a = pos[num[i][j]].first, b = pos[num[i][j]].second;
			bingo[a][b] = 0;
			bingo_cnt += check_bingo(bingo, );
			if (bingo_cnt >= 3) {
				ans = cnt;
				break;
			}
			cnt++;
		}
	}
	cout << ans;
}
