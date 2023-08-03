#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, ans1, ans2;
int visited[101][101], yPos[4] = {-1, 0, 1, 0}, xPos[4] = {0, 1, 0, -1};
vector<string> map;

void dfs(int a, int b) {
    visited[a][b] = 1;
    char c = map[a][b];

    for (int i = 0; i < 4; i++) {
        if (a + yPos[i] < 0 || b + xPos[i] < 0 || a + yPos[i] >= N || b + xPos[i] >= N) {
            continue;
        }

        if (!visited[a + yPos[i]][b + xPos[i]] && map[a + yPos[i]][b + xPos[i]] == c) {
            dfs(a + yPos[i], b + xPos[i]);
        }
    }
}

void initSetting() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'R') map[i][j] = 'G';
            visited[i][j] = 0;
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                ans1++;
            }
        }
    }

    initSetting();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                ans2++;
            }
        }
    }

    cout << ans1 << " " << ans2;
}