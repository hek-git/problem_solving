#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<int> s;
int visited[101][101], map[101][101];

void dfs(int source, int& n) {
    s.insert(source);
    for (int i = 1; i <= n; i++) {
        if (!visited[source][i] && map[source][i]) {
            visited[source][i] = visited[i][source] = 1;
            dfs(i, n);
        }
    }
}

int solution(int n) {
    s.clear();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j]) {
                dfs(i, n);
                memset(visited, 0, sizeof(visited));
                int diff = n - s.size();
                return diff - (n - diff) > 0 ? diff - (n - diff) : -(diff - (n - diff));
            }
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    for (int i = 0; i < wires.size(); i++)
        map[wires[i][0]][wires[i][1]] = map[wires[i][1]][wires[i][0]] = 1;

    for (int k = 0; k < wires.size(); k++) {
        map[wires[k][0]][wires[k][1]] = map[wires[k][1]][wires[k][0]] = 0;
        answer = min(solution(n), answer);
        map[wires[k][0]][wires[k][1]] = map[wires[k][1]][wires[k][0]] = 1;
    }
    return answer;
}