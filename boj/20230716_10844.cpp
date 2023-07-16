#include <iostream>
#define mod 1000000000

using namespace std;

long long N, dp[101][10], ans;

int main() {
    cin >> N;
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 1; i <= 99; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0)
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
            else if (j == 9)
                dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % mod;
            else {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
                dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % mod;
            }
            dp[i][j] %= mod;
        }
    }

    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[N][i]) % 1000000000;
    }

    cout << ans;
}