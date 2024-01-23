#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

char number[3] = {'4', '1', '2'};
    
string recursive(int n){
    if(!n) return "";
    else{
        return number[n % 3] + recursive((n - 1) / 3); 
    }
}

string solution(int n) {
    string answer = recursive(n);
    // cout << answer;
    reverse(answer.begin(), answer.end());
    return answer;
}