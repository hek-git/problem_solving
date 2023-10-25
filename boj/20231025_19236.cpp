#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int ans, level, dx[8] = {0, -1, -1, -1, 0, 1, 1, 1}, dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<vector<pair<int, int>>> map;
pair<int, int> shark, sharkPos, tmp;


// ������ �� ����� ��ġ�� �ٲٱ� ���� swap �Լ�
void swap(pair<int, int>&a, pair<int, int>& b){
    pair<int, int> tmp = a;
    a = b;
    b = tmp;
}

// 1~16�� ������� ��ġ�� ã�� �Լ�. �ش� ����Ⱑ ���ٸ� -1, -1 ��ȯ
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

// �� ����Ⱑ �̵��ؾ� �� ��ġ�� ã�� �Լ�.
// �Ű�������(������ ����, ������� ��ǥ, ����� ��ǥ)
pair<int, int> findNextPos(vector<vector<pair<int, int>>>& m, pair<int, int> pos, pair<int, int>& sharkPos) {
    int i = pos.first, j = pos.second;
    // 8������ ��� ��ȸ�ϸ�
    for (int k = 0; k < 8; k++) {
        int nextDir = (m[i][j].second - 1 + k) % 8;
        int nextX = j + dx[nextDir], nextY = i + dy[nextDir];
        // ���� ��ǥ�� �� �ְų� ������ ����� continue
        if (nextY == sharkPos.first && nextX == sharkPos.second) continue;
        if (nextX > 3 || nextX < 0 || nextY > 3 || nextY < 0) continue;
        // ����� ����, ��ǥ ����
        m[i][j].second = ++nextDir;
        pos.first = nextY;
        pos.second = nextX;
        break;
    }
    // ����� ��ǥ ��ȯ
    return pos;
}

// ������ ����(����� �̵�)�ϴ� �Լ�.
// �Ű������� ������ ����, ����� ��ǥ
vector<vector<pair<int, int>>> moveMap(vector<vector<pair<int, int>>> m, pair<int, int>& sharkPos) {
    // 1~16�� �������� �ݺ�
    for (int n = 1; n <= 16; n++) {
        // �ش� ������� ��ǥ�� ã��. ��ǥ�� -1, -1 �̶�� �������� �ʴ� ������̹Ƿ� continue
        pair<int, int> pos = findFishPos(m, n);
        if(pos.first == -1 && pos.second == -1) continue;
        // �ش� ����Ⱑ �̵��ؾ��ϴ� ������ ��ǥ�� ���ϰ� �� ���� swap��
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

// �Ű������� (���� ������ ����, ����� ����(�� ���� ������� ũ��, ����), ����� ��ǥ(y, x), �� ���� ����� ũ�� ����)
void dfs(vector<vector<pair<int, int>>> m, pair<int, int> shark, pair<int, int> sharkPos, int level){
    // ���� ū level�� ans�� �����Ѵ�.
    ans = max(ans, level);
    //cout << endl<< level << "!" << endl;
    
    // ���� ����, ����� ����, ����� ��ǥ�� ������ ���� ����
    vector<vector<pair<int, int>>> newM = moveMap(m, sharkPos);
    pair<int, int> newShark, newSharkPos;
    int newLevel;
    // for (int k = 0; k < 4; k++) {
    //     for (int l = 0; l < 4; l++) {
    //         cout << newM[k][l].first << " " << newM[k][l].second << " ";
    //     }
    //     cout << endl;
    // }

    // ����� �̵�
    for(int i = 1; i < 4; i++){
        // ���� X, Y ��ǥ�� ���� ����� �������� 1~3ĭ ���� �̵�
        int nextX = sharkPos.second + dx[shark.second - 1]*i;
        int nextY = sharkPos.first + dy[shark.second - 1]*i;
        
        // ������ ����ų� ����Ⱑ ���ٸ� continue
        if(nextX > 3 || nextX < 0 || nextY > 3 || nextY < 0 || !newM[nextY][nextX].first) continue;
        // ����� ���� -> ������� ũ��� ����
        // ����� ��ǥ -> ������� ��ǥ�� ����
        newShark.first = newM[nextY][nextX].first;
        newShark.second = newM[nextY][nextX].second;
        newSharkPos.first = nextY;
        newSharkPos.second = nextX;
        //�� �̹��� ���� ������� ũ��
        newLevel = newM[nextY][nextX].first;
        //�� ���� ������� ��ǥ�� ������ 0
        newM[nextY][nextX].first = 0;
        newM[nextY][nextX].second = 0;
        //cout << "\n���� : " << newShark.second << " " << "���� ��ǥ" << nextY << " " << nextX;
        dfs(newM, newShark, newSharkPos, level + newLevel);
        // ���� �ݺ��� ���� ������ ���� ����� ���� ����
        newM[nextY][nextX].first = newShark.first;
        newM[nextY][nextX].second = newShark.second;
    }
}

void solve(){
    // �ʱ� ���� ���� 0, 0�� ��ġ�ϰ� �ش� ��ġ�� ����⸦ ������ �ش� ������ ����.
    shark.first = map[0][0].first;
    shark.second = map[0][0].second;
    sharkPos.first = 0;
    sharkPos.second = 0;
    // ���� ������ �����󿡼� 0, ����� ���� ����
    map[0][0].first = 0;
    map[0][0].second = 0;
    level = shark.first;
    // dfs ����
    dfs(map, shark, sharkPos, level);
}

int main() {
    // �Է�
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