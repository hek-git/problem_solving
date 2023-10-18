// #include <algorithm>
// #include <iostream>
// #include <vector>

// using namespace std;

// vector<pair<int, int>> Tree[10001];
// int N, parent, child, w, visited[10001], ans, ans = 0;

// // 모든 노드에 대해 DFS하여 가능한 경우를 다 계산하는 경우
// void dfs(int s, int l) {
//     ans = max(l, ans);
//     visited[s] = 1;
//     for(int i = 0; i < Tree[s].size(); i++){
//         if(!visited[Tree[s][i].first]){
//             dfs(Tree[s][i].first, l + Tree[s][i].second);
//         }
//     }
//     visited[s] = 0;
// }

// int main() {
//     cin >> N;
//     for (int i = 1; i < N; i++) {
//         cin >> parent >> child >> w;
//         Tree[parent].push_back(make_pair(child, w));
//         Tree[child].push_back(make_pair(parent, w));
//     }
//     // 1 번 부터 모든 노드에 대해 dfs를 실행한다.
//     // 각 dfs 반복시 해당 노드에서 가장 큰 거리가 반환된다.
//     // 모든 노드에 대해 dfs를 실행하고 이를 비교하여 최대값을 찾는다.
//     for (int i = 1; i <= N; i++) {
//         ans = 0;
//         dfs(i, 0);
//         // cout << i << " : " << ans << endl;
//         ans = max(ans, ans);
//     }
//     cout << ans;
// }

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> Tree[10001];
int N, parent, child, w, visited[10001];
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
    for (int i = 1; i < N; i++) {
        cin >> parent >> child >> w;
        Tree[parent].push_back(make_pair(child, w));
        Tree[child].push_back(make_pair(parent, w));
    }

    // 임의의 한 노드에 대해 dfs를 실행한다.
    // 결과로 len의 first에는 해당 노드 가장 먼 노드의 번호와 거리가 반환된다.
    // 위에서 구한 노드에서 다시 bfs를 하여 트리의 지름을 출력.
    dfs(1, 0);
    // cout << ans.first << " : " << ans.second << endl;
    dfs(ans.first, 0);

    cout << ans.second;
}