#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, ans, check[26];
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> map;

void dfs(pair<int, int> s, int cnt) {
    for (int i = 0; i < 4; i++) {
        int next_y = s.first + dir[i].first;
        int next_x = s.second + dir[i].second;
        if (next_y < 0 || next_x < 0 || next_y >= R || next_x >= C) continue;
        int idx = map[next_y][next_x] - 'A';
        if (!check[idx]) {
            check[idx] = 1;
            dfs(make_pair(next_y, next_x), cnt + 1);
            check[idx] = 0;
        }
    }
    ans = max(ans, cnt);
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }
    check[map[0][0] - 'A'] = 1;
    dfs(make_pair(0, 0), 1);
    cout << ans;
}