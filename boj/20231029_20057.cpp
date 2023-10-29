#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, ans, cnt, d, len = 1, map[500][500];
double ratio[9] = {0.01, 0.01, 0.07, 0.07, 0.02, 0.02, 0.1, 0.1, 0.05};
pair<int, int> storm, dir[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
pair<int, int> sand[4][10] = {{{-1, 1}, {1, 1}, {-1, 0}, {1, 0}, {-2, 0}, {2, 0}, {-1, -1}, {1, -1}, {0, -2}, {0, -1}},
                             {{-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {0, -2}, {0, 2}, {1, -1}, {1, 1}, {2, 0}, {1, 0}},
                             {{-1, -1}, {1, -1}, {-1, 0}, {1, 0}, {-2, 0}, {2, 0}, {-1, 1}, {1, 1}, {0, 2}, {0, 1}},
                             {{1, -1}, {1, 1}, {0, -1}, {0, 1}, {0, -2}, {0, 2}, {-1, -1}, {-1, 1}, {-2, 0}, {-1, 0}}};

// void print() {
//     for (int i = 1; i <= N; i++) {
//         for (int j = 1; j <= N; j++) {
//             cout << map[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

void moveSand(pair<int, int>& s, int d) {
    pair<int, int> y, a;
    int totalSand, leftSand;
    y.first = s.first + dir[d].first;
    y.second = s.second + dir[d].second;
    totalSand = leftSand = map[y.first][y.second];

    for (int i = 0; i < 10; i++) {
        int nextY, nextX;
        nextY = y.first + sand[d][i].first;
        nextX = y.second + sand[d][i].second;
        
        if(nextY > N || nextX > N || nextY < 1 || nextX < 1){
            if (i == 9) ans += leftSand;
            else ans += (int)(totalSand * ratio[i]);
            leftSand -= (int)(totalSand * ratio[i]);;
            continue;
        }
        if (i == 9)
            map[nextY][nextX] += leftSand;
        else {
            map[nextY][nextX] += (int)(totalSand * ratio[i]);
            leftSand -= (int)(totalSand * ratio[i]);
        }
    }
    map[y.first][y.second] = 0;
}

void solve() {
    while (true) {
        if (cnt == 2) {
            len++;
            cnt = 0;
        }
        for (int i = 0; i < len; i++) {
            if (storm.first == 1 && storm.second == 1) return;
            moveSand(storm, d);
            //cout << "ÆøÇ³ : " << storm.first << " " << storm.second << '\n';
            storm.first += dir[d].first;
            storm.second += dir[d].second;
            //print();
        }
        
        cnt++;
        d = (d + 1) % 4;
    }
}

int main() {
    cin >> N;
    storm.first = storm.second = N/2 + 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
    solve();
    cout << ans;
}