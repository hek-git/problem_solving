#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int answer, check[9], flag;
vector<string> list, order;
set<int> list2;
set<set<int>> s;

bool compare(string& a, string& b){
    if(a.size() != b.size()) return false;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '*') continue;
        else if(a[i] != b[i]) return false;
    }
    return true;
}

bool validate(vector<string>& banned_id){
    for(int i = 0; i < banned_id.size(); i++){
        if(!compare(banned_id[i], order[i])) return false;
    }
    return true;
}

void change_order(int n, vector<string>& banned_id){
    if(order.size() == n){
        if(validate(banned_id)) flag = 1;
        return;
    }

    for(int i = 0; i < list.size(); i++){
        if(flag) return;
        if(!check[i]){
            check[i] = 1;
            order.push_back(list[i]);
            change_order(n, banned_id);
            order.pop_back();
            check[i] = 0;
        }
    }
}

void backtrack1(vector<string>& user_id, vector<string>& banned_id, int s){
    if(list.size() == banned_id.size()){
        flag = 0;
        change_order(banned_id.size(), banned_id);
        if(flag) answer++;
        return;
    }
    
    for(int i = s; i < user_id.size(); i++){
        list.push_back(user_id[i]);
        backtrack1(user_id, banned_id, i + 1);
        list.pop_back();
    }
}

void backtrack2(vector<vector<int>>& candidate, int idx){
    if(list2.size() == candidate.size()){
        s.insert(list2);
        return;
    }
    for(int i = 0; i < candidate[idx].size(); i++){
        if(!check[candidate[idx][i]]){
            check[candidate[idx][i]] = 1;
            list2.insert(candidate[idx][i]);
            backtrack2(candidate, idx + 1);
            list2.erase(candidate[idx][i]);
            check[candidate[idx][i]] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    // backtrack1(user_id, banned_id, 0); // 방법 1: 모든 user_id 경우를 나열하고 각각의 banned_id에 맞는지 확인하는 방법
    
    // 방법 2 : 모든 baenned_id에 대해 가능한 후보를 모아두고 모든 경우의 수를 나열 및 set을 이용한 중복확인
    vector<vector<int>> candidate;
    for(int i = 0; i < banned_id.size(); i++){
        vector<int> tmp;
        for(int j = 0; j < user_id.size(); j++){
            if(compare(banned_id[i], user_id[j])) tmp.push_back(j);
        }
        candidate.push_back(tmp);
    }
    backtrack2(candidate, 0);
    return s.size();
}