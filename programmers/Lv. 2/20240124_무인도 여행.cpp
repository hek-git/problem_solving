#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int visited[101][101];

int bfs(pair<int, int> s, vector<string>& maps) {
    int life = 0;
    queue<pair<int, int>> q;
    q.push(s);
    visited[s.first][s.second] = 1;
    while (!q.empty()) {
        pair<int, int> source = q.front();
        q.pop();
        life += (maps[source.first][source.second] - '0');

        for (int i = 0; i < 4; i++) {
            int nextY = source.first + dir[i].first,
                nextX = source.second + dir[i].second;
            if (nextY < 0 || nextX < 0 || nextY >= maps.size() ||
                nextX >= maps[0].size() || visited[nextY][nextX] ||
                maps[nextY][nextX] == 'X')
                continue;
            visited[nextY][nextX] = 1;
            q.push(make_pair(nextY, nextX));
        }
    }
    return life;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (!visited[i][j] && maps[i][j] != 'X') {
                answer.push_back(bfs(make_pair(i, j), maps));
            }
        }
    }

    if (answer.size())
        sort(answer.begin(), answer.end());
    else
        answer.push_back(-1);
    return answer;
}