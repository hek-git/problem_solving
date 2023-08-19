#include <iostream>
#include <algorithm>

using namespace std;

int N, dp[50001];

int main() {

    cin >> N;

    for(int i = 2; i<=50000; i++) dp[i] = 10;
    for(int i = 2; i*i<=50000; i++) dp[i*i] = 1;
    
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i<=50000; i++){
        for(int j = 1; j * j <= i; j++){
            dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
        }
    }

    cout << dp[N];
}