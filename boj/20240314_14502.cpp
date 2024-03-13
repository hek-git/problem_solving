#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, n, visited[9][9], answer;
vector<pair<int, int>> list, candidate, virus;
vector<vector<int>> map;
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int countSafe(vector<vector<int>>& map) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void bfs(vector<vector<int>>& map, vector<pair<int, int>> candidate,
         pair<int, int> source) {
    for (int i = 0; i < candidate.size(); i++)
        map[candidate[i].first][candidate[i].second] = 1;
    queue<pair<int, int>> q;
    q.push(source);
    visited[source.first][source.second] = 1;

    while (!q.empty()) {
        pair<int, int> s = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_y = s.first + dir[i].first;
            int next_x = s.second + dir[i].second;
            if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= M ||
                map[next_y][next_x] != 0 || visited[next_y][next_x])
                continue;
            q.push(make_pair(next_y, next_x));
            visited[next_y][next_x] = 1;
            map[next_y][next_x] = 2;
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

void backtrack(int s) {
    if (candidate.size() == 3) {
        vector<vector<int>> map_cpy = map;
        for (int i = 0; i < virus.size(); i++) {
            if (!visited[virus[i].first][virus[i].second])
                bfs(map_cpy, candidate, virus[i]);
        }
        answer = max(answer, countSafe(map_cpy));
        initVisited();
        return;
    }

    for (int i = s; i < list.size(); i++) {
        candidate.push_back(list[i]);
        backtrack(i + 1);
        candidate.pop_back();
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        vector<int> tmp;
        for (int j = 0; j < M; j++) {
            cin >> n;
            tmp.push_back(n);
            if (n == 0) list.push_back(make_pair(i, j));
            if (n == 2) virus.push_back(make_pair(i, j));
        }
        map.push_back(tmp);
    }

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    // for(auto a : list){
    //     cout << a.first << " " << a.second << endl;
    // }
    // cout << endl;

    // for(auto a : virus) cout << a.first << " " << a.second << endl;
    // cout << endl;

    backtrack(0);
    cout << answer;
}