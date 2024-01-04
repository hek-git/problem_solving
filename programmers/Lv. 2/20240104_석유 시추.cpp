#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int visited[501][501], gas[250001], num = 1, n, m;
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// bfs로 뽑을 수 있는 모든 석유 칸 수 조회, 이때 num 값으로 각 덩어리에 번호를 매김
int bfs(vector<vector<int>>& map, pair<int, int> source, int num){
    int oil = 0;
    queue<pair<int, int>> q;
    q.push(source);
    visited[source.first][source.second] = num;
    
    while(!q.empty()){
        oil++;
        pair<int, int> s = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nextX = s.second + dir[i].second;
            int nextY = s.first + dir[i].first;
            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= m || visited[nextY][nextX] || !map[nextY][nextX]) continue;
            q.push(make_pair(nextY, nextX));
            visited[nextY][nextX] = num;
        }
    }
    return oil;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size();
    m = land[0].size();

    // 모든 칸에 접근하여 각 덩어리에 bfs로 뽑을 수 있는 석유의 수를 찾고 배열에 석유 번호와 함께 매핑 
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(land[j][i] && !visited[j][i]){
                int oil = bfs(land, make_pair(j, i), num);
                gas[num++] = oil;                
            }
        }
    }

    for(int i = 0; i < m; i++){
        set<int> gas_num;
        int oil = 0;
        // 각 열에 대해 순차적으로 접근하여 각 덩어리 번호 값을 집합에 저장(중복X)
        for(int j = 0; j < n; j++){
            if(land[j][i]) gas_num.insert(visited[j][i]);
        }
        // 얻을 수 있는 석유 칸 수를 저장해놓은 배열을 이용해 해당 열에서 얻을 수 있는 전체 석유 칸 수를 구함
        for(auto g : gas_num) oil += gas[g];
        answer = max(answer, oil);
    }
    
    return answer;
}