#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> want_map;
map<string, int> sale_map;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0, flag;

    // want 목록 매핑
    for(int i = 0; i < want.size(); i++) want_map[want[i]] = number[i]; 

    // 할인목록의 마지막 - 10일까지 전부 순회하며 할인 목록 map을 각각 만듦
    for(int i = 0; i < discount.size() - 9; i++){
        sale_map.clear();
        flag = 1;
        for(int j = i; j < i + 10; j++){
            if(sale_map.find(discount[j]) != sale_map.end()) sale_map[discount[j]]++;
            else sale_map[discount[j]] = 1;
        }

        for(auto w : want_map){
            if(sale_map.find(w.first) == sale_map.end() || sale_map[w.first] != w.second){
                flag = 0;
                break;
            }
        }   
        if(flag) answer++;
    }
    return answer;
}