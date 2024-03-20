#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K, W, V, dp[100001];
vector<int> weight, value;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> W >> V;
        weight.push_back(W);
        value.push_back(V);
    }

    for(int i = 0; i < weight.size(); i++){
        for(int j = K; j >= weight[i]; j--){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[K];
}