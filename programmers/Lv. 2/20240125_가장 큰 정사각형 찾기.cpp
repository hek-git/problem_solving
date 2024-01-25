#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    vector<vector<int>> dp(board.size(), vector<int>(board[0].size(), 0));
    for (int i = 0; i < board[0].size(); i++)
        dp[0][i] = board[0][i], answer = max(answer, dp[0][i]);
    for (int i = 0; i < board.size(); i++)
        dp[i][0] = board[i][0], answer = max(answer, dp[i][0]);

    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[0].size(); j++) {
            if (board[i][j])
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            else
                dp[i][j] = 0;
            answer = max(answer, dp[i][j]);
        }
    }
    return answer * answer;
}