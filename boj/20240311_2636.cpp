#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, cnt, space, ans, map[110][110], visited[110][110];
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int bfs(pair<int, int> source){
    int space = 0;
    queue<pair<int, int>> q;
    q.push(source);
    visited[source.first][source.second] = 1;

    while(!q.empty()){
        space++;
        pair<int, int> s = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int next_y = s.first + dir[i].first;
            int next_x = s.second + dir[i].second;
            if(next_y < 0 || next_x < 0 || next_y >= N || next_x >= M || visited[next_y][next_x] || map[next_y][next_x]) continue;
            q.push(make_pair(next_y, next_x));
            visited[next_y][next_x] = 1;
        }

    }
    return space;

}

void melt(){
    vector<pair<int, int>> cheese;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j]) {
                for(int k = 0; k < 4; k++){
                    int next_y = i + dir[k].first;
                    int next_x = j + dir[k].second;
                    if(visited[next_y][next_x]) cheese.push_back(make_pair(i, j));
                }
            }
        }
    }

    for(int i = 0; i < cheese.size(); i++){
        map[cheese[i].first][cheese[i].second] = 0;
    }
}

int countCheese(){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j]) cnt++;
        }
    }
    return cnt;
}

void initVisited(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visited[i][j] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    space = N * M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    ans = countCheese();

    while(true){
        if(bfs(make_pair(0, 0)) == space) break;
        ans = countCheese();
        melt();
        initVisited();
        cnt++;
    }
    cout << cnt << endl << ans;

}