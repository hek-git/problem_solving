#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ���� �Ǵ� �İ��� �¸��ߴ��� Ȯ���ϴ� �Լ�
bool is_win(vector<string>& board, char c) {
    // ������ �Ǵ� �����ٿ� c�� ���ӵǾ� �ִ��� Ȯ��
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == c && board[0][i] == board[1][i] &&
            board[0][i] == board[2][i] && board[1][i] == board[2][i])
            return true;
        if (board[i][0] == c && board[i][0] == board[i][1] &&
            board[i][0] == board[i][2] && board[i][1] == board[i][2])
            return true;
    }
    // �밢�� �������� c�� ���ӵǾ� �ִ��� Ȯ��
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
    // o�� x�� ������ 2�� �̻� ���̳��ų� x�� �� ���� ��� �Ǽ� 1���� �ش�, 
    if (abs(count_o - count_x) >= 2 || count_x > count_o) return 0;
    // o�� �̰��� �� x�� ������ o�� ���� �̻� ���� �� ����
    if (is_win(board, 'O') && count_o <= count_x) return 0;
    // x�� �̰��� �� o�� ������ x�� ������ �ʰ��Ͽ� ���� �� ����
    if (is_win(board, 'X') && count_x < count_o) return 0;
    return 1;
}