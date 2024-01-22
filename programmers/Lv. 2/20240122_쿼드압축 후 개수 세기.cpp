#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer(2, 0);

void solution(vector<vector<int>>& arr, pair<int, int> pos, int size) {
    if (size <= 0) return;
    int standard = arr[pos.first][pos.second];
    for (int i = pos.first; i < pos.first + size; i++) {
        for (int j = pos.second; j < pos.second + size; j++) {
            if (arr[i][j] != standard) {
                int div = size / 2;
                solution(arr, make_pair(pos.first, pos.second), div);
                solution(arr, make_pair(pos.first + div, pos.second), div);
                solution(arr, make_pair(pos.first, pos.second + div), div);
                solution(arr, make_pair(pos.first + div, pos.second + div), div);
                return;
            }
        }
    }
    answer[standard]++;
}

vector<int> solution(vector<vector<int>> arr) {
    solution(arr, make_pair(0, 0), arr.size());
    return answer;
}