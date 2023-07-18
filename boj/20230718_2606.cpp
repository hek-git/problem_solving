#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, num, S, T, ans, visited[101];
vector<int> network[101];

void bfs() {
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int p = q.front();
        q.pop();
        visited[1]=1;

        for (int i = 0; i < network[p].size(); i++) {
            if (!visited[network[p][i]]) {
                q.push(network[p][i]);
                visited[network[p][i]] = 1;
            }
        }
        ans++;
    }
}

int main() {
    cin >> N >> num;
    for (int i = 0; i < num; i++) {
        cin >> S >> T;
        network[S].push_back(T);
        network[T].push_back(S);
    }
    bfs();
    cout << ans-1;
}