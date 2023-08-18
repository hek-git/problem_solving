#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
int map[1001][1001], visited[1001][1001], ans[1001][1001];
pair<int, int> source;

void dfs(pair<int, int> s) {
    visited[s.first][s.second] = 1;
    ans[s.first][s.second] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(s.first, s.second));

    while (!q.empty()) {
        pair<int, int> source = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int destX = source.second + dx[i];
            int destY = source.first + dy[i];
            if (!visited[destY][destX] && map[destY][destX]) {
                visited[destY][destX] = 1;
                q.push(make_pair(destY, destX));
                ans[destY][destX] = ans[source.first][source.second] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) source = make_pair(i, j);
            if (map[i][j] == 0) ans[i][j] = 0;
        }
    }

    dfs(source);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}