#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;

bool cmp(vector<int>& a, vector<int>& b){
    if(a[n] == b[n]) return a[0] > b[0];
    else return a[n] < b[n];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    vector<int> s;
    n = col - 1;
    sort(data.begin(), data.end(), cmp);
    for(int i = row_begin - 1; i < row_end; i++){
        int s_i = 0;
        for(int j = 0; j < data[0].size(); j++){
            s_i = s_i + data[i][j] % (i + 1);
        }
        s.push_back(s_i);
    }
    for(int i = 0; i < s.size(); i++) answer ^= s[i];    
    return answer;
}