#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    vector<string> splitted;
    string answer, tmp;
    int idx = 0;
    
    s.push_back(' ');
    while(idx < s.size()){
        if(s[idx] == ' '){
            while(idx < s.size() && s[idx] == ' '){
                tmp += s[idx];
                idx++;
            }
            splitted.push_back(tmp);
            tmp.clear();
            continue;
        }
        tmp += s[idx];
        idx++;
    }
    
    for(int i = 0; i < splitted.size(); i++){
        if(splitted[i][0] >= 'a' && splitted[i][0] <= 'z'){
            splitted[i][0] += ('A' - 'a');
        }
        for(int j = 1; j < splitted[i].size(); j++){
            if(splitted[i][j] >= 'A' && splitted[i][j] <= 'Z'){
                splitted[i][j] -= ('A' - 'a');
            }
        }
    }
    
    for(auto a : splitted){
        answer += a;
    }
    answer.pop_back();
    return answer;
}