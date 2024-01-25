#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int rotate(vector<vector<int>>& matrix, pair<int, int> p1, pair<int, int> p2){
    int size = 0;
    vector<int> len(4), num;
    pair<int, int> start = p1;
    len[0] = len[2] = p2.second - p1.second;
    len[1] = len[3] = p2.first - p1.first;
    
    // 돌릴 값을 순서대로 일차원 배열(num)에 저장
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < len[i]; j++){
            num.push_back(matrix[start.first][start.second]);
            start.first += dir[i].first;
            start.second += dir[i].second;
        }
    }

    // 회전된 순서대로 접근하며 원래 순서의 원소를 대입
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < len[i]; j++){
            start.first += dir[i].first;
            start.second += dir[i].second;
            matrix[start.first][start.second] = num[size++];
        }
    }
    // 최소값 반환
    return *min_element(num.begin(), num.end());
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix(rows + 1, vector<int>(columns + 1));

    // 행렬 채우기
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            matrix[i][j] = (i - 1) * columns + j;
        }
    }

    // 행렬 회전 후 최소 값 추가
    for(int i = 0; i < queries.size(); i++){
        answer.push_back(rotate(matrix, make_pair(queries[i][0], queries[i][1]), make_pair(queries[i][2], queries[i][3])));
    }

    return answer;
}