#include <iostream>
#include <vector>

using namespace std;

int N, white, blue;
int map[129][129];

int countWhite(pair<int, int>& source, int N) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!map[source.first + i][source.second + j]) cnt++;
        }
    }
    return cnt;
}

void solve(pair<int, int> source, int N) {
    int whiteSpace = countWhite(source, N);
    //cout << N << " white space :" << whiteSpace << endl;
    if (whiteSpace == N * N) {
        white++;
        return;
    } else if (whiteSpace == 0) {
        blue++;
        return;
    }

    int half = N / 2;
    solve(make_pair(source.first, source.second), half);
    solve(make_pair(source.first + half, source.second), half);
    solve(make_pair(source.first, source.second + half), half);
    solve(make_pair(source.first + half, source.second + half), half);
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    solve(make_pair(1, 1), N);
    cout << white << "\n"
         << blue;
}