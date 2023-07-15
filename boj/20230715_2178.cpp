#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

//map은 미로 정보, visited[i][j]는 방문했는지 여부, solution[i][j]는 i, j 위치까지 오는데 걸리는 최단 거리
int N, M, map[102][102], visited[102][102], solution[102][102];
//위, 오른쪽, 아래, 왼쪽 방향 순서대로 살펴보기 위한 방향 배열
int dir_y[4] = {-1, 0, 1, 0}, dir_x[4] = {0, 1, 0, -1};

//1,1 부터 bfs(너비 우선 탐색)하여 답을 찾는 함수
void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    solution[1][1] = 1;

    while (!q.empty()) {
        //i와 j가 각각 N, M일 경우 목적지이므로 종료
        if (i == N && j == M) break;
        
        //큐의 가장 앞 원소를 가져옴(dfs하기 위함)
        i = q.front().first, j = q.front().second;
        q.pop();

        //이미 방문했다면 아무 것도 하지 않음
        if (visited[i][j]) continue;

        //방문 했음을 표시
        visited[i][j] = 1;

        // 위쪽, 오른쪽, 아래쪽, 왼쪽을 조사하며 방문 가능한지 확인(0이 아니고 visited 하지 않았는지 확인)
        // 방문 가능하면 solution(정답)을 채우고 해당 방향을 큐에 삽입
        for (int d = 0; d < 4; d++) {
            if (map[i + dir_y[d]][j + dir_x[d]] && !visited[i + dir_y[d]][j + dir_x[d]]) {
                solution[i + dir_y[d]][j + dir_x[d]] = solution[i][j] + 1;
                q.push(make_pair(i + dir_y[d], j + dir_x[d]));
            }
        }
    }
}

int main() {
    cin >> N >> M;
    
    //입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    //1,1 좌표에서 부터 bfs 시작
    bfs(1, 1);
    cout << solution[N][M];
}

