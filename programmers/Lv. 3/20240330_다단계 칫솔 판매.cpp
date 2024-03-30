#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> employee;
int union_find[10001];

void profit_share(vector<int>& answer, int emp, int amount){
    answer[emp] += amount - amount / 10;
    if( !(amount / 10) || union_find[emp] == emp) return;
    profit_share(answer, union_find[emp], amount / 10);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    for(int i = 0; i < enroll.size(); i++) employee[enroll[i]] = i;
    for(int i = 0; i < referral.size(); i++){
        if(!referral[i].compare("-")) union_find[employee[enroll[i]]] = i;
        else union_find[employee[enroll[i]]] = employee[referral[i]]; 
    }

    for(int i = 0; i < seller.size(); i++){
        profit_share(answer, employee[seller[i]], amount[i] * 100);
    }

    // for(auto a : employee){
    //     cout << a.first << " " << a.second << endl;
    // }
    // for(int i = 0; i < enroll.size(); i++){
    //     cout << union_find[i] << " ";
    // }

    return answer;
}