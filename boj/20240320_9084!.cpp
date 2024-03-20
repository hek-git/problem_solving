#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int T, N, M, dp[10001], c;
vector<int> coin;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        coin.clear();
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < N; j++) {
            cin >> c;
            coin.push_back(c);
        }
        cin >> M;
        for (int k = 0; k < coin.size(); k++) {
            if (coin[k] > M) continue;
            dp[coin[k]]++;
            for (int l = coin[k] + 1; l <= M; l++)
                dp[l] = dp[l] + dp[l - coin[k]];
        }
        cout << dp[M] << endl;
    }
}