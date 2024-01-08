#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    pair<long long, long long> pos;
    int number;

    while(left <= right){
        pos.first = left / (long long)n;
        pos.second = left % (long long)n;
        if(pos.first >= pos.second) number = pos.first + 1;
        else number = pos.second + 1;

        left++;
        answer.push_back(number);
    }
    
    return answer;
}