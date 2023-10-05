#include <algorithm>
#include <iostream>

using namespace std;

int T, n, num, s[2][100001], dp[2][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        for (int j = 0; j < 2; j++) {
            for (int k = 1; k <= n; k++) {
                cin >> num;
                s[j][k] = num;
            }
        }
        dp[0][1] = s[0][1];
        dp[1][1] = s[1][1];
        for (int k = 2; k <= n; k++) {
            dp[0][k] = max({dp[1][k - 1], dp[1][k - 2], dp[0][k - 2]}) + s[0][k];
            dp[1][k] = max({dp[0][k - 1], dp[0][k - 2], dp[0][k - 2]}) + s[1][k];
        }
        cout << max(dp[0][n], dp[1][n]) << '\n';
    }
}