#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, dp[1001][1001], answer;
vector<string> map;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(map[i - 1][j - 1] == '1') dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            else continue;
            answer = max(answer, dp[i][j]);
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << answer * answer;
}