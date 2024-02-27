#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int union_find[101];

bool cmp(vector<int>& a, vector<int>& b) { return a[2] < b[2]; }

int find(int n) {
    if(union_find[n] == n) return n;
    return union_find[n] = find(union_find[n]);
}

void merge(int a, int b) { union_find[find(a)] = find(b); }

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i = 0; i < n; i++) union_find[i] = i;
    sort(costs.begin(), costs.end(), cmp);
    for (int i = 0; i < costs.size(); i++) {
        if (find(costs[i][0]) == find(costs[i][1])) continue;
        answer += costs[i][2];
        merge(costs[i][0], costs[i][1]);
    }
    return answer;
}