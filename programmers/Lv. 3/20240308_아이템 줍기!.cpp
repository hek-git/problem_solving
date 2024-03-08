#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int map[52][52][4], visited[52][52];
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool check(pair<int, int> s, int d){
    int nextX = s.first + dir[d].first;
    int nextY = s.second + dir[d].second;
    if((map[s.first][s.second][(d + 1) % 4] && map[s.first][s.second][(d + 3) % 4]) && (map[nextX][nextY][(d + 1) % 4] && map[nextX][nextY][(d + 3) % 4])){
        pair<int, int> l = make_pair(s.first + dir[(d + 1) % 4].first, s.second + dir[(d + 1) % 4].second);
        pair<int, int> r = make_pair(s.first + dir[(d + 3) % 4].first, s.second + dir[(d + 3) % 4].second);
        if(map[l.first][l.second][d] && map[r.first][r.second][d]) return false;
        return true;
    }
    return true;
}

int bfs(pair<int, int> source, pair<int, int> destination){
    int answer = 0;
    queue<pair<int, int>> q;
    q.push(source);
    visited[source.first][source.second] = 1;

    while(!q.empty()){
        pair<int, int> s = q.front();
        q.pop();

        if(s.first == destination.first && s.second == destination.second) break;

        for(int i = 0; i < 4; i++){
            int nextX = s.first + dir[i].first;
            int nextY = s.second + dir[i].second;
            if(nextX < 0 || nextY < 0 || visited[nextX][nextY] || !check(s, i) || !(map[s.first][s.second][i])) continue;
            q.push(make_pair(nextX, nextY));
            visited[nextX][nextY] = visited[s.first][s.second] + 1;
        }
    }
    return visited[destination.first][destination.second] - 1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    pair<int, int> s, d;
    s = make_pair(characterX, characterY);
    d = make_pair(itemX, itemY);

    for(int i = 0; i < rectangle.size(); i++){
        int x1 = rectangle[i][0], y1 = rectangle[i][1];
        int x2 = rectangle[i][2], y2 = rectangle[i][3];
        
        for(int i = x1; i <= x2; i++){
            for(int j = y1; j < y2; j++){
                map[i][j][1] = 1;
                map[i][j + 1][3] = 1;
            }
        }

        for(int i = y1; i <= y2; i++){
            for(int j = x1; j < x2; j++){
                map[j][i][2] = 1;
                map[j + 1][i][0] = 1;
            }
        }
    }

    return bfs(s, d);
}