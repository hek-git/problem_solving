#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int visited[101][101];
pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(vector<vector<int>>& maps){
    queue<pair<int, int>> q;
    int n = maps.size()- 1, m = maps[0].size() - 1;
    q.push(make_pair(0, 0));
    visited[0][0] = 1;

    while(!q.empty()){
        pair<int, int> s = q.front();
        q.pop();

        if(s.first == n && s.second == m) return visited[s.first][s.second];

        for(int i = 0; i < 4; i++){
            int nextY = s.first + dir[i].first;
            int nextX = s.second + dir[i].second;
            if(nextY < 0 || nextX < 0 || nextY > n || nextX > m || visited[nextY][nextX] || !maps[nextY][nextX]) continue;
            visited[nextY][nextX] = visited[s.first][s.second] + 1;
            q.push(make_pair(nextY, nextX)); 
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps) {
    return bfs(maps);
}