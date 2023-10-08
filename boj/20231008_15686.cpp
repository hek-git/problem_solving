#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N, M, ans = 100000000, map[51][51];
vector<pair<int, int>> chicken, house, choose;

int distance(pair<int, int> s, pair<int, int> d) { return abs(d.first - s.first) + abs(d.second - s.second); }

int urbanChickenDistance(vector<pair<int, int>>& chicken) {
    int totalDistance = 0;
    for (int i = 0; i < house.size(); i++) {
        int d = 101;
        for (int j = 0; j < chicken.size(); j++) {
            d = min(d, distance(house[i], chicken[j]));
        }
        totalDistance += d;
    }
    return totalDistance;
}

void solve(int idx) {
    if (choose.size() == M) {
        ans = min(urbanChickenDistance(choose), ans);
        return;
    }
    for (int i = idx; i < chicken.size(); i++) {
        choose.push_back(chicken[i]);
        solve(i + 1);
        choose.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) chicken.push_back(make_pair(i, j));
            if (map[i][j] == 1) house.push_back(make_pair(i, j));
        }
    }
    solve(0);
    cout << ans;
}