#include <algorithm>
#include <iostream>

using namespace std;

int N, M, B, time = 2000000000, height, m;
int map[500][500];

int blockNeed(int h) {
    int num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (h - map[i][j] > 0) num += (h - map[i][j]);
        }
    }
    return num;
}

int blockExtract(int h) {
    int num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] - h > 0) num += (map[i][j] - h);
        }
    }
    return num;
}

void solve(int h, int b) {
    int t = 0;
    int blockExtracted = blockExtract(h);
    int totalBlock = b + blockExtracted;
    int blockNeeded = blockNeed(h);

    if (totalBlock < blockNeeded) return;

    t = blockExtracted * 2 + blockNeeded;

    if (t < time) {
        time = t;
        height = h;
    } else if (t == time) {
        height = max(h, height);
    }
}

int main() {
    cin >> N >> M >> B;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            m = max(map[i][j], m);
        }
    }

    for (int i = m; i >= 0; i--) {
        solve(i, B);
    }

    cout << time << " " << height;
}