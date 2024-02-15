#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int list[100001];

bool cmp(vector<int>& a, vector<int>& b){ return a.size() < b.size(); }

vector<int> split(string s, char delim){
    vector<int> ret;
    s.push_back(delim);
    string tmp_s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == delim){
            int n = stoi(tmp_s);
            ret.push_back(n);
            tmp_s.clear();
        } else tmp_s.push_back(s[i]); 
    }
    return ret;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> tuple;
    string tmp_s;
    int flag = 0;

    for(int i = 1; i < s.size()-1; i++){
        if(s[i] == '{'){
            flag = 1;
        } else if(s[i] == '}'){
            tuple.push_back(split(tmp_s, ','));
            tmp_s.clear();
            flag = 0;
        } else if(flag){
            tmp_s.push_back(s[i]);
        }
    }
    sort(tuple.begin(), tuple.end(), cmp);

    for(int i = 0; i < tuple.size(); i++){
        for(int j = 0; j < tuple[i].size(); j++){
            if(!list[tuple[i][j]]){
                list[tuple[i][j]] = 1;
                answer.push_back(tuple[i][j]);
            }
        }
    }
    
    return answer;
}