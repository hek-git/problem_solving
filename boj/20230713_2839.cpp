#include <iostream>
#include <cstring>

using namespace std;

// //greedy
// int main() {
//     int N, ans = -1, i = 0;
//     cin >> N;
//     while (i * 3 <= N) {
//         if ((N - 3 * i) % 5 == 0) {
//             ans += i+1;
//             ans += (N - 3 * i) / 5;
//             break;
//         }
//         i++;
//     }
//     cout << ans;
// }

//dp
int main() {
    int N, dp[5001];
    memset(dp, -1, sizeof(dp));
    dp[3]=1;
    dp[5]=1;

    cin >> N;
    for(int i=6; i<=5000; i++){
        if(dp[i-3]==-1 && dp[i-5]==-1 );
        else if(dp[i-5]!=-1) dp[i]=dp[i-5]+1;
        else dp[i]=dp[i-3]+1;
    }
    cout << dp[N];
}