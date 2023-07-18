#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, map[27][27], visited[27][27], cnt, x_pos[4] = {0, 1, 0, -1}, y_pos[4] = {-1, 0, 1, 0};
vector<int> house;

void bfs(int i, int j) {
    
    cnt = 0;
    queue<pair<int, int>> q;

    q.push(make_pair(i, j));
    visited[i][j] = 1;

    while (!q.empty()) {

        pair<int, int> p;
        p = q.front();
        q.pop();
        cnt++;

        for (int c = 0; c < 4; c++) {
            if (map[p.first + y_pos[c]][p.second + x_pos[c]] && !visited[p.first + y_pos[c]][p.second + x_pos[c]]) {
                q.push(make_pair(p.first + y_pos[c], p.second + x_pos[c]));
                visited[p.first + y_pos[c]][p.second + x_pos[c]] = 1;
            }
        }
    }

    house.push_back(cnt);
}

int main() {

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] && !visited[i][j]) bfs(i, j);
        }
    }

    sort(house.begin(), house.end());
    cout << house.size() << endl;
    for(auto h : house) cout << h << endl;

}