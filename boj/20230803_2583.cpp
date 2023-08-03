#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int M, N, K, x, y, x2, y2, ans, t;
int map[101][101], visited[101][101], yPos[4] = {-1, 0, 1, 0}, xPos[4] = {0, 1, 0, -1};
vector<int> list;

void dfs(int a, int b) {
    // cout << "실행";
    visited[a][b] = 1;
    t++;
    //cout << a << " " << b << endl;
    for (int i = 0; i < 4; i++) {
        
        if (a + yPos[i] < 0 || b + xPos[i] < 0 || a + yPos[i] >= M || b + xPos[i] >= N){
            //cout  << a + yPos[i] << " " << b + xPos[i] << " 실행" << endl;
            continue;
        }

        if (!visited[a + yPos[i]][b + xPos[i]]) {
            dfs(a + yPos[i], b + xPos[i]);
        }
    }
}

int main() {
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> x >> y >> x2 >> y2;
        for (int j = x; j < x2; j++) {
            for (int k = y; k < y2; k++) {
                map[k][j] = 1;
                visited[k][j] = 1;
            }
        }
    }

    // for(int i=0; i<M; i++){
    //     for(int j=0; j<N; j++){
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    // for(int i=0; i<M; i++){
    //     for(int j=0; j<N; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            //cout << i << " " << j << " " << visited[M][N] << " ";
            if (!visited[i][j]) {
                //cout << M << " " << N << " 일때 " << endl;
                t = 0;
                dfs(i, j);
                list.push_back(t);
                ans++;
            }
        }
    }

    sort(list.begin(), list.end());

    cout << ans << endl;
    for (auto l : list) cout << l << " ";

    // for(int i=0; i<M; i++){
    //     for(int j=0; j<N; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}