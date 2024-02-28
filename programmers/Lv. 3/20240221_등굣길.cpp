#include <string>
#include <vector>
#include <iostream>
#define MOD 1000000007

using namespace std;

int dp[100][100];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for (int i = 0; i < puddles.size(); i++) {
        int tmp = puddles[i][0] - 1;
        puddles[i][0] = puddles[i][1] - 1;
        puddles[i][1] = tmp;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) dp[i][j] = -1;

    dp[0][0] = 1;
    for (int i = 0; i < puddles.size(); i++) dp[puddles[i][0]][puddles[i][1]] = 0;
    for (int i = 1; i < n; i++) if(dp[i][0]) dp[i][0] = dp[i - 1][0];
    for (int i = 1; i < m; i++) if(dp[0][i]) dp[0][i] = dp[0][i - 1];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if(dp[i][j]) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    return dp[n - 1][m - 1];
}