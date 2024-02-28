#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// 일반적인 bfs 풀이
int bfs(int m, int n, int color, pair<int, int> source, vector<vector<int>>& visited, vector<vector<int>>& picture) {
    queue<pair<int, int>> q;
    pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int territory = 0;
    q.push(source);
    visited[source.first][source.second] = 1;

    while (!q.empty()) {
        pair<int, int> s = q.front();
        territory++;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = s.first + dir[i].first;
            int nextX = s.second + dir[i].second;
            if (nextY < 0 || nextX < 0 || nextY >= m || nextX >= n || picture[nextY][nextX] != color || !picture[nextY][nextX] || visited[nextY][nextX]) continue;
            q.push(make_pair(nextY, nextX));
            visited[nextY][nextX] = 1;
        }
        
    }
    return territory;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
    vector<vector<int>> visited(m, vector<int>(n, 0));

    for (int i = 0; i < picture.size(); i++) {
        for (int j = 0; j < picture[i].size(); j++) {
            if(picture[i][j] && !visited[i][j]){
                pair<int, int> p = make_pair(i, j);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, bfs(m, n, picture[i][j], p, visited, picture));
            }
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}