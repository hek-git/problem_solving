#include <algorithm>
#include <iostream>

using namespace std;

int N, M, map[101][101], u, v, w;
const int INF = 10000001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(i == j) map[i][j] = 0;
            else map[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        map[u][v] = min(w, map[u][v]);
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(map[i][j] == INF) map[i][j] = 0;
        }
    }


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}