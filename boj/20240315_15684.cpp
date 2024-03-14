#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, H, h, n, graph[31][11][11], answer = 4;
vector<pair<int, int>> candidate, list;

int dfs(int s, int h){
    if(h == H + 1) return s; // 마지막 높이에 도착했다면 해당 세로선 번호 반환
    if(graph[h][s][s + 1]) return dfs(s + 1, h + 1); // 내 다음 세로선과 연결된 경우 ex) 1 -> 2
    else if(graph[h][s][s - 1]) return dfs(s - 1, h + 1); // 내 이전 세로선과 연결된 경우 ex) 2 -> 1
    else return dfs(s, h + 1); // 현재 높이(h)에서 연결된 세로선이 없는 경우 동일한 세로선의 다음 높이로 이동
}

bool validate(){
    bool flag = true;

    // 뽑은 가로선 후보를 graph에 적용
    for(int i = 0; i < candidate.size(); i++){
        int h = candidate[i].first, n = candidate[i].second;
        graph[h][n][n + 1] = graph[h][n + 1][n] = 1;
    }

    // 1~N번 가로선까지 사다리타기를 진행
    for(int i = 1; i <= N; i++){
        if(i != dfs(i, 1)) { // 사다리타기 결과가 i와 다른 경우 즉시 break
            flag = false; 
            break;
        }
    }

    // graph에 적용된 가로선 원상복구
    for(int i = 0; i < candidate.size(); i++){
        int h = candidate[i].first, n = candidate[i].second;
        graph[h][n][n + 1] = graph[h][n + 1][n] = 0;
    }
    return flag;
}

void backtrack(int s){
    // 후보 가로선 개수와 상관없이 검증 진행, 최소값인 경우 최신화
    if(validate()) answer = min(answer, (int)candidate.size());
    if(candidate.size() == 3) return; // 3개를 초과하여 뽑을 필요없으므로 백트래킹 중지

    // 백트래킹 중복 제거를 위해 s 인덱스부터 시작
    for(int i = s; i < list.size(); i++){
        candidate.push_back(list[i]);
        backtrack(i + 1);
        candidate.pop_back();
    }
}

int main() {
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        cin >> h >> n;
        graph[h][n][n + 1] = graph[h][n + 1][n] = 1;
    }

    // 구성된 graph를 후보가 될 수 있는 가로선 추가
    for(int i = 1; i <= H; i++){
        for(int j = 1; j < N; j++){
            if(!graph[i][j][j + 1]) list.push_back(make_pair(i, j));
        }
    }

    backtrack(0);
    if(answer == 4) answer = -1;
    cout << answer;
}