#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> used_words;
    char prev_letter = words[0][words[0].size()-1];
    int turn = 1, people = 1;

    used_words.insert(words[0]);
    answer.push_back(0);
    answer.push_back(0);

    for(int i = 1; i < words.size(); i++){
        // 현재 단어의 차례와 사람 계산
        turn = i / n + 1;
        people = i % n + 1;
        // 단어장에 이미 있거나 마지막 글자와 시작 글자가 다르면 탈락 처리
        if(used_words.find(words[i]) != used_words.end() || prev_letter != words[i][0]){
            answer[0] = people;
            answer[1] = turn;
            break;
        }
        // 사용된 단어 추가, 마지막 알파벳 갱신
        used_words.insert(words[i]);
        prev_letter = words[i][words[i].size()-1];
    }    
    return answer;
}