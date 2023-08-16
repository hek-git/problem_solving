#include <iostream>
#include <vector>

using namespace std;

int T, k, n;
long long dp[15][15];

int main() {
    cin >> T;

    for (int j = 1; j <= 14; j++) dp[0][j] = j;

    for (int j = 1; j <= 14; j++) {
        for (int k = 1; k <= 14; k++) {
            for (int l = 1; l <= k; l++){
                dp[j][k] += dp[j-1][l];
            }
        }
    }

    // for(int i=0; i<=14; i++){
    //     for(int j = 0; j<=14; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < T; i++) {
        cin >> k >> n;
        cout << dp[k][n] << endl;
    }
}