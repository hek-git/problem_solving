#include <iostream>
#include <vector>

using namespace std;

int N, M, map[51][51], dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, -1, -1, -1, 0, 1, 1, 1}, ans;
int diagonalX[4] = {-1, 1, 1, -1}, diagonalY[4] = {-1, -1, 1, 1};
vector<pair<int, int>> cloud, dir;
pair<int, int> p;

bool isCloud(int i, int j) {
    for (int k = 0; k < cloud.size(); k++) {
        if (cloud[k].first == i && cloud[k].second == j) return true;
    }
    return false;
}

void moveCloud(int n) {
    for (int i = 0; i < dir[n].second; i++) {
        for (int j = 0; j < cloud.size(); j++) {
            int nextX = cloud[j].second + dx[dir[n].first - 1];
            int nextY = cloud[j].first + dy[dir[n].first - 1];
            if (nextX > N)
                nextX = 1;
            else if (nextX < 1)
                nextX = N;
            if (nextY > N)
                nextY = 1;
            else if (nextY < 1)
                nextY = N;
            cloud[j].second = nextX;
            cloud[j].first = nextY;
        }
    }
}

void increaseWater() {
    for (int i = 0; i < cloud.size(); i++) {
        map[cloud[i].first][cloud[i].second]++;
    }
}

void magic() {
    vector<int> increase;
    for (int i = 0; i < cloud.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            int nextX = cloud[i].second + diagonalX[j];
            int nextY = cloud[i].first + diagonalY[j];
            if (nextX > N || nextX < 1 || nextY > N || nextY < 1) continue;
            if (map[nextY][nextX]) cnt++;
        }
        increase.push_back(cnt);
    }
    for (int i = 0; i < cloud.size(); i++) {
        map[cloud[i].first][cloud[i].second] += increase[i];
    }
}

void newCloud() {
    vector<pair<int, int>> tmpCloud;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] >= 2 && !isCloud(i, j)) {
                map[i][j] -= 2;
                tmpCloud.push_back(make_pair(i, j));
            }
        }
    }
    cloud = tmpCloud;
}

void printM(){
    for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
}
void solve() {
    for (int i = 0; i < dir.size(); i++) {
        moveCloud(i);
        increaseWater();
        magic();
        newCloud();
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> p.first >> p.second;
        dir.push_back(p);
    }
    cloud.push_back(make_pair(N, 1));
    cloud.push_back(make_pair(N, 2));
    cloud.push_back(make_pair(N - 1, 1));
    cloud.push_back(make_pair(N - 1, 2));

    solve();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += map[i][j];
        }
    }
    cout << ans;
}