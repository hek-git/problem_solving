#include <string>
#include <vector>
#include <iostream>

using namespace std;

int sum[1000001], dp[1001][1001];

int solution(vector<int> elements) {
    int answer = 0;
    
    for(int i = 1; i <= elements.size(); i++) dp[i][i] = elements[i - 1];
    
    for(int i = 1; i <= elements.size(); i++){
        for(int j = i + 1; j <= elements.size(); j++){
            dp[i][j] = dp[i][j-1] + elements[j - 1];
        }
    }
    for(int i = 1; i <= elements.size(); i++){
        for(int j = i + 1; j <= elements.size(); j++){
            dp[j][i] = dp[j][elements.size()] + dp[1][i];
        }
    }

    // for(int i = 1; i <= elements.size(); i++){
    //     for(int j = 1; j <= elements.size(); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 1; i <= elements.size(); i++){
        for(int j = 1; j <= elements.size(); j++){
            if(sum[dp[i][j]]) continue;
            else{
                sum[dp[i][j]]++;
                answer++;
            }
        }
    }
    return answer;
}

