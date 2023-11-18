#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer = 1251, require, mineralMap[3][3];
vector<int> pickList, mineralsNum;

int check(){
    int point = 0, i = 0, count = 5;
    int loop = min(mineralsNum.size(), pickList.size() * 5);
    for(int j = 0; j < loop; j++){
        point += mineralMap[pickList[i]][mineralsNum[j]];
        count--;
        if(count == 0){
            i++;
            count = 5;
        }
    }
    return point;
}

void backtracking(vector<int>& picks){
    if(pickList.size() == require){
        //cout << check() << endl;
        answer = min(answer, check());
        // for(int i = 0 ; i < require; i++){
        //     cout << pickList[i] << " ";
        // }
        // cout << endl;
        return;
    }

    for(int i = 0; i < 3; i++){
        if(picks[i]){
            pickList.push_back(i);
            picks[i]--;
            backtracking(picks);
            picks[i]++;
            pickList.pop_back();
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int a, b;
    a = picks[0] + picks[1] + picks[2];
    b = minerals.size() / 5;
    if(minerals.size()%5 != 0) b++;
    require = min(a, b);

    mineralMap[0][0] = mineralMap[0][1] = mineralMap[0][2] = 1;

    mineralMap[1][0] = 5;
    mineralMap[1][1] = mineralMap[1][2] = 1;

    mineralMap[2][0] = 25;
    mineralMap[2][1] = 5;
    mineralMap[2][2] = 1;
    
    for(int i = 0; i < minerals.size(); i++){
        if(!minerals[i].compare("diamond")) mineralsNum.push_back(0);
        else if(!minerals[i].compare("iron")) mineralsNum.push_back(1);
        else if(!minerals[i].compare("stone")) mineralsNum.push_back(2);
    }
    // for(int i = 0; i < minerals.size(); i++) cout << mineralsNum[i] << " ";
    // cout << endl;
    backtracking(picks);
    return answer;
}