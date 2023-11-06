#include <string>
#include <vector>
#include <iostream>

using namespace std;


int ansFirst, ansSecond, saleRate[4] = {10, 20, 30, 40};
vector<int> global_emo, sale;
vector<vector<int>> usr;

void calculate(){
    int first = 0, second = 0;
    for(int i = 0; i < usr.size(); i++){
        int price = 0;
        for(int j = 0; j < global_emo.size(); j++){
            if(sale[j] >= usr[i][0]) price = price + (global_emo[j] - (global_emo[j] * sale[j] / 100));
            if(price >= usr[i][1]){
                price = 0;
                first++;
                break;
            }
        }
        second += price;
    }
    if(first > ansFirst){
        ansFirst = first;
        ansSecond = second;
    }
    else if(first == ansFirst && second > ansSecond){
        ansSecond = second;
    }
}

void backTracking(){
    if(sale.size() == global_emo.size()){
        calculate();
        return;
    }

    for(int i = 0; i < 4; i++){
        sale.push_back(saleRate[i]);
        backTracking();
        sale.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    global_emo = emoticons;
    usr = users;
    backTracking();
    answer.push_back(ansFirst);
    answer.push_back(ansSecond);
    return answer;
}