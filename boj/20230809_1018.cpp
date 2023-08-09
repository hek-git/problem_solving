#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M, num, ans = 2500;
vector<string> map, cpy;

int solution(int a, int b) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == 0 && j == 0) continue;
			if (i != 0 && j == 0) {
				if (cpy[a + i - 1][b + j] == cpy[a + i][b + j]) {
					cpy[a + i][b + j] = cpy[a + i - 1][b + j] == 'B' ? 'W' : 'B';
					num++;
				}
			}
			else {
				if (cpy[a + i][b + j - 1] == cpy[a + i][b + j]) {
					cpy[a + i][b + j] = cpy[a + i][b + j - 1] == 'B' ? 'W' : 'B';
					num++;
				}
			}
		}
		if (num > ans) return num;
	}
	return num;
}

int main(){

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		map.push_back(s);
	}

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M-7; j++) {
			
			cpy = map;
			if (map[i][j] == 'B') num++;
			cpy[i][j] = 'W';
			//cout << solution(i, j) << endl;
			ans = min(ans, solution(i, j));
			num = 0;

			cpy = map;
			if (map[i][j] == 'W') num++;
			cpy[i][j] = 'B';
			//cout << solution(i, j) << endl<< endl; 
			ans = min(ans, solution(i, j));
			num = 0;
		}
	}
	
	cout << ans;

}