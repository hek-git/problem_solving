#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll dp[2][500001];

ll solution(vector<int> sequence) {
    ll answer = 0;
    dp[0][0] = sequence[0];
    dp[1][0] = -sequence[0];
    answer = max({answer, dp[0][0], dp[1][0]});
    for(int i = 1; i < sequence.size(); i++){
        dp[0][i] = max((ll)sequence[i], (ll)sequence[i] + dp[1][i - 1]);
        dp[1][i] = max((ll)-sequence[i], (ll)-sequence[i] + dp[0][i - 1]);
        answer = max({answer, dp[0][i], dp[1][i]});
    }
    return answer;
}