#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, s, t, a, b, ans, visited[101];
vector<int> list[101];

void dfs(int s, int t, int n) {
    if (s == t){
        ans = n;
        return;
    }

    visited[s] = 1;
    for (int i = 0; i < list[s].size(); i++) {
        int next = list[s][i];
        if (!visited[next]) {
        dfs(next, t, n + 1);
        }
    }
}

int main() {
    cin >> N;
    cin >> s >> t;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    dfs(s, t, 0);
    if (ans)
        cout << ans;
    else
        cout << -1;
    return 0;
}