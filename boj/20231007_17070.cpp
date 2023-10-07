#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, ans, flag, map[18][18], dx[3] = {1, 1, 0}, dy[3] = {0, 1, 1};

void bfs(){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(1, 1), make_pair(1, 2)));

    while(!q.empty()){
        pair<pair<int, int>, pair<int, int>> s;
        s = q.front();
        q.pop();
        
        pair<int, int> p1 = s.first;
        pair<int, int> p2 = s.second;
        // �������� �� ��ġ�� N, N�̸� continue
        if(p2.first == N && p2.second == N){
            ans++;
            continue;
        }       

        // ������ ������ ������ ���
        if(p2.first - 1 == p1.first && p2.second == p1.second){
            // �Ʒ� �������� �� �� �ִ��� Ȯ��
            if(!map[p2.first + 1][p2.second]){
                q.push(make_pair(make_pair(p1.first + 1, p1.second), make_pair(p2.first + 1, p2.second)));
            }
            // �밢�� �������� �� �� �ִ��� Ȯ��
            for(int i = 0; i < 3; i++){
                if(map[p2.first + dy[i]][p2.second + dx[i]]) flag = 1;
            }
            if(!flag){
                q.push(make_pair(make_pair(p1.first + 1, p1.second), make_pair(p2.first + 1, p2.second + 1)));
            }
            flag = 0;
        }

        // ������ ������ ������ ���
        else if(p2.first == p1.first && p2.second - 1 == p1.second){
            // ������ �������� �� �� �ִ��� Ȯ��
            if(!map[p2.first][p2.second + 1]){
                q.push(make_pair(make_pair(p1.first, p1.second + 1), make_pair(p2.first, p2.second + 1)));
            }
            // �밢�� �������� �� �� �ִ��� Ȯ��
            for(int i = 0; i < 3; i++){
                if(map[p2.first + dy[i]][p2.second + dx[i]]) flag = 1;
            }
            if(!flag){
                q.push(make_pair(make_pair(p1.first, p1.second + 1), make_pair(p2.first + 1, p2.second + 1)));
            }
            flag = 0;
        }

        // ������ ������ ������ �밢���� ���
        else if(p2.first - 1 == p1.first && p2.second -1 == p1.second){
            // ������ �������� �� �� �ִ��� Ȯ��
            if(!map[p2.first][p2.second + 1]){
                q.push(make_pair(make_pair(p1.first + 1, p1.second + 1), make_pair(p2.first, p2.second + 1)));
            }
            // �Ʒ� �������� �� �� �ִ��� Ȯ��
            if(!map[p2.first + 1][p2.second]){
                q.push(make_pair(make_pair(p1.first + 1, p1.second + 1), make_pair(p2.first + 1, p2.second)));
            }
            // �밢�� �������� �� �� �ִ��� Ȯ��
            for(int i = 0; i < 3; i++){
                if(map[p2.first + dy[i]][p2.second + dx[i]]) flag = 1;
            }
            if(!flag){
                q.push(make_pair(make_pair(p1.first + 1, p1.second + 1), make_pair(p2.first + 1, p2.second + 1)));
            }
            flag = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i<=N; i++){
        map[N+1][i] = 1;
        map[i][N+1] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
    bfs();
    cout << ans;
}