#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int skills[26];

bool validate(string& skill, string& skill_tree){
    string filtered;
    int order = 0;
    // 스킬에 해당하는 알파벳만 남김
    for(int i = 0; i < skill_tree.size(); i++){
        if(skills[skill_tree[i] - 'A']) filtered.push_back(skill_tree[i]); 
    }
    // 스킬 순서를 따르는지 확인
    for(int i = 0; i < filtered.size(); i++){
        if(skill[order++] != filtered[i]) return false;
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0, flag;
    // 스킬에 해당하는 배열 초기화
    for(int i = 0; i < skill.size(); i++) skills[skill[i] - 'A'] = 1;
    for(int i = 0 ; i < skill_trees.size(); i++){
        if(validate(skill, skill_trees[i])) answer++;
    }
    return answer;
}