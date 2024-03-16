#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, answer;
char map[7][7];
vector<pair<int, int>> teacher, list, obstacle;
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool check() {
    for (int i = 0; i < obstacle.size(); i++)
        map[obstacle[i].first][obstacle[i].second] = 'O';

    for (int i = 0; i < teacher.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int next_y = teacher[i].first + dir[j].first;
            int next_x = teacher[i].second + dir[j].second;
            while (true) {
                if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N ||
                    map[next_y][next_x] == 'O')
                    break;
                if (map[next_y][next_x] == 'S') {
                    for (int i = 0; i < obstacle.size(); i++)
                        map[obstacle[i].first][obstacle[i].second] = 'X';
                    return false;
                }
                next_y += dir[j].first;
                next_x += dir[j].second;
            }
        }
    }
    return true;
}

void backtrack(int s) {
    if (obstacle.size() == 3) {
        if (check()) answer = 1;
        return;
    }

    for (int i = s; i < list.size(); i++) {
        obstacle.push_back(list[i]);
        backtrack(i + 1);
        obstacle.pop_back();
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'T') teacher.push_back(make_pair(i, j));
            if (map[i][j] == 'X') list.push_back(make_pair(i, j));
        }
    }
    backtrack(0);
    if (answer)
        cout << "YES";
    else
        cout << "NO";
}