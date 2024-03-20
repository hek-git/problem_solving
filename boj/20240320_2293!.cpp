#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, k, dp[100001], c;
vector<int> coin;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> c;
        coin.push_back(c);
    }
    for(int i = 0; i < coin.size(); i++){
        if(coin[i] > k) continue;
        dp[coin[i]]++;
        for(int j = coin[i] + 1; j <= k; j++) dp[j] = dp[j] + dp[j - coin[i]];
    }
    cout << dp[k];
}