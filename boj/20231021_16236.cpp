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

// visited 배열 초기화 함수
void initVisited(){
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[i][j] = 0;
        }
    }
}

// source부터 bfs를 실행하는 함수. dest를 찾으면 거리를 반환하고 못찾는다면 -1을 반환한다.
int bfs(pair<int, int>& source, pair<int, int> dest) {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(source, 0));
    visited[source.first][source.second] = 1;
    while (!q.empty()) {    
        pair<pair<int, int>, int> info = q.front();
        pair<int, int> s = info.first;
        int cost = info.second;
        q.pop();
        // dest의 좌표라면 cost(거리)를 반환한다.
        if (s.first == dest.first && s.second == dest.second){
            return cost;
        }
        for (int i = 0; i < 4; i++) {
            int nextX = s.second + dx[i];
            int nextY = s.first + dy[i];
            // visited거나 좌표를 벗어났거나 상어의 크기보다 큰 물고기인 경우 continue
            if (visited[nextY][nextX]) continue;
            if (nextX > N || nextX < 1 || nextY > N || nextY < 1 || map[nextY][nextX] > level) continue;
            visited[nextY][nextX] = 1;
            pair<int, int> next = make_pair(nextY, nextX);
            q.push(make_pair(next, cost + 1));
        }
    }
    // q가 비어있어서 나온 경우(dest까지 도달하지 못한 경우)이므로 -1 반환.
    return -1;
}

// 먹을 수 있는 후보 물고기들을 찾는다.
void findEdibleFish() {
    candidateFish.clear();
    dist.clear();

    // map을 순회하며 후보 물고기들을 찾는다.
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] != 0 && map[i][j] < level) {
                // bfs를 실행하고 vistied 배열 초기화.
                int d = bfs(shark, make_pair(i, j));
                initVisited();
                // 거리가 -1 이라면 해당 물고기를 먹을수는 있으나 도달하지 못하므로 후보에 추가하지않는다.
                if(d != -1) {
                    candidateFish.push_back(make_pair(i, j));
                    dist.push_back(d);
                }
            }
        }
    }
}

// 후보 물고기들을 토대로 실제로 먹을 물고기를 찾는 함수. 하나의 물고기 좌표, 거리가 반환된다.
pair<pair<int, int>, int> findFish() {
    int min_distance;
    fish.clear();
    // 후보 물고기가 2개 이상이라면 가장 가까운 거리의 물고기를 찾는다. 
    if (candidateFish.size() > 1) {
        min_distance = *min_element(dist.begin(), dist.end());
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] == min_distance) fish.push_back(candidateFish[i]);
        }
        // 가장 가까운 거리의 물고기도 2개 이상이라면 좌표를 정렬(왼쪽 위)하여 실제 먹을 물고기의 위치, 거리 반환.
        if (fish.size() > 1) {
            sort(fish.begin(), fish.end());
        }
        return make_pair(fish[0], min_distance);
    } else // 후보 물고기가 하나라면 해당 물고기 위치, 거리 반환.
        return make_pair(candidateFish[0], dist[0]);
}

// 물고기를 먹고 변경 사항 적용하는 함수(물고기 삭제, 상어 위치 이동, 상어 크기 변경 등등)
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
        // findEdibleFish 함수로 먹을 수 있는 물고기들을 찾음
        findEdibleFish();
        // 후보 물고기가 없다면 solve함수 종료
        if (candidateFish.size() == 0) return;
        // findFish 함수로 실제로 먹을 물고기를 찾음
        pair<pair<int, int>, int> fishToEat = findFish();
        // 물고기를 먹는 함수
        eatFish(fishToEat);
    }
}

int main() {
    cin >> N;
    // 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            // 상어일 경우 상어 좌표 기억, 해당 위치는 0
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