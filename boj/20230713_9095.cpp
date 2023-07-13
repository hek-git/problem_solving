#include <iostream>
#include <string>
#include <vector>

using namespace std;

// //dp
// int main() {
//     int T, num, dp[11];
//     cin >> T;
//     dp[1] = 1;
//     dp[2] = 2;
//     dp[3] = 4;
//     for (int i = 4; i <= 10; i++) {
//         dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//     }
//     for (int i = 0; i < T; i++) {
//         cin >> num;
//         cout << dp[num] << endl;
//     }
// }

//DFS? Brute force
int num, ans;

void solve(int a){
    
    if(a>num) return;

    if(a==num){
        ans++;
        return;
    }
    solve(a+1);
    solve(a+2);
    solve(a+3);
}

int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> num;
        solve(0);
        cout << ans << endl;
        ans=0;
    }
}