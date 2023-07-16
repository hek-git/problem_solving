#include <iostream>

using namespace std;

int N, num, rectangle[501][501], dp[501][501], ans;

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num;
            rectangle[i][j] = num;
        }
    }

    dp[1][1] = rectangle[1][1];

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1)
                dp[i][j] = rectangle[i][j] + dp[i - 1][j];
            else if (j == i)
                dp[i][j] = rectangle[i][j] + dp[i - 1][j - 1];
            else
                dp[i][j] = rectangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (ans < dp[N][i]) ans = dp[N][i];
    }

    cout << ans;
}
