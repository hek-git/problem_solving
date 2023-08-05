#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n, m, num, sol = 0;
int xPos[4] = {0, 1, 0, -1}, yPos[4] = {-1, 0, 1, 0}, visited[51][51];
vector<string> map;

void initSetting() {
    for (int i = 0; i < 51; i++) {
        memset(visited[i], 0, sizeof(visited[i]));
    }
}

int bfs(int a, int b) {
    int cost = 0;
    queue<pair<int, int>> q;

    q.push(make_pair(a, b));
    visited[a][b] = 1;

    while (!q.empty()) {
        pair<int, int> next = q.front();
        q.pop();

        a = next.first;
        b = next.second;
        cost = max(cost, visited[a][b]) - 1;

        for (int i = 0; i < 4; i++) {
            int nextX = b + xPos[i];
            int nextY = a + yPos[i];
            if (nextX < 0 || nextY < 0 || nextX >= m || nextY >= n) continue;
            if (!visited[nextY][nextX] && map[nextY][nextX] == 'L') {
                visited[nextY][nextX] = visited[a][b] + 1;
                q.push(make_pair(nextY, nextX));
            }
        }
    }

    return cost;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'L') {
                sol = max(sol, bfs(i, j));
            }

            //cout << endl;
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < m; j++) {
            //         cout << visited[i][j];
            //     }
            //     cout << endl;
            // }
            initSetting();
        }
    }

    cout << sol;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }
}