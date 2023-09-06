#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, i;
vector<int> dp(1000001, 1000000), ans;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    dp[n] = 0;
    for (int i = n; i > 0; i--){
        if (i % 3 == 0)
            dp[i / 3] = min(dp[i / 3], dp[i] + 1);
        if (i % 2 == 0)
            dp[i / 2] = min(dp[i / 2], dp[i] + 1);
        dp[i - 1] = min(dp[i - 1], dp[i] + 1);
    }

    i = 1;
    ans.push_back(1);
    while (true){
        //cout << i << " "; 
        if(i >= n) break;
        if(dp[i+1] == dp[i] - 1){
            i+=1;
        }else if(dp[i*2] == dp[i] - 1){
            i*=2;
        }else if(dp[i*3] == dp[i] - 1){
            i*=3;
        }
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());

    cout << dp[1] << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    
}