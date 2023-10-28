#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// visited�� �� 0 : �湮���� ����, 1 : ���� �μ��� ���� ���¿��� �湮��, 2 : ���� �μ� ���·� �湮��
int N, M, ans = -1, map[1001][1001], visited[1001][1001];
pair<int, int> d[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void bfs(){
    queue<pair<pair<int,int>, pair<bool, int>>> q;
    q.push(make_pair(make_pair(1, 1), make_pair(true, 1)));
    visited[1][1] = 1;

    while(!q.empty()){
        pair<int, int> s, state;
        s = q.front().first;
        state = q.front().second;
        q.pop();

        
        if(s.first == N && s.second == M){
            ans = state.second;
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int nextX = s.second + d[i].second;
            int nextY = s.first + d[i].first;

            if(nextY > N || nextX > M || nextY < 1 || nextX < 1) continue;

            // ���� �ִµ� �μ� �� ���� ���
            if (map[nextY][nextX] && state.first == false) continue;

            // ���� �ִµ� �μ� �� �ִ� ���
            else if (map[nextY][nextX] && state.first) {
                // �̹� 1(���� �μ��� ����)�̰ų� 2(���� �μ� ����)�� �湮�ߴٸ� q�� �߰����� �ʴ´�
                // �ƴ϶�� �湮���� �ʾ����Ƿ� q�� �߰��ϰ� �μ� ���·� �湮(2)ǥ��
                if(!visited[nextY][nextX]){
                    q.push(make_pair(make_pair(nextY, nextX), make_pair(false, state.second + 1)));
                    visited[nextY][nextX] = 2;
                }
            }

            // ���� ���� �μ� �� ���� ���
            else if (state.first == false) {
                // �̹� 1(���� �μ��� ����)�̰ų� 2(���� �μ� ����)�� �湮�ߴٸ� q�� �߰����� �ʴ´�
                // �ƴ϶�� �湮���� �ʾ����Ƿ� q�� �߰��ϰ� �μ� ���·� �湮(2)ǥ��
                if(!visited[nextY][nextX]){
                    q.push(make_pair(make_pair(nextY, nextX), make_pair(state.first, state.second + 1)));
                    visited[nextY][nextX] = 2;
                }
            }

            // ���� ���� �μ� �� �ִ� ���
            else {
                // �̹� 1��(���� �μ��� ����) ���·� �湮�ߴٸ� q�� �߰����� �ʴ´�
                // �ƴ϶�� ������ �湮���� �ʾҰų� 2�� ���·� �湮�� ���̰� �̴� �� ȿ�������� �� ����̹Ƿ� �μ��� ���� ���·� �湮(1) ǥ��
                if(visited[nextY][nextX] != 1){
                    q.push(make_pair(make_pair(nextY, nextX), make_pair(state.first, state.second + 1)));
                    visited[nextY][nextX] = 1;
                }
            }
        }
        
    }
}

int main() {

    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        string tmp;
        cin >> tmp;
        for(int j = 1; j <= M; j++){
            map[i][j] = tmp[j-1] - '0';
        }
    }
    bfs();
    cout << ans;
}