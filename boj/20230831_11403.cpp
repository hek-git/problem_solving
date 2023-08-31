#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, num, visited[101], ans[101][101];
vector<int> map[101];

void bfs(int source) {
    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int s = q.front();
        q.pop();

        for(int i = 0; i<map[s].size(); i++){
            int dest = map[s][i];
            if(!visited[dest]){
                 q.push(dest);
                 visited[dest] = 1;
                 ans[source][dest] = 1;
            }
        }
    }

}

void initSettings(){
    memset(visited, 0, sizeof(visited));
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> num;
            if (num) map[i].push_back(j);
        }
    }
    
    // 인접 리스트 출력
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 0; j < map[i].size(); j++) {
    //         cout << i << "-> " << map[i][j] << endl;
    //     }
    //     cout << '\n';
    // }

    for (int i = 1; i <= N; i++) {
        bfs(i);
        initSettings();
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}