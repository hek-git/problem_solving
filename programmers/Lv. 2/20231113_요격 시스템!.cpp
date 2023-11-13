#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end());
    int start = targets[0][0];
    int finish = targets[0][1];
    int i = 1;
    while(i < targets.size()){
        if(targets[i][0] < finish){
            start = targets[i][0];
            finish = min(finish, targets[i][1]);
        } else{
            start = targets[i][0];
            finish = targets[i][1];
            answer++;
        }
        i++;
    }
    return answer;
}