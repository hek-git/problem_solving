#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, n, answer;
vector<vector<int>> v;

void print(vector<vector<int>> board){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int findMax(vector<vector<int>>& board){
    int m = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            m = max(board[i][j], m);
        }
    }
    return m;
}

vector<vector<int>> moveUp(vector<vector<int>> board) {
    int top;
    for (int i = 0; i < board.size(); i++) {
        top = 0;
        for(int j = 1; j < board.size(); j++){
            if(!board[j][i]) continue;

            int tmp_j = j - 1;
            while (board[tmp_j][i] == 0 && tmp_j > top) tmp_j--;

            if(board[j][i] == board[tmp_j][i]){
                board[tmp_j][i] *= 2;
                board[j][i] = 0;
                top = tmp_j + 1;
            } else{
                int tmp = board[j][i];
                board[j][i] = 0;
                if(board[tmp_j][i] == 0) board[tmp_j][i] = tmp;
                else board[tmp_j + 1][i] = tmp;                
            }
        }
    }
    // print(board); 
    return board;
}

vector<vector<int>> moveDown(vector<vector<int>> board){
    int down;
    for (int i = 0; i < board.size(); i++) {
        down = board.size() - 1;
        for(int j = board.size() - 2; j >= 0; j--){
            if(!board[j][i]) continue;

            int tmp_j = j + 1;
            while (board[tmp_j][i] == 0 && tmp_j < down) tmp_j++;

            if(board[j][i] == board[tmp_j][i]){
                board[tmp_j][i] *= 2;
                board[j][i] = 0;
                down = tmp_j - 1;
            } else{
                int tmp = board[j][i];
                board[j][i] = 0;
                if(board[tmp_j][i] == 0) board[tmp_j][i] = tmp;
                else board[tmp_j - 1][i] = tmp;                
            }
        }
    }
    // print(board);
    return board;
}

vector<vector<int>> moveRight(vector<vector<int>> board){
    int right;
    for (int i = 0; i < board.size(); i++) {
        right = board.size() - 1;
        for(int j = board.size() - 2; j >= 0; j--){
            if(!board[i][j]) continue;

            int tmp_j = j + 1;
            while (board[i][tmp_j] == 0 && tmp_j < right) tmp_j++;

            if(board[i][j] == board[i][tmp_j]){
                board[i][tmp_j] *= 2;
                board[i][j] = 0;
                right = tmp_j - 1;
            } else{
                int tmp = board[i][j];
                board[i][j] = 0;
                if(board[i][tmp_j] == 0) board[i][tmp_j] = tmp;
                else board[i][tmp_j - 1] = tmp;                
            }         
        }
    }
    // print(board);
    return board;
}

vector<vector<int>> moveLeft(vector<vector<int>> board){
    int left;
    for (int i = 0; i < board.size(); i++) {
        left = 0;
        for(int j = 1; j < board.size(); j++){
            if(!board[i][j]) continue;

            int tmp_j = j - 1;
            while (board[i][tmp_j] == 0 && tmp_j > left) tmp_j--;

            if(board[i][j] == board[i][tmp_j]){
                board[i][tmp_j] *= 2;
                board[i][j] = 0;
                left = tmp_j + 1;
            } else{
                int tmp = board[i][j];
                board[i][j] = 0;
                if(board[i][tmp_j] == 0) board[i][tmp_j] = tmp;
                else board[i][tmp_j + 1] = tmp;                
            }          
        }
    }
    // print(board);
    return board;
}

void solve(vector<vector<int>> board, int cnt){
    answer = max(answer, findMax(board));
    if(cnt == 5) return;
    solve(moveUp(board), cnt + 1);
    solve(moveDown(board), cnt + 1);
    solve(moveRight(board), cnt + 1);
    solve(moveLeft(board), cnt + 1);
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        vector<int> tmp;
        for(int j = 0; j < N; j++){
            cin >> n;
            tmp.push_back(n);
        }
        v.push_back(tmp);
    }
    solve(v, 0);
    cout << answer;
}