#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer, sequence;
    while (k != 1) {
        sequence.push_back(k);
        if (k % 2 == 0)
            k /= 2;
        else
            k = k * 3 + 1;
    }
    sequence.push_back(1);
    vector<double> integral(sequence.size());
    integral[0] = 0;
    for(int i = 1; i <= sequence.size() - 1; i++){
        integral[i] = integral[i - 1] + min(sequence[i], sequence[i - 1]) + abs(sequence[i] - sequence[i - 1]) / 2;
    }

    for(int i = 0; i < ranges.size(); i++){
        int x1 = ranges[i][0], x2 = (sequence.size() - 1) + ranges[i][1];
        if(x1 > x2 || x1 > sequence.size() - 1 || x2 > sequence.size() - 1) answer.push_back(-1);
        else answer.push_back(integral[x2] - integral[x1]);
    }
    return answer;
}