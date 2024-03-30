#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[100001];
int solution(int n, vector<int> money) {
    int answer = 0;
    for(int i = 0; i < money.size(); i++){
        dp[money[i]]++;
        for(int j = money[i]; j <= n; j++){
            dp[j] += dp[j - money[i]];
        }
    }
    return dp[n];
}