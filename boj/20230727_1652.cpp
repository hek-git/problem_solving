#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, width, length, cnt_w, cnt_l, max_w, max_l;

int main() {

	cin >> N;
	vector<string> map(N);

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (map[i][j] == 'X'){
				if (cnt_w >= 2) width++;
				cnt_w = 0;
			}
			else cnt_w++;

			if (map[j][i] == 'X') {
				if (cnt_l >= 2) length++;
				cnt_l = 0;
			}
			else cnt_l++;
		}
		//cout << max_w << " " << max_l << endl;;

		if (cnt_w >= 2) width++;
		if (cnt_l>= 2) length++;

		cnt_w = cnt_l = 0;
	}

	cout << width << " " << length;
}