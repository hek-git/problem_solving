#include <iostream>

using namespace std;

int N, wine[10001], dp[10001][3], ans;

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> wine[i];
    }

    dp[1][1] = wine[1];
    dp[2][1] = dp[1][1] + wine[2];
    dp[2][2] = wine[2];

    for (int i = 3; i <= N; i++) {
        dp[i][1] = wine[i] + dp[i - 1][2];
        dp[i][2] = wine[i] + max(dp[i - 2][1], dp[i - 2][2]);
        if (dp[i][2] < (wine[i] + max(dp[i - 3][1], dp[i - 3][2])))
            dp[i][2] = wine[i] + max(dp[i - 3][1], dp[i - 3][2]);
    }

    for (int i = 1; i <= N; i++) {
        if (ans < dp[i][1]) ans = dp[i][1];
        if (ans < dp[i][2]) ans = dp[i][2];
    }

    cout << ans;
}