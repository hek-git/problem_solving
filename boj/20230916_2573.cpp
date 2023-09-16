#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M, tmp, ans, map[301][301], mapCpy[301][301], visited[301][301], dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

void cpyMap(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            map[i][j] = mapCpy[i][j];
        }
    }
}

void initVisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 0;
        }
    }
}

void bfs(pair<int, int> source) {
    queue<pair<int, int>> q;
    q.push(source);

    while (!q.empty()) {
        pair<int, int> s = q.front();
        q.pop();
        visited[s.first][s.second] = 1;

        for (int i = 0; i < 4; i++) {
            int nextX = s.second + dx[i];
            int nextY = s.first + dy[i];

            if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0 || map[nextY][nextX] == 0) continue;
            if (!visited[nextY][nextX]) {
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = 1;
            }
        }
    }
}

void melt() {
    for(int i = 0; i<N; i++){
        for(int j = 0 ; j<M; j++){
            int meltNum = 0;
            for(int k = 0; k<4; k++){
                if(map[i + dy[k]][j + dx[k]] == 0) meltNum++;
            }
            if(mapCpy[i][j] - meltNum < 0) mapCpy[i][j] = 0;
            else mapCpy[i][j] -= meltNum;
        }
    }
    cpyMap();
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            mapCpy[i][j] = map[i][j];
        }
    }

    while (true) {
        tmp = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && map[i][j]) {
                    bfs(make_pair(i, j));
                    tmp++;
                }
            }
        }
        if (tmp >= 2) break;
        if (tmp == 0) {
            ans = 0;
            break;
        }
        melt();
        initVisited();
        ans++;
    }
    cout << ans;
}