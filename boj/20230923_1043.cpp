#include <iostream>
#include <vector>

using namespace std;

int N, M, n, m, num, ans, flag, people[51], party[51][51];

void check() {
    flag = 0;
    for (int i = 1; i < 51; i++) {
        // 이미 진실을 얘기해야하는 사람이면 건너뜀
        if (people[i]) continue;
        // 모든 party를 순회하며 i번 사람이 있는 곳을 찾음
        for (int j = 0; j < M; j++) {
            if (party[j][i]) {
                for (int k = 0; k < 51; k++) {
                    if (party[j][k] == 1 && people[k] == 1) {
                        people[i] = 1;
                        flag = 1;
                        return;
                    }
                }
            }
        }
    }

}

void decide() {
    // i번 사람한테 진실, 거짓을 얘기할지 유무를 판단
    for (int i = 1; i < 51; i++) {
        // 이미 진실을 얘기해야하는 사람이면 건너뜀
        if (people[i]) continue;
        // 모든 party를 순회하며 i번 사람이 있는 곳을 찾음
        flag = 0;
        for (int j = 0; j < M; j++) {
            if (party[j][i]) {
                for (int k = 0; k < 51; k++) {
                    if (party[j][k] == 1 && people[k] == 1) {
                        people[i] = 1;
                        flag = 1;
                        break;
                    }
                }
            }
        }
        while (flag) check();
    }
}

void solve() {
    for (int i = 0; i < M; i++) {
        flag = 1;
        for (int j = 1; j < 51; j++) {
            if (party[i][j] == 1 && people[j] == 1) {
                flag = 0;
                break;
            }
        }
        if (flag) ans++;
    }
}

int main() {
    cin >> N >> M;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        people[num] = 1;
    }

    for (int i = 0; i < M; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> num;
            party[i][num] = 1;
        }
    }
    decide();
    for (int i = 1; i <= N; i++) {
        cout << people[i] << " ";
    }
    solve();
    cout << ans;
}
