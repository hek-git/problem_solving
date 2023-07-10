#include <iostream>

using namespace std;

int map[20][20], ans, w, h;

bool check_win(int a, int b, int color) {
    
	int cnt = 0;

    // 오른쪽 상단 대각선 방향 확인
    for (int i = 0; i < 5; i++) {
        if (a - i > 0 && b + i < 20) {
            if (map[a - i][b + i] == color) cnt++;
        }
    }
    // 6목인지 확인(왼쪽 밑)
    if (a + 1 < 20 && b - 1 > 0) {
        if (map[a + 1][b - 1] == color) cnt++;
    }
    // 6목인지 확인(오른쪽 위)
    if (a - 5 > 0 && b + 5 < 20) {
        if (map[a - 5][b + 5] == color) cnt++;
    }
	cout << endl << cnt << endl;
    // 정확히 다섯개라면 해당 돌과 가장 왼쪽 좌표 반환
    if (cnt == 5 && (a < 15 && b < 15 && map[a][b] == map[a-5][b+5])) {
		cout << "1번 경우" << endl;
        ans = color;
        w = a;
        h = b;
        return true;
    }
    cnt = 0;

    // 오른쪽 방향 확인
    for (int i = 0; i < 5; i++) {
        if (b + i < 20) {
            if (map[a][b + i] == color) cnt++;
        }
    }
    // 6목인지 확인(왼쪽)
    if (b - 1 > 0) {
        if (map[a][b - 1] == color) cnt++;
    }
    // 6목인지 확인(오른쪽)
    if (b + 5 < 20) {
        if (map[a][b + 5] == color) cnt++;
    }
    // 정확히 다섯개라면 해당 돌과 가장 왼쪽 좌표 반환
    if (cnt == 5) {
		cout << "2번 경우" << endl;
        ans = color;
        w = a;
        h = b;
        return true;
    }
    cnt = 0;

    // 오른쪽 하단 대각선 방향 확인
    for (int i = 0; i < 5; i++) {
        if (a + i < 20 && b + i < 20) {
            if (map[a + i][b + i] == color) cnt++;
        }
    }
    // 6목인지 확인(왼쪽 위)
    if (a - 1 > 0 && b - 1 > 0) {
        if (map[a - 1][b - 1] == color) cnt++;
    }
    // 6목인지 확인(오른쪽 밑)
    if (a + 5 < 20 && b + 5 < 20) {
        if (map[a + 5][b + 5] == color) cnt++;
    }
    // 정확히 다섯개라면 해당 돌과 가장 왼쪽 좌표 반환
    if (cnt == 5) {
		cout << "3번 경우" << endl;
        ans = color;
        w = a;
        h = b;
        return true;
    }
    cnt = 0;

    // 아래 방향 확인
    for (int i = 0; i < 5; i++) {
        if (a + i < 20) {
            if (map[a + i][b] == color) cnt++;
        }
    }
    // 6목인지 확인(위쪽)
    if (a - 1 > 0) {
        if (map[a - 1][b] == color) cnt++;
    }
    // 6목인지 확인(아래쪽)
    if (a + 5 < 20) {
        if (map[a + 5][b] == color) cnt++;
    }
    // 정확히 다섯개라면 해당 돌과 가장 왼쪽 좌표 반환
    if (cnt == 5) {
		cout << "4번 경우" << endl;
        ans = color;
        w = a;
        h = b;
        return true;
    }
	return false;
}

int main() {
    int num;

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            cin >> num;
            map[i][j] = num;
        }
	}

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            if (map[j][i]) {
                if (check_win(j, i, map[j][i])){
                    cout << ans << endl << w << " " << h;
					return 0; 
				}
            }
        }
    }
	cout << 0;
}
