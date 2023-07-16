#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int N, K, solution[100001], visited[100001];

void bfs() {
    fill_n(solution, 100001, 100001);

    int n = N;
    queue<int> q;

    q.push(N);
    solution[N] = 0;
    visited[N] = 1;

    while (!q.empty()) {

        if (n == K) break;

        n = q.front();
        q.pop();

        if (n - 1 >= 0 && !visited[n - 1]) {
            q.push(n - 1);
            solution[n - 1] = solution[n] + 1;
            visited[n - 1] = 1;
        }
        if (n + 1 <= 100000 && !visited[n + 1]) {
            q.push(n + 1);
            solution[n + 1] = solution[n] + 1;
            visited[n + 1] = 1;
        }
        if (n * 2 <= 100000 && !visited[n * 2]) {
            q.push(n * 2);
            solution[n * 2] = solution[n] + 1;
            visited[n * 2] = 1;
        }
    }
}

int main() {
    cin >> N >> K;
    bfs();
    cout << solution[K];
}
