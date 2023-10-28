#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// visited의 값 0 : 방문하지 않음, 1 : 벽을 부수지 않은 상태에서 방문함, 2 : 벽을 부순 상태로 방문함
int N, M, ans = -1, map[1001][1001], visited[1001][1001];
pair<int, int> d[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void bfs(){
    queue<pair<pair<int,int>, pair<bool, int>>> q;
    q.push(make_pair(make_pair(1, 1), make_pair(true, 1)));
    visited[1][1] = 1;

    while(!q.empty()){
        pair<int, int> s, state;
        s = q.front().first;
        state = q.front().second;
        q.pop();

        
        if(s.first == N && s.second == M){
            ans = state.second;
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int nextX = s.second + d[i].second;
            int nextY = s.first + d[i].first;

            if(nextY > N || nextX > M || nextY < 1 || nextX < 1) continue;

            // 벽이 있는데 부술 수 없는 경우
            if (map[nextY][nextX] && state.first == false) continue;

            // 벽이 있는데 부술 수 있는 경우
            else if (map[nextY][nextX] && state.first) {
                // 이미 1(벽을 부수지 않은)이거나 2(벽을 부순 상태)로 방문했다면 q에 추가하지 않는다
                // 아니라면 방문하지 않았으므로 q에 추가하고 부순 상태로 방문(2)표시
                if(!visited[nextY][nextX]){
                    q.push(make_pair(make_pair(nextY, nextX), make_pair(false, state.second + 1)));
                    visited[nextY][nextX] = 2;
                }
            }

            // 벽이 없고 부술 수 없는 경우
            else if (state.first == false) {
                // 이미 1(벽을 부수지 않은)이거나 2(벽을 부순 상태)로 방문했다면 q에 추가하지 않는다
                // 아니라면 방문하지 않았으므로 q에 추가하고 부순 상태로 방문(2)표시
                if(!visited[nextY][nextX]){
                    q.push(make_pair(make_pair(nextY, nextX), make_pair(state.first, state.second + 1)));
                    visited[nextY][nextX] = 2;
                }
            }

            // 벽이 없고 부술 수 있는 경우
            else {
                // 이미 1인(벽을 부수지 않은) 상태로 방문했다면 q에 추가하지 않는다
                // 아니라면 기존에 방문하지 않았거나 2인 상태로 방문한 것이고 이는 더 효율적으로 온 경우이므로 부수지 않은 상태로 방문(1) 표시
                if(visited[nextY][nextX] != 1){
                    q.push(make_pair(make_pair(nextY, nextX), make_pair(state.first, state.second + 1)));
                    visited[nextY][nextX] = 1;
                }
            }
        }
        
    }
}

int main() {

    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        string tmp;
        cin >> tmp;
        for(int j = 1; j <= M; j++){
            map[i][j] = tmp[j-1] - '0';
        }
    }
    bfs();
    cout << ans;
}