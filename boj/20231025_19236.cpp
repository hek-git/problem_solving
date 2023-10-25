#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int ans, level, dx[8] = {0, -1, -1, -1, 0, 1, 1, 1}, dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<vector<pair<int, int>>> map;
pair<int, int> shark, sharkPos, tmp;


// 공간의 두 물고기 위치를 바꾸기 위한 swap 함수
void swap(pair<int, int>&a, pair<int, int>& b){
    pair<int, int> tmp = a;
    a = b;
    b = tmp;
}

// 1~16번 물고기의 위치를 찾는 함수. 해당 물고기가 없다면 -1, -1 반환
pair<int, int> findFishPos(vector<vector<pair<int, int>>>& m, int n){
    pair<int, int> pos;
    pos.first = pos.second = -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (m[i][j].first == n) {
                pos.first = i, pos.second = j;
                return pos;
            }
        }
    }
    return pos;
}

// 각 물고기가 이동해야 할 위치를 찾는 함수.
// 매개변수는(공간의 상태, 물고기의 좌표, 상어의 좌표)
pair<int, int> findNextPos(vector<vector<pair<int, int>>>& m, pair<int, int> pos, pair<int, int>& sharkPos) {
    int i = pos.first, j = pos.second;
    // 8방향을 모두 조회하며
    for (int k = 0; k < 8; k++) {
        int nextDir = (m[i][j].second - 1 + k) % 8;
        int nextX = j + dx[nextDir], nextY = i + dy[nextDir];
        // 다음 좌표에 상어가 있거나 범위를 벗어나면 continue
        if (nextY == sharkPos.first && nextX == sharkPos.second) continue;
        if (nextX > 3 || nextX < 0 || nextY > 3 || nextY < 0) continue;
        // 물고기 방향, 좌표 설정
        m[i][j].second = ++nextDir;
        pos.first = nextY;
        pos.second = nextX;
        break;
    }
    // 물고기 좌표 반환
    return pos;
}

// 공간을 변경(물고기 이동)하는 함수.
// 매개변수는 공간의 상태, 상어의 좌표
vector<vector<pair<int, int>>> moveMap(vector<vector<pair<int, int>>> m, pair<int, int>& sharkPos) {
    // 1~16번 물고기까지 반복
    for (int n = 1; n <= 16; n++) {
        // 해당 물고기의 좌표를 찾음. 좌표가 -1, -1 이라면 존재하지 않는 물고기이므로 continue
        pair<int, int> pos = findFishPos(m, n);
        if(pos.first == -1 && pos.second == -1) continue;
        // 해당 물고기가 이동해야하는 공간의 좌표를 구하고 두 값을 swap함
        pair<int, int> nextPos = findNextPos(m, pos, sharkPos);
        swap(m[pos.first][pos.second], m[nextPos.first][nextPos.second]);
        // cout << endl;
        // for (int k = 0; k < 4; k++) {
        //     for (int l = 0; l < 4; l++) {
        //         cout << m[k][l].first << " " << m[k][l].second << " ";
        //     }
        //     cout << endl;
        // }
    }
    return m;
}

// 매개변수는 (현재 공간의 상태, 상어의 상태(상어가 먹은 물고기의 크기, 방향), 상어의 좌표(y, x), 상어가 먹은 물고기 크기 누적)
void dfs(vector<vector<pair<int, int>>> m, pair<int, int> shark, pair<int, int> sharkPos, int level){
    // 가장 큰 level을 ans에 저장한다.
    ans = max(ans, level);
    //cout << endl<< level << "!" << endl;
    
    // 기존 공간, 상어의 상태, 상어의 좌표를 복사할 변수 선언
    vector<vector<pair<int, int>>> newM = moveMap(m, sharkPos);
    pair<int, int> newShark, newSharkPos;
    int newLevel;
    // for (int k = 0; k < 4; k++) {
    //     for (int l = 0; l < 4; l++) {
    //         cout << newM[k][l].first << " " << newM[k][l].second << " ";
    //     }
    //     cout << endl;
    // }

    // 상어의 이동
    for(int i = 1; i < 4; i++){
        // 다음 X, Y 좌표는 현재 상어의 방향으로 1~3칸 까지 이동
        int nextX = sharkPos.second + dx[shark.second - 1]*i;
        int nextY = sharkPos.first + dy[shark.second - 1]*i;
        
        // 범위를 벗어나거나 물고기가 없다면 continue
        if(nextX > 3 || nextX < 0 || nextY > 3 || nextY < 0 || !newM[nextY][nextX].first) continue;
        // 상어의 상태 -> 물고기의 크기와 방향
        // 상어의 좌표 -> 물고기의 좌표로 변경
        newShark.first = newM[nextY][nextX].first;
        newShark.second = newM[nextY][nextX].second;
        newSharkPos.first = nextY;
        newSharkPos.second = nextX;
        //상어가 이번에 먹은 물고기의 크기
        newLevel = newM[nextY][nextX].first;
        //상어가 먹은 물고기의 좌표와 방향은 0
        newM[nextY][nextX].first = 0;
        newM[nextY][nextX].second = 0;
        //cout << "\n방향 : " << newShark.second << " " << "다음 좌표" << nextY << " " << nextX;
        dfs(newM, newShark, newSharkPos, level + newLevel);
        // 다음 반복때 사용될 공간을 위해 물고기 상태 원복
        newM[nextY][nextX].first = newShark.first;
        newM[nextY][nextX].second = newShark.second;
    }
}

void solve(){
    // 초기 설정 상어는 0, 0에 위치하고 해당 위치의 물고기를 먹으며 해당 방향을 가짐.
    shark.first = map[0][0].first;
    shark.second = map[0][0].second;
    sharkPos.first = 0;
    sharkPos.second = 0;
    // 먹힌 물고기는 공간상에서 0, 상어의 레벨 증가
    map[0][0].first = 0;
    map[0][0].second = 0;
    level = shark.first;
    // dfs 실행
    dfs(map, shark, sharkPos, level);
}

int main() {
    // 입력
    for (int i = 0; i < 4; i++) {
        vector<pair<int, int>> v;
        for (int j = 0; j < 4; j++) {
            cin >> tmp.first >> tmp.second;
            v.push_back(tmp);
        }
        map.push_back(v);
    }
    solve();
    cout << ans;
}