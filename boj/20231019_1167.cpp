#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, s, d, w, visited[100001];
vector<pair<int, int>> Tree[100001];
pair<int, int> ans;

// 트리의 지름을 구하는 알고리즘 사용
// 임의의 한 점에서 가장 거리가 먼 점을 찾고 그 점에서 가장 거리가 먼 점을 찾으면 해당 노드가 트리의 지름.
void dfs(int s, int l) {
    if (ans.second < l) {
        ans.first = s;
        ans.second = l;
    }
    visited[s] = 1;
    for (int i = 0; i < Tree[s].size(); i++) {
        if (!visited[Tree[s][i].first]) {
            dfs(Tree[s][i].first, l + Tree[s][i].second);
        }
    }
    visited[s] = 0;
}

int main() {
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> s;
        while(true){
            cin >> d;
            if(d==-1) break;
            else{
                cin >> w;
            }
            Tree[s].push_back(make_pair(d, w));
        }
    }
    dfs(1, 0);
    dfs(ans.first, 0);
    cout << ans.second;
}