#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int N, team[21][21], answer = 99999999, check[25];

int calculate(int n) {
    vector<int> list1, list2;
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (!check[i])
            list2.push_back(i);
        else
            list1.push_back(i);
    }
    
    for (int i = 0; i < list1.size(); i++) {
        for (int j = i + 1; j < list1.size(); j++) {
            a += team[list1[i]][list1[j]] + team[list1[j]][list1[i]];
            b += team[list2[i]][list2[j]] + team[list2[j]][list2[i]];
        }
    }
    return abs(a - b);
}

void solve(int n, int s, int cnt) {
    if (cnt == n / 2) {
        answer = min(answer,  calculate(n));
        return;
    }

    for (int i = s + 1; i <= n; i++) {
        if (!check[i]) {
            check[i] = 1;
            solve(n, i, cnt + 1);
            check[i] = 0;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> team[i][j];
        }
    }
    solve(N, 0, 0);
    cout << answer;
}