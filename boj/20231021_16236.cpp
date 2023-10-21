#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, ans, map[21][21], visited[21][21], dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
int level = 2, leftFish = 2;
pair<int, int> shark;
vector<pair<int, int>> fish, candidateFish;
vector<int> dist;

// visited �迭 �ʱ�ȭ �Լ�
void initVisited(){
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[i][j] = 0;
        }
    }
}

// source���� bfs�� �����ϴ� �Լ�. dest�� ã���� �Ÿ��� ��ȯ�ϰ� ��ã�´ٸ� -1�� ��ȯ�Ѵ�.
int bfs(pair<int, int>& source, pair<int, int> dest) {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(source, 0));
    visited[source.first][source.second] = 1;
    while (!q.empty()) {    
        pair<pair<int, int>, int> info = q.front();
        pair<int, int> s = info.first;
        int cost = info.second;
        q.pop();
        // dest�� ��ǥ��� cost(�Ÿ�)�� ��ȯ�Ѵ�.
        if (s.first == dest.first && s.second == dest.second){
            return cost;
        }
        for (int i = 0; i < 4; i++) {
            int nextX = s.second + dx[i];
            int nextY = s.first + dy[i];
            // visited�ų� ��ǥ�� ����ų� ����� ũ�⺸�� ū ������� ��� continue
            if (visited[nextY][nextX]) continue;
            if (nextX > N || nextX < 1 || nextY > N || nextY < 1 || map[nextY][nextX] > level) continue;
            visited[nextY][nextX] = 1;
            pair<int, int> next = make_pair(nextY, nextX);
            q.push(make_pair(next, cost + 1));
        }
    }
    // q�� ����־ ���� ���(dest���� �������� ���� ���)�̹Ƿ� -1 ��ȯ.
    return -1;
}

// ���� �� �ִ� �ĺ� �������� ã�´�.
void findEdibleFish() {
    candidateFish.clear();
    dist.clear();

    // map�� ��ȸ�ϸ� �ĺ� �������� ã�´�.
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] != 0 && map[i][j] < level) {
                // bfs�� �����ϰ� vistied �迭 �ʱ�ȭ.
                int d = bfs(shark, make_pair(i, j));
                initVisited();
                // �Ÿ��� -1 �̶�� �ش� ����⸦ �������� ������ �������� ���ϹǷ� �ĺ��� �߰������ʴ´�.
                if(d != -1) {
                    candidateFish.push_back(make_pair(i, j));
                    dist.push_back(d);
                }
            }
        }
    }
}

// �ĺ� �������� ���� ������ ���� ����⸦ ã�� �Լ�. �ϳ��� ����� ��ǥ, �Ÿ��� ��ȯ�ȴ�.
pair<pair<int, int>, int> findFish() {
    int min_distance;
    fish.clear();
    // �ĺ� ����Ⱑ 2�� �̻��̶�� ���� ����� �Ÿ��� ����⸦ ã�´�. 
    if (candidateFish.size() > 1) {
        min_distance = *min_element(dist.begin(), dist.end());
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] == min_distance) fish.push_back(candidateFish[i]);
        }
        // ���� ����� �Ÿ��� ����⵵ 2�� �̻��̶�� ��ǥ�� ����(���� ��)�Ͽ� ���� ���� ������� ��ġ, �Ÿ� ��ȯ.
        if (fish.size() > 1) {
            sort(fish.begin(), fish.end());
        }
        return make_pair(fish[0], min_distance);
    } else // �ĺ� ����Ⱑ �ϳ���� �ش� ����� ��ġ, �Ÿ� ��ȯ.
        return make_pair(candidateFish[0], dist[0]);
}

// ����⸦ �԰� ���� ���� �����ϴ� �Լ�(����� ����, ��� ��ġ �̵�, ��� ũ�� ���� ���)
void eatFish(pair<pair<int, int>, int>& fish) {
    pair<int, int> fishPos = fish.first;
    int cost = fish.second;
    map[fishPos.first][fishPos.second] = 0;
    shark.first = fishPos.first;
    shark.second = fishPos.second;
    ans += cost;
    leftFish--;
    if (leftFish == 0) {
        level++;
        leftFish = level;
    }
}

void solve() {
    while (true) {
        // findEdibleFish �Լ��� ���� �� �ִ� �������� ã��
        findEdibleFish();
        // �ĺ� ����Ⱑ ���ٸ� solve�Լ� ����
        if (candidateFish.size() == 0) return;
        // findFish �Լ��� ������ ���� ����⸦ ã��
        pair<pair<int, int>, int> fishToEat = findFish();
        // ����⸦ �Դ� �Լ�
        eatFish(fishToEat);
    }
}

int main() {
    cin >> N;
    // �Է�
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            // ����� ��� ��� ��ǥ ���, �ش� ��ġ�� 0
            if (map[i][j] == 9) {
                map[i][j] = 0;
                shark.first = i;
                shark.second = j;
            }
        }
    }
    solve();
    cout << ans;
}