#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[100][100];
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int bfs(vector<string>& board, pair<int, int> source){
    queue<pair<int, int>> q;
    visited[source.first][source.second] = 1;
    q.push(source);

    while(!q.empty()){
        pair<int, int> s = q.front();
        q.pop();
        if(board[s.first][s.second] == 'G') return visited[s.first][s.second] - 1;
        for(int i = 0; i < 4; i++){
            int nextX = s.second;
            int nextY = s.first;
            while(true){
                if(nextX + dir[i].second < 0 || nextY + dir[i].first < 0 || nextX + dir[i].second >= board[0].size() || nextY + dir[i].first >= board.size()) break;
                if(board[nextY + dir[i].first][nextX + dir[i].second] == 'D') break;
                nextX += dir[i].second;
                nextY += dir[i].first;
            }
            if(!visited[nextY][nextX]){
                visited[nextY][nextX] = visited[s.first][s.second] + 1;
                q.push(make_pair(nextY, nextX));
            }
        }
    }

    return -1;
}

int solution(vector<string> board) {
    pair<int, int> source;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] == 'R'){
                source.first = i;
                source.second = j;
            }
        }
    }
    return bfs(board, source);
}