#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> answer, airport;
vector<int> graph[10001];
map<string, int> m;

void dfs(int start, int size) {
    answer.push_back(airport[start]);

    for (int i = 0; i < graph[start].size(); i++) {
        if (graph[start][i] != -1) {
            int next = graph[start][i];
            graph[start][i] = -1;

            dfs(next, size);

            if (answer.size() != size) {
                // cout << "hello" << endl;
                graph[start][i] = next;
                answer.pop_back();
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    int start, idx = 0;
    sort(tickets.begin(), tickets.end());

    for (int i = 0; i < tickets.size(); i++)
        m[tickets[i][0]] = m[tickets[i][1]] = 0;
    for (auto a : m) {
        if (!a.first.compare("ICN")) start = idx;
        m[a.first] = idx++;
        airport.push_back(a.first);
    }

    for (int i = 0; i < tickets.size(); i++)
        graph[m[tickets[i][0]]].push_back(m[tickets[i][1]]);

    dfs(start, tickets.size() + 1);
    return answer;
}