#include <iostream>
#include <vector>

using namespace std;

int N, num, ans=-1001;
vector<int> n(100001), dp(100001);

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> num;
        n[i] = num;
    }

    dp[1] = n[1];

    for (int i = 2; i <= N; i++) {
        if (dp[i - 1] < 0)
            dp[i] = n[i];
        else
            dp[i] = n[i] + dp[i - 1];
    }
    
    for(int i=1; i<=N; i++){
        if(ans < dp[i]) ans=dp[i];
    }

    cout << ans;

}
