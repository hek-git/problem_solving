// #include <algorithm>
// #include <iostream>
// #include <vector>

// using namespace std;

// vector<pair<int, int>> Tree[10001];
// int N, parent, child, w, visited[10001], ans, ans = 0;

// // ��� ��忡 ���� DFS�Ͽ� ������ ��츦 �� ����ϴ� ���
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
//     // 1 �� ���� ��� ��忡 ���� dfs�� �����Ѵ�.
//     // �� dfs �ݺ��� �ش� ��忡�� ���� ū �Ÿ��� ��ȯ�ȴ�.
//     // ��� ��忡 ���� dfs�� �����ϰ� �̸� ���Ͽ� �ִ밪�� ã�´�.
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

// Ʈ���� ������ ���ϴ� �˰��� ���
// ������ �� ������ ���� �Ÿ��� �� ���� ã�� �� ������ ���� �Ÿ��� �� ���� ã���� �ش� ��尡 Ʈ���� ����.
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

    // ������ �� ��忡 ���� dfs�� �����Ѵ�.
    // ����� len�� first���� �ش� ��� ���� �� ����� ��ȣ�� �Ÿ��� ��ȯ�ȴ�.
    // ������ ���� ��忡�� �ٽ� bfs�� �Ͽ� Ʈ���� ������ ���.
    dfs(1, 0);
    // cout << ans.first << " : " << ans.second << endl;
    dfs(ans.first, 0);

    cout << ans.second;
}