#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

class Coordinate {
   public:
    int x;
    int y;
    int h;

    Coordinate(int h, int y, int x) {
        this->y = y;
        this->x = x;
        this->h = h;
    }
};

int M, N, H, ans, dx[6] = {0, 1, 0, -1, 0, 0}, dy[6] = {-1, 0, 1, 0, 0, 0}, dh[6] = {0, 0, 0, 0, 1, -1};
int map[101][101][101], visited[101][101][101];
queue<Coordinate> q;

void dfs() {
    while (!q.empty()) {
        Coordinate source = q.front();
        ans = max(ans, visited[source.h][source.y][source.x]);
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nextH = source.h + dh[i];
            int nextY = source.y + dy[i];
            int nextX = source.x + dx[i];

            if (nextH > H || nextH < 1 || nextY > N || nextY < 1 || nextX > M || nextX < 1) continue;
            if (!map[nextH][nextY][nextX]) {
                if (visited[nextH][nextY][nextX]) {
                    visited[nextH][nextY][nextX] = min(visited[nextH][nextY][nextX], visited[source.h][source.y][source.x] + 1);
                } else {
                    visited[nextH][nextY][nextX] = visited[source.h][source.y][source.x] + 1;
                    q.push(Coordinate(nextH, nextY, nextX));
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &M, &N, &H);

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= M; k++) {
                scanf("%d", &map[i][j][k]);
                if (map[i][j][k] == 1) q.push(Coordinate(i, j, k));
                if (map[i][j][k] == -1) visited[i][j][k] = -1;
            }
        }
    }

    dfs();

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= M; k++) {
                if(map[i][j][k] == 0 && visited[i][j][k] == 0) ans = -1;
            }
        }
    }

    printf("%d");
}