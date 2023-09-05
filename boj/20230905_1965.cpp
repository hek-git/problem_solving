#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, num, dp[1001], ans = 0, flag;
vector<int> boxes;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i =0; i<n; i++){
        cin >> num;
        boxes.push_back(num);
    }
    dp[0] = 1;

    for(int i = 1; i<n; i++){
        for(int j = i - 1; j>=0; j--){
            if(boxes[i] > boxes[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(dp[i] == 0) dp[i] = 1;
    }

    for(int i = 0; i<n; i++){
        ans = max(ans, dp[i]);
        cout << dp[i] <<  ' ';
    }
    cout << ans;
}