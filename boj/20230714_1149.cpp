#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, num, prev, dp[1001][3];
    vector<int> house[1001];

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> num;
            house[i].push_back(num);
        }
    }

    dp[1][0] = house[1][0];
    dp[1][1] = house[1][1];
    dp[1][2] = house[1][2];

    for (int i = 2; i <= N; i++) {
        dp[i][0] = house[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = house[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = house[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << min({dp[N][0], dp[N][1], dp[N][2]});
}