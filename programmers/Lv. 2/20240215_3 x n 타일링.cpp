#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

typedef long long ll;

ll dp[5001];

int solution(int n) {
    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 11;
    for (int i = 6; i <= 5000; i++) {
        if (i % 2 != 1) {
            int tmp = i - 4;
            dp[i] = 3 * dp[i - 2] % MOD;
            while (tmp >= 0) {
                dp[i] = (dp[i] + (2 * dp[tmp])) % MOD;
                tmp -= 2;
            }
        }
    }
    return dp[n];
}