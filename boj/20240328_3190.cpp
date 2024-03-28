#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K, L, r, c, X, current_dir, map[101][101], answer;
char C, dir_transition[10001];

pair<int, int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<pair<int, int>> snake;

bool check_collision(int head_y, int head_x) {
    if (head_y >= N || head_x >= N || head_y < 0 || head_x < 0) return true;
    for (int i = snake.size() - 2; i >= 0; i--) {
        if (head_y == snake[i].first && head_x == snake[i].second)
            return true;
    }
    return false;
}

bool move() {
    pair<int, int> prev = snake[snake.size() - 1];
    int next_y = prev.first + dir[current_dir].first;
    int next_x = prev.second + dir[current_dir].second;
    if(check_collision(next_y, next_x)) return true;

    if (map[next_y][next_x]){
        snake.push_back(make_pair(next_y, next_x));
        map[next_y][next_x] = 0;
    }
    else {
        snake[snake.size() - 1].first = next_y;
        snake[snake.size() - 1].second = next_x;
        for (int i = snake.size() - 2; i >= 0; i--) {
            pair<int, int> tmp = snake[i];
            snake[i] = prev;
            prev = tmp;
        }
    }
    return false;
}

void check_dir_transition(){
    char c = dir_transition[answer];
    if(c == 'L') current_dir = (current_dir - 1 + 4)% 4;
    else if(c == 'D') current_dir = (current_dir + 1) % 4;
}

int solve() {
    while (true) {
        answer++;
        if(move()) return answer;
        check_dir_transition();
    }
}

int main() {
    snake.push_back(make_pair(0, 0));
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> r >> c;
        map[r - 1][c - 1] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> X >> C;
        dir_transition[X] = C;
    }
    cout << solve();
}