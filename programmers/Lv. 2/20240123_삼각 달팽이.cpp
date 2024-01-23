#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[1001][1001], num = 1, height, dir = 1, cnt = 1;
pair<int, int> pos;

vector<int> solution(int n) {
    vector<int> answer;
    height = n - 1;
    for(int i = 0; i < n - 1; i++){
        arr[i][0] = num++;
        pos.first += 1;
    }
    while(num <= (n * (n + 1)/2)){
        arr[pos.first][pos.second] = num++;
        if(dir == 0) pos.first += 1;
        if(dir == 1) pos.second += 1;
        if(dir == 2) {
            pos.first -= 1;
            pos.second -= 1;
        }
        if(cnt == height){
            dir = (dir + 1) % 3;
            cnt = 0;
            height--;
        }
        cnt++;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
           answer.push_back(arr[i][j]);
        }
    }
    return answer;
}