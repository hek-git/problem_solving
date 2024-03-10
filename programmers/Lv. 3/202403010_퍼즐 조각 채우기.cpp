#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// check_piece는 테이블에 넣은 퍼즐 조각을 표시하기 위한 배열
// (퍼즐 조각은 한번만 사용할 수 있기 때문)
int visited[51][51], check_piece[1500];
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// visited 배열 초기화
void initVisited() {
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            visited[i][j] = 0;
        }
    }
}

// 연결된 퍼즐 조각 좌표를 반환하는 bfs
// return_code를 통해 퍼즐의 절대 좌표와 상대 좌표를 반환할 수 있음 
vector<pair<int, int>> bfs(int n, vector<vector<int>>& map,
                           pair<int, int> source, int return_code) {
    vector<pair<int, int>> relative_pos, implicit_pos;
    pair<int, int> pos;
    queue<pair<int, int>> q;
    q.push(source);
    q.push(pos);
    visited[source.first][source.second] = 1;

    while (!q.empty()) {
        pair<int, int> s = q.front(), pos_s;
        q.pop();
        pos_s = q.front();
        q.pop();
        relative_pos.push_back(pos_s);
        implicit_pos.push_back(s);

        for (int i = 0; i < 4; i++) {
            int next_y = s.first + dir[i].first;
            int next_x = s.second + dir[i].second;
            if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= n ||
                visited[next_y][next_x] || !map[next_y][next_x])
                continue;
            int next_rel_y = pos_s.first + dir[i].first;
            int next_rel_x = pos_s.second + dir[i].second;
            q.push(make_pair(next_y, next_x));
            q.push(make_pair(next_rel_y, next_rel_x));
            visited[next_y][next_x] = 1;
        }
    }
    if (return_code == 1) return relative_pos;
    return implicit_pos;
}

// 회전 시킨 퍼즐 조각의 좌표들을 반환하는 함수
vector<vector<pair<int, int>>> rotate(vector<vector<pair<int, int>>>& piece) {
    vector<vector<pair<int, int>>> rotate_piece;
    // 현재 상태 추가 후 왼쪽으로 90도씩 회전(4회 반복)
    for (int n = 0; n < piece.size(); n++) {
        for (int i = 0; i < 4; i++) {
            rotate_piece.push_back(piece[n]);
            for (int j = 0; j < piece[n].size(); j++) {
                int tmp = piece[n][j].first;
                piece[n][j].first = piece[n][j].second;
                piece[n][j].second = -tmp;
            }
        }
    }
    return rotate_piece;
}

// 빈 공간에 알맞는 퍼즐 조각이 있는지 확인하는 함수
int check(vector<pair<int, int>>& space, vector<vector<pair<int, int>>>& piece, int n) {
    int answer = 0; 
    for (int i = 0; i < piece.size(); i++) {
        if (space.size() == piece[i].size() && equal(space.begin(), space.end(), piece[i].begin())) {
            check_piece[n]++;
            return space.size();
        }
    }
    return 0;
}

// 모든 빈 공관과 모든 퍼즐 조각을 비교하여 채울 수 있는 퍼즐 조각 칸을 계산하는 함수
int solution(vector<vector<pair<int, int>>>& space,
             vector<vector<vector<pair<int, int>>>>& piece) {
    int cnt = 0;
    for(int i = 0; i < space.size(); i++) sort(space[i].begin(), space[i].end());
    for(int i = 0; i < piece.size(); i++){
        for(int j = 0; j < piece[i].size(); j++){
            sort(piece[i][j].begin(), piece[i][j].end());
        }
    }    

    for (int n = 0; n < space.size(); n++) {
        for (int i = 0; i < piece.size(); i++){
            if(check_piece[i]) continue;
            int tmp = check(space[n], piece[i], i);
            if(tmp != 0) {
                cnt += tmp;
                break;
            }
        }
    }
    return cnt;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    vector<vector<vector<pair<int, int>>>> piece;
    vector<vector<pair<int, int>>> space;

    // bfs 재사용을 위해 game_board의 조건도 table과 동일하게 설정 (1을 빈 칸, 0을 채워진 칸으로 표시)
    for (int i = 0; i < game_board.size(); i++)
        for (int j = 0; j < game_board[0].size(); j++)
            game_board[i][j] = !game_board[i][j];

    // bfs를 통해 table로부터 퍼즐 조각들의 상대 좌표를 구함
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[0].size(); j++) {
            if (!visited[i][j] && table[i][j]) {
                vector<vector<pair<int, int>>> tmp_piece;
                vector<pair<int, int>> p =
                    bfs(table.size(), table, make_pair(i, j), 0);
         
                // 해당 퍼즐 조각을 접근할 수 있는 모든 칸에서 bfs를 하여 모든 경우의 상대 좌표를 구한다
                // (시작 좌표에 따라 상대 좌표가 달라지기 때문)    
                for (int k = 0; k < p.size(); k++) {
                    for (int n = 0; n < p.size(); n++) visited[p[n].first][p[n].second] = 0;
                    tmp_piece.push_back(bfs(table.size(), table, p[k], 1));
                }

                // 위에서 구한 모든 퍼즐 조각 좌표들을 roatate 함수를 통해 회전시키고 이를 piece 배열에 넣는다.
                piece.push_back(rotate(tmp_piece));
            }
        }
    }

    // 빈 공간을 구하는 bfs를 해야하기 때문에 visited 초기화
    initVisited();

    // bfs를 통해 game_board로부터 빈 공간의 상대 좌표를 구함.
    for (int i = 0; i < game_board.size(); i++) {
        for (int j = 0; j < game_board[0].size(); j++) {
            if (!visited[i][j] && game_board[i][j])
                space.push_back(
                    bfs(game_board.size(), game_board, make_pair(i, j), 1));
        }
    }
    
    // 구한 빈 공간 좌표와 모든 퍼즐 조각 좌표를 이용하여 답 구한다.
    return solution(space, piece);
}