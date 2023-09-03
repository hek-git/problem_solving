#include <iostream>
#include <algorithm>

using namespace std;

int N, dp[100001][3];

int maxPoint() {

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + dp[i][j];
            else if (j == 1) dp[i][j] = max({ dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1] }) + dp[i][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + dp[i][j];
        }
    }
    return max({ dp[N][0], dp[N][1], dp[N][2] });
}

int minPoint() {

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + dp[i][j];
            else if (j == 1) dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1] }) + dp[i][j];
            else dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + dp[i][j];
        }
    }
    return min({ dp[N][0], dp[N][1], dp[N][2] });
}

void initPoint() {

    for (int i = N; i > 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) dp[i][j] -= max(dp[i - 1][j], dp[i - 1][j + 1]);
            else if (j == 1) dp[i][j] -= max({ dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1] });
            else dp[i][j] -= max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> dp[i][j];
        }
    }

    cout << maxPoint() << " ";
    initPoint();
    cout << minPoint();
}