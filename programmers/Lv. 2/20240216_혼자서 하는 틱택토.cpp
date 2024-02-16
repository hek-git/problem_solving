#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 선공 또는 후공이 승리했는지 확인하는 함수
bool is_win(vector<string>& board, char c) {
    // 세로줄 또는 가로줄에 c가 연속되어 있는지 확인
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == c && board[0][i] == board[1][i] &&
            board[0][i] == board[2][i] && board[1][i] == board[2][i])
            return true;
        if (board[i][0] == c && board[i][0] == board[i][1] &&
            board[i][0] == board[i][2] && board[i][1] == board[i][2])
            return true;
    }
    // 대각선 방향으로 c가 연속되어 있는지 확인
    if (board[1][1] == c && board[0][0] == board[1][1] &&
        board[0][0] == board[2][2] && board[1][1] == board[2][2])
        return true;
    if (board[1][1] == c && board[0][2] == board[2][0] &&
        board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    return false;
}

int solution(vector<string> board) {
    int count_o = 0, count_x = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'O') count_o++;
            if (board[i][j] == 'X') count_x++;
        }
    }
    // o와 x의 개수가 2개 이상 차이나거나 x가 더 많은 경우 실수 1번에 해당, 
    if (abs(count_o - count_x) >= 2 || count_x > count_o) return 0;
    // o가 이겼을 땐 x의 개수가 o의 개수 이상 있을 수 없음
    if (is_win(board, 'O') && count_o <= count_x) return 0;
    // x가 이겼을 땐 o의 개수가 x의 개수를 초과하여 있을 수 없음
    if (is_win(board, 'X') && count_x < count_o) return 0;
    return 1;
}