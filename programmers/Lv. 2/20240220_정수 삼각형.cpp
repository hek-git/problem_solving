#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < triangle.size(); i++){
        dp[i][0] = triangle[i][0] + dp[i - 1][0];
        dp[i][i] = triangle[i][i] + dp[i - 1][i - 1];
    }
    
    for(int i = 2; i < triangle.size(); i++){
        for(int j = 1; j < triangle[i].size() - 1; j++){
            dp[i][j] = triangle[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
        }
    }

    for(int i = 0; i < triangle[triangle.size() - 1].size(); i++) answer = max(answer, dp[triangle.size() - 1][i]);   
    return answer;
}