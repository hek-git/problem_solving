#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    int start = 0, finish = msg.size(), num = 27;
    for(int i = 1; i < num; i++){
        string s;
        s.push_back('A' + i - 1);
        m[s] = i;
    }
    
    while(start < finish){
        int len = 1;
        string tmp;
        tmp += msg[start];
        // 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾음
        while(m.find(tmp) != m.end()){
            start++;
            tmp += msg[start];
        }
        // tmp는 입력에서 처리되지 않은 다음 글자까지 포함이므로 마지막 알파벳 바로 전 단어를 사전에서 찾고, tmp는 사전에 새로 등록
        answer.push_back(m[tmp.substr(0, tmp.size() - 1)]);
        m[tmp] = num++;
        tmp.clear();
    }
    return answer;
}