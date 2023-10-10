#include <algorithm>
#include <iostream>

using namespace std;

int S, T, dp[200000];

int main() {
    cin >> S >> T;
    if (S >= T) {
        cout << S - T;
        return 0;
    }

    for (int i = S; i >= 0; i--) {
        dp[i] = S - i;
    }

    if (S == 0) {
        S = 1;
        dp[S] = 1;
        for(int i = 2; i<200000; i++){
            dp[i] = 50;
        }
    } else {
        for (int i = S; i <= 100000; i *= 2) {
            for (int j = i; j < i * 2; j++) {
                dp[j] = j - i;
            }
        }
    }

    for (int i = S; i <= 100000; i *= 2) {
        for (int j = i; j <= i * 2; j++) {
            if (j % 2 == 1) {
                dp[j] = min(dp[j], dp[j - 1] + 1);
            } else {
                dp[j] = min({dp[j], dp[j - 1] + 1, dp[j / 2]});
                dp[j - 1] = min(dp[j - 1], dp[j] + 1);
            }
        }
    }

    cout << dp[T];
    //  for(int i = 0; i < 100000; i++){
    //       cout << i << " : " << dp[i] << endl;
    //  }
}
