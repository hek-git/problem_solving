#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> radix[10];


// 두 수를 붙였을 때 더 큰 수인 경우를 반환
bool cmp(string& n1, string& n2){
    return n1 + n2 < n2 + n1;
}

string solution(vector<int> numbers) {
    string answer = "";
    for(int i = 0; i < numbers.size(); i++){
        string s = to_string(numbers[i]);
        radix[s[0] - '0'].push_back(s);
    }
    for(int i = 1; i < 10; i++){
        if(!radix[i].empty()){
            sort(radix[i].begin(), radix[i].end(), cmp);
        }
    }

    for(int i = 9; i >= 0; i--){
        for(int j = radix[i].size()-1; j >= 0; j--){
            if(answer.compare("0")) answer += radix[i][j];
        }
    }

    return answer;
}
