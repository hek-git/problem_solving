#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[101][101];
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// visited √ ±‚»≠
void initVisited(){
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            visited[i][j] = 0;
        }
    }
}

// bfs 
int bfs(vector<string> map, pair<int, int>& s, pair<int, int> d, int n, int m){
    int cost = 0;
    queue<pair<int, int>> q;    
    q.push(s);
    visited[s.first][s.second] = 1;

    while(!q.empty()){
        pair<int, int> source = q.front();
        q.pop();        
        if(source.first == d.first && source.second == d.second){
            return visited[source.first][source.second] - 1;
        }
        for(int i = 0; i < 4; i++){
            int nextY = source.first + dir[i].first;
            int nextX = source.second + dir[i].second;
            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= m || visited[nextY][nextX]) continue;
            if(map[nextY][nextX] == 'X' ) continue;
            visited[nextY][nextX] = visited[source.first][source.second] + 1;
            q.push(make_pair(nextY, nextX));
        }

    }
    return 0;
}

int solution(vector<string> maps) {
    int answer = -1;
    pair<int, int> start, lever, finish;
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].size(); j++){
            if(maps[i][j] == 'S'){
                start.first = i;
                start.second =j;
            }
            if(maps[i][j] == 'L'){
                lever.first = i;
                lever.second = j;
            }
            if(maps[i][j] == 'E'){
                finish.first = i;
                finish.second = j;
            }
        }
    }
    int a = bfs(maps, start, lever, maps.size(), maps[0].size());
    initVisited();
    int b = bfs(maps, lever, finish, maps.size(), maps[0].size());
    if(a && b) answer = a + b;
    return answer;
}