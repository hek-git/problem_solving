#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N, Q, l, tmp, ice, iceSize, map[65][65], visited[65][65];
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<int> L;

void print() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void rotateArray(pair<int, int> s, int n) {
    int len = n;
    for (int i = 0; i < n / 2; i++) {
        int lastX = s.second + len - 1;
        int lastY = s.first + len - 1;
        vector<int> tmp;
        for (int j = 0; j < len; j++) tmp.push_back(map[s.first][s.second + j]);
        for (int a = 0; a < len; a++) map[s.first][lastX - a] = map[s.first + a][s.second];
        for (int b = 0; b < len; b++) map[s.first + b][s.second] = map[lastY][s.second + b];
        for (int c = 0; c < len; c++) map[lastY][s.second + c] = map[lastY - c][lastX];
        for (int d = 0; d < len; d++) map[s.first + d][lastX] = tmp[d];

        s.first++;
        s.second++;
        len -= 2;
    }
}

void rotateArray(int n) {
    n = (int)pow(2, n);
    for (int i = 1; i <= N; i += n) {
        for (int j = 1; j <= N; j += n) {
            rotateArray(make_pair(i, j), n);
        }
    }
}

void melt() {
    vector<pair<int, int>> m;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nextX = j + dir[k].second;
                int nextY = i + dir[k].first;
                if (nextY < 1 || nextX < 1 || nextY > N || nextX > N || map[nextY][nextX] == 0) continue;
                cnt++;
            }
            if (cnt < 3) m.push_back(make_pair(i, j));
        }
    }
    for (int i = 0; i < m.size(); i++) {
        if(map[m[i].first][m[i].second]) map[m[i].first][m[i].second]--;
    }
    // print();
}

void dfs(pair<int, int> s, int n) {
    tmp++;
    iceSize = max(iceSize, n);
    visited[s.first][s.second] = 1;
    for (int i = 0; i < 4; i++) {
        int nextX = s.second + dir[i].second;
        int nextY = s.first + dir[i].first;
        if (nextY < 1 || nextX < 1 || nextY > N || nextX > N || visited[nextY][nextX] || !map[nextY][nextX]) continue;
        dfs(make_pair(nextY, nextX), n + 1);
    }
}

void solve() {
    // 마법 시전과 얼음 양 변화 적용 구문
    for (int i = 0; i < Q; i++) {
        rotateArray(L[i]);
        melt();
    }
    //cout << endl;
    //print();
    // 정답 구하기(남은 얼음의 합, 가장 큰 덩어리가 차지하는 칸 개수)
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!visited[i][j] && map[i][j]){
                dfs(make_pair(i, j), 1);
                iceSize = max(iceSize, tmp);
                tmp = 0;
            }
            
            ice += map[i][j];
        }
    }
}

int main() {
    cin >> N >> Q;
    N = (int)pow(2, N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < Q; i++) {
        cin >> l;
        L.push_back(l);
    }
    solve();
    cout << ice << endl << iceSize;
}