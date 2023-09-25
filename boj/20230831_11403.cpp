// #include <iostream>
// #include <queue>
// #include <vector>
// #include <cstring>

// bfs를 이용한 풀이
// using namespace std;

// int N, num, visited[101], ans[101][101];
// vector<int> map[101];

// void bfs(int source) {
//     queue<int> q;
//     q.push(source);

//     while(!q.empty()){
//         int s = q.front();
//         q.pop();

//         for(int i = 0; i<map[s].size(); i++){
//             int dest = map[s][i];
//             if(!visited[dest]){
//                  q.push(dest);
//                  visited[dest] = 1;
//                  ans[source][dest] = 1;
//             }
//         }
//     }

// }

// void initSettings(){
//     memset(visited, 0, sizeof(visited));
// }

// int main() {
//     cin >> N;

//     for (int i = 1; i <= N; i++) {
//         for (int j = 1; j <= N; j++) {
//             cin >> num;
//             if (num) map[i].push_back(j);
//         }
//     }

//     // 인접 리스트 출력
//     // for (int i = 1; i <= N; i++) {
//     //     for (int j = 0; j < map[i].size(); j++) {
//     //         cout << i << "-> " << map[i][j] << endl;
//     //     }
//     //     cout << '\n';
//     // }

//     for (int i = 1; i <= N; i++) {
//         bfs(i);
//         initSettings();
//     }
//     for(int i = 1; i<=N; i++){
//         for(int j = 1; j<=N; j++){
//             cout << ans[i][j] << " ";
//         }
//         cout << '\n';
//     }
// }

// 플로이드 워셜 알고리즘을 이용한 풀이
#include <iostream>

using namespace std;

int N, n, map[101][101], ans[101][101];

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> n;
            if(n){
                map[i][j] = 1;
                ans[i][j] = 1;
            }
            else map[i][j] = 100;
            
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][j] > map[i][k] + map[k][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                    ans[i][j] = 1;
                }
            }
        }
    }

    for(int a = 1; a<=N; a++){
        for(int b = 1; b<=N; b++){
            cout << ans[a][b] << " ";
        }
        cout << endl;
    }
}