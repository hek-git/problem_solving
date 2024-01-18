#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INIT 2000000

using namespace std;

int dp[1000001];

int solution(int x, int y, int n) {
    for (int i = 0; i < x; i++) dp[i] = INIT;
    for (int i = x + 1; i < 1000001; i++) dp[i] = INIT;
    for (int i = x + 1; i < 1000001; i++) {
        if (i - n >= 0 && dp[i - n] != INIT) dp[i] = min(dp[i], dp[i - n] + 1);
        if (i % 2 == 0 && dp[i / 2] != INIT) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0 && dp[i / 3] != INIT) dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    // for(int i = 0; i <= y; i++) cout << i << " " << dp[i] << endl;
    return dp[y] == INIT ? -1 : dp[y];
}